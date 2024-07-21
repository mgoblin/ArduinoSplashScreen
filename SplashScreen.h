#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
/*
    SplashScreen.h - Library for sequential changing screens usually on program starts.
    Created by Michael Golovanov, July 12 2024.
    Released on public domain.   
*/

/**
 * @file SplashScreen.h
 */

/**
 * @brief Splash screen namespace
 */
namespace mg {

    /**
     * @brief Declares single screen
     *  
     * @details %Screen described by its %data and display delay. 
     * 
     * @tparam T type of screen data
     */
    template <typename T> 
    struct Screen {  
        /** 
         * @brief %Screen data
         */
        T *page; 

        /**
         * @brief %Screen display time in milliseconds
         * 
         */
        size_t displayIntervalMs;
    };

    /**
     * @brief Describes single page of LCD1602
     * 
     * @details LCD1602 is a popular display device. 
     *          In text mode it can display 2 x 16 char lines.
     */
    class LCD1602Page: public Printable
    {
        public:
            /// @brief first string
            String line1;
            /// @brief second line
            String line2;

            /**
             * Constructor
             * 
             * @param l1 first line
             * @param l2 second line
             */
            LCD1602Page(String l1, String l2): line1 {l1}, line2 {l2}
            {

            }

            /**
             * Print LCD1602Page
             */
            size_t printTo(Print& p) const
            {
                size_t res = p.print("LCD1602Page: line1 = <");
                res += p.print(line1);
                res += p.print(">, line2 = <");
                res += p.print(line2);
                res += p.print(">");
                return res;
            }
    };

    /** 
     * @brief %Splash screen state
     */
    enum class State
    {
        /// @brief ready to start display screens
        READY = 'R',
        /// @brief displaying one of screens
        DISPLAYING = 'D',
        /// @brief all screens was displayed
        FINISHED = 'F'
    };

    /**
     * @brief Describes displaying screen 
     */
    template <typename T>
    class DisplayingScreen: public Printable
    {
        public:
            /// Reference to the last rendered screen.
            const Screen<T> *renderedScreen;
            
            /// Last rendered screen index  
            uint16_t screenIndex;

            /// Start millis for rendered screen 
            uint64_t startDisplayMillis;

            /// Last rendered screen remaining display time 
            uint64_t remainingDisplayMillis;

            /** 
             * Constructor
            */
            DisplayingScreen(const Screen<T> *rs, uint16_t sIdx, uint64_t st, uint64_t rem):
                renderedScreen{rs}, screenIndex{sIdx}, startDisplayMillis{st}, remainingDisplayMillis{rem} 
            {
            }

            virtual ~DisplayingScreen() {}

            /** 
             * Printable implementation. 
             */
            virtual size_t printTo(Print& p) const
            {
                size_t res = p.print("DisplayingScreen: screenIndex = ");
                res += p.print(screenIndex);
                res += p.print(", startDisplayMillis = ");
                res += p.print((long)startDisplayMillis, DEC);
                res += p.print(", remainingDisplayMillis = ");
                res += p.print((long)remainingDisplayMillis, DEC);
                return res;
            }

    };

    /**
     * @brief Describes display screens process status.
     * 
     * @tparam T type of splash screen page.
     */
    template <typename T>
    class DisplaySplashScreenStatus: public Printable
    {
        public: 
            /// Splash screen state
            State state;
        
            /// Pointer to displaying screen. nullptr if splash screen doesnt display screen.
            DisplayingScreen<T> *displayingScreen;

            /**
             * Constructor
             */
            DisplaySplashScreenStatus(mg::State st, mg::DisplayingScreen<T> *ds)
            {
                state = st;
                displayingScreen = ds;
            } 
            
            /**
             * Printable implementation
             */
            size_t printTo(Print& p) const
            {
                size_t res = p.print("DisplaySplashScreenStatus: state = ");
                switch (state)
                {
                    case mg::State::READY:
                        res += p.print("READY"); 
                        break;
                    case mg::State::DISPLAYING:
                        res += p.print("DISPLAYING");
                        break;    
                    case mg::State::FINISHED:
                        res += p.print("FINISHED");
                        break;    
                };

                if (displayingScreen != nullptr)
                {
                    res += p.print(", ");
                    res += displayingScreen->printTo(p);
                } else {
                    res += p.print(", Displaying screen is null");
                }
                return res;
            }
    };
    
    /**
     * @brief describes render page function 
     * 
     * @details render page function called by %splash screen to render page on screen device
     * 
     * @tparam T page type
     */
    template <typename T>
    using RenderPageHandler = void (*)(T *page);
    
    /**
     * @brief describes clear screen function
     * 
     * @details clear screen function called by %splash screen to clear screen device
     */
    using ClearHandler = void (*)();

    /** 
     * @brief %Sequence of rotating screens 
     * 
     * @tparam T type of splash screen page
     * 
     * @details 
     * Initialized in READY state and wait to display() call for start screen rotation. 
     * Method tick() should be call periodically (usually inside loop()) to 
     * nonbloking screen rotation after screen display interval.
     */
    template <typename T>
    class SplashScreen
    {
        private:
            const Screen<T>* _screens;
            uint16_t _screensCount;
            ClearHandler _clearHandler;
            RenderPageHandler<T> _renderPageHanler;

            State _state;

            DisplayingScreen<T> *_displayingScreen;

            /**
             * Calculate time remaining for next screen displaying.
             * Should be called only inside displayingTick()
             */
            uint64_t calculateRemainingDisplayMillis()
            {
                auto delta =  millis() - _displayingScreen->startDisplayMillis;
                return delta > _displayingScreen->renderedScreen->displayIntervalMs ? 
                    0 : _displayingScreen->renderedScreen->displayIntervalMs - delta;
            }

            /**
             * Verify that all screens are displayed
             * true if all screens are displayed otherwise false
             */
            bool allScreensDisplayed()
            {
                return _displayingScreen->screenIndex == _screensCount - 1 && needToNextScreen();
            }

            /**
             * Verifry that next screen should be displayed
             */
            bool needToNextScreen()
            {
                return _displayingScreen->remainingDisplayMillis == 0;
            }

            /**
             * Free _displayingScreen object memory and set pointer to nullptr 
             */
            void freeDisplayingScreenPtr()
            {
                if (_displayingScreen != nullptr)
                {
                    delete _displayingScreen;
                    _displayingScreen = nullptr; 
                }
            }

        public:

            /**
             * @brief Initialize %splash screen
             * 
             * @param screens - screen array
             * @param screensCount - size of screen array
             * @param clearHandler - reference to clear device screen function.
             * @param renderPageHandler = reference to render page on device screen function
             */
            SplashScreen(
                const Screen<T> *screens, 
                byte screensCount,
                ClearHandler clearHandler, 
                RenderPageHandler<T> renderPageHandler)
            {
                _screens = screens;
                _screensCount = screensCount;
                _clearHandler = clearHandler;
                _renderPageHanler = renderPageHandler;
                _state = State::READY;
                _displayingScreen = nullptr; 
            }

            /**
             * @brief Destruct %splash screen
             */
            virtual ~SplashScreen()
            {
                _screens = nullptr;
                _clearHandler = nullptr;
                _renderPageHanler = nullptr;
                _state = State::READY;
                freeDisplayingScreenPtr();
            }

            /**
             * @brief Get splash screen state
             * 
             * @return Splash screen state
             */
            State getState()
            {
                return _state;
            }

            /**
             * @brief Get splash screen clear handler
             * 
             * @return Splash screen clear handler or nullptr if the handler not assigned.
             */
            ClearHandler getClearHandler()
            {
                return _clearHandler;
            }

            /**
             * @brief Get splash screen render screen handler
             * 
             * @return Splash screen render screen handler or nullptr if the handler not assigned.
             */
            RenderPageHandler<T> getRenderPageHandler()
            {
                return _renderPageHanler;
            }

            /**
             * @brief Get screens count
             * 
             * @return Screens count
             */
            uint16_t getScreensCount()
            {
                return _screensCount;
            }

            /**
             * @brief Get screen by index
             * 
             * @details Get screen by index or nullptr if index not in ragne of screens
             * 
             * @param index screen index in range of screensArray indexes
             * 
             * @return screen by index
             */
            const Screen<T>* getScreen(uint16_t index) 
            {
                return _screensCount > 0 && index < _screensCount ? &(_screens[index]) : nullptr;
            }

            /** 
             * @brief Render page by index
             * 
             * @details Before render page call clear() and then delegate page rendering
             *          to render page hanlder. Render does not change internal state of 
             *          splash screen.
             * 
             * @param pageIndex Page index. Page index should be in range of screensArray indexes.
             */
            void renderPage(uint16_t pageIndex)
            {
                const Screen<T> *screen = getScreen(pageIndex);
                if (_renderPageHanler != nullptr && screen != nullptr)
                {
                    clear();
                     _renderPageHanler(screen->page);
                }
            }

            /**
             * @brief Clear display.
             * 
             * @details Call clear handler if it assigned for page clearing.
             */
            void clear()
            {
                if (_clearHandler != nullptr)
                {
                    _clearHandler();
                }
            }

            /**
             * @brief Starts display screen by index.
             * 
             * @details Changes splash screen status to mg::Status::DISPLAYING and 
             *          store displaying screen pointer and current millis() value.  
             *          For screen changing after time intervals method tick() should 
             *          be periodically called.
             *          displayScreen(0) call is equivalent to display().
             * 
             * @param screenIndex %Screen index. Should be in range of screensArray indexes.
             * 
             * @return Displayed screen pointer or nullptr if screen not found.
             */
            const Screen<T>* displayScreen(uint16_t screenIndex) {
                
                const Screen<T> *screen = getScreen(screenIndex);
                if (screen != nullptr) 
                {
                    _state = State::DISPLAYING;
                    freeDisplayingScreenPtr();
                    _displayingScreen = new DisplayingScreen<T>(
                        screen,
                        screenIndex,
                        millis(),
                        screen->displayIntervalMs
                    );
                    
                    renderPage(screenIndex);
                }
                
                return screen;
            }

            /**
             * @brief Starts splash screen from frist screen.
             * 
             * @details Changes splash screen status to mg::Status::DISPLAYING and 
             *          store displaying screen pointer for first screen, its index = 0 and current millis() value.  
             *          For screen changing after time intervals method tick() should 
             *          be periodically called.
             *          display() call is equivalent to display(0).
             * 
             * @return first screen pointer or null if screen not found. 
             */
            const Screen<T>* display()
            {
                return displayScreen(0);
            }

            /** 
             * @brief Make splash screen ready to start.
             * 
             * @details Set %splash screen state State::READY and call clear display handler. 
             */
            void makeReady()
            {
                _state = State::READY;
                freeDisplayingScreenPtr();
                clear();
            }

            /**
             * @brief Excplicitly stops splash screen.
             * 
             * @details Set %Splash screen state to State::FINISHED and call clear set handler
             * 
             * @return %Splash screen status before move to mg::State::FINISHED
             */
            DisplaySplashScreenStatus<T> finish()
            {
                DisplaySplashScreenStatus<T> status(State::FINISHED, nullptr);
                _state = State::FINISHED;
                freeDisplayingScreenPtr();
                status.state = _state;
                status.displayingScreen = _displayingScreen;
                clear();
                return status;    
            }

            /**
             * @brief Display screens one after another in mg::State::DISPLAYING state.
             * 
             * @details tick() should be called periodically to display next screen. 
             *          Usually tick() should be called inside loop() 
             * 
             * @return current display screens status 
             */
            DisplaySplashScreenStatus<T> tick()
            {
                switch (_state)
                {
                case mg::State::DISPLAYING:
                    _displayingScreen->remainingDisplayMillis = calculateRemainingDisplayMillis();
                
                    if (allScreensDisplayed())
                    {
                        finish(); 
                    } 
                    else if (needToNextScreen())
                    {
                        uint16_t idx = _displayingScreen->screenIndex + 1;
                        displayScreen(idx);
                    }
                    break;
                
                default:
                    freeDisplayingScreenPtr();
                    break;
                }
                
                DisplaySplashScreenStatus<T> status(
                    getState(),
                    _displayingScreen
                );
                return status;
            }
    };
}
#endif