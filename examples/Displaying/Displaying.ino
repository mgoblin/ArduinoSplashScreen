#include <SplashScreen.h>

using namespace mg;

#define SPLASH_SCREENS_COUNT 3
const String page1 = "Hello";
const String page2 = "Splash";
const String page3 = "Screen"; 

const Screen<const String> screen1 
{
        .page = &page1, 
        .displayIntervalMs = 1000
};
const Screen<const String> screen2 
{
        .page = &page2, 
        .displayIntervalMs = 1000
};
const Screen<const String> screen3 
{
        .page = &page3, 
        .displayIntervalMs = 1000
};
const mg::Screen<const String> screensArray[SPLASH_SCREENS_COUNT] = { screen1, screen2, screen3 };


void clearScreen() 
{
    
}

void displayScreen(const String* page)
{
    Serial.println(*page);
}

SplashScreen<const String> splashScreen(screensArray, SPLASH_SCREENS_COUNT, clearScreen, displayScreen);

uint16_t last_idx = 255;
bool finishedPrinted = false;

void setup()
{
    Serial.begin(9600);

    DisplaySplashScreenStatus<const String> status = splashScreen.tick();
    Serial.println(status);

    splashScreen.display();   
}

void loop()
{
    DisplaySplashScreenStatus<const String> status = splashScreen.tick();
    if (status.state != mg::State::FINISHED)
    {
        uint16_t idx = status.displayingScreen->screenIndex;
        if (last_idx != idx)
        {
            Serial.println(status);
            last_idx = idx;
        }
    } else 
    {
        if (!finishedPrinted)
        {
            Serial.println(status);
            finishedPrinted = true;
        }
    }
}
