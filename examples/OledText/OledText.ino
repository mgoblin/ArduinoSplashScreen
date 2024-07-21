#include <Arduino.h>
#include <SplashScreen.h>
#include <SSD1306AsciiWire.h>

// 0X3C+SA0 - 0x3C or 0x3D
#define OLED_I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;

typedef const char Page[2][16];
void clearScreen();
void displayScreen(Page* page);


#define SPLASH_SCREENS_COUNT 2

const PROGMEM char page1[2][16] { "LCD1111", "Test" };
const mg::Screen<const char[2][16]> screen1 
{
        .page = &page1, 
        .displayIntervalMs = 3000
};
const PROGMEM char page2[2][16] ={ "Page2_1", "Page2_2" };
const mg::Screen<const char[2][16]> screen2 
{
        .page = &page2, 
        .displayIntervalMs = 5000
};

const mg::Screen<const char[2][16]> screensArray[SPLASH_SCREENS_COUNT] = { screen1, screen2 };
mg::SplashScreen<const char[2][16]> splashScreen(screensArray, SPLASH_SCREENS_COUNT, clearScreen, displayScreen);

void clearScreen()
{
    oled.clear();
}

void displayScreen(Page *page)
{
    auto p = *page;

    char buffer[16 + 1];
    strcpy_P(buffer, p[0]); 
    oled.println(buffer);

    strcpy_P(buffer, p[1]); 
    oled.println(buffer);
}

void setup()
{
    Wire.setClock(400000L);
    oled.begin(&Adafruit128x64, OLED_I2C_ADDRESS); 
    oled.setFont(System5x7);

    splashScreen.display();
}

void loop()
{
    splashScreen.tick();
}