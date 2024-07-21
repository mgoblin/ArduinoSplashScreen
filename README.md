# Splash screen library

## What is splash screen?
Splash screen is sequentialy displayed on program start screens.

Splash screen enhances user experience in the following cases: 
* Program needs long initialization
* Program should display usage tips

## Why you need Strings splash screen library
Splash screen library sequencially change screens in non blocking manner.

Each screen is described as a display interval and data.

The responsibility for implementing screen clearing and rendering is delegated to the code by the user of the library. This approach allows you to separate the logic of changing screens from the logic of drawing screens on different devices.

## Mininal example

### Step 1. Add library to your project
Use library manager.

### Step 2. Describe screens
Example 1. Describe two LCD1602 screens 
```cpp
#include <Arduino.h>
#include <SplashScreen.h>

#define SPLASH_SCREENS_COUNT 2
mg::LCD1602Page page1 = mg::LCD1602Page { "LCD1111", "Test" };
mg::Screen<mg::LCD1602Page> screen1 = mg::Screen<mg::LCD1602Page> 
{
        .page = &page1, 
        .displayIntervalMs = 3000
};
mg::LCD1602Page page2 = mg::LCD1602Page { "Page2_1", "Page2_2" };
mg::Screen<mg::LCD1602Page> screen2 = mg::Screen<mg::LCD1602Page> 
{
        .page = &page2, 
        .displayIntervalMs = 5000
};

mg::Screen<mg::LCD1602Page> screensArray[SPLASH_SCREENS_COUNT] = { screen1, screen2 };
```

### Step 3. Define clear and render screen handlers
```cpp
#include <SSD1306AsciiWire.h>

// 0X3C+SA0 - 0x3C or 0x3D
#define OLED_I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;

void clearScreen()
{
    oled.clear();
}

void displayScreen(mg::LCD1602Page *page)
{
    oled.println(page->line1);
    oled.println(page->line2);
}
```

### Step4. Use SplashScreen for sequentialy rendering screens
```cpp
mg::SplashScreen<mg::LCD1602Page> splashScreen(
    screensArray, SPLASH_SCREENS_COUNT, clearScreen, displayScreen);

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
```
