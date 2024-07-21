#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SplashScreen.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// 'FMRadio', 128x64px
const unsigned char bitmap_FMRadio [] PROGMEM = {

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x0f, 0x98, 0x0c, 0x07, 0xc0, 0x00, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x08, 0x18, 0x0c, 0x04, 0x20, 0x00, 0x12, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x08, 0x14, 0x14, 0x04, 0x20, 0x00, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x08, 0x14, 0x14, 0x04, 0x21, 0xe1, 0xd2, 0x1e, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x0f, 0x92, 0x24, 0x04, 0x22, 0x12, 0x32, 0x21, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x08, 0x12, 0x24, 0x07, 0xc0, 0x12, 0x12, 0x21, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x08, 0x11, 0x44, 0x04, 0x41, 0xf2, 0x12, 0x21, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x08, 0x11, 0x44, 0x04, 0x22, 0x12, 0x12, 0x21, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x08, 0x10, 0x84, 0x04, 0x22, 0x32, 0x32, 0x21, 0x00, 0x00, 
	0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x08, 0x10, 0x84, 0x04, 0x11, 0xd1, 0xd2, 0x1e, 0x00, 0x00, 
	0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x38, 0x07, 0x03, 0xf0, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x3c, 0x0f, 0x0e, 0x18, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x3c, 0x0f, 0x18, 0x00, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x34, 0x0b, 0x18, 0x00, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x36, 0x1b, 0x30, 0x00, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x32, 0x13, 0x30, 0x00, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x33, 0x13, 0x30, 0xf8, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x03, 0xfc, 0x00, 0x33, 0x33, 0x30, 0x18, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc3, 0xfc, 0x00, 0x31, 0x23, 0x30, 0x18, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xe3, 0xfc, 0x00, 0x31, 0xe3, 0x18, 0x18, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x79, 0xe3, 0xfc, 0x00, 0x31, 0xe3, 0x18, 0x18, 0x00, 0x00, 
	0x01, 0xfe, 0x01, 0x83, 0x06, 0x00, 0xf0, 0xf3, 0xfc, 0x00, 0x30, 0xc3, 0x0c, 0x18, 0x00, 0x00, 
	0x01, 0xfe, 0x01, 0x83, 0x06, 0x00, 0xe0, 0x73, 0xfc, 0x00, 0x30, 0xc3, 0x03, 0xf0, 0x00, 0x00, 
	0x01, 0xfe, 0x01, 0x83, 0x06, 0x00, 0xe0, 0x73, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xfe, 0x01, 0x83, 0x06, 0x00, 0xf0, 0x73, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xfe, 0x01, 0x93, 0x26, 0x40, 0x78, 0xe3, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xfe, 0x01, 0x93, 0x26, 0x40, 0x7f, 0xe3, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xfe, 0x01, 0x93, 0x26, 0x40, 0x3f, 0xc3, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x78, 0x78, 0x78, 0x18, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x84, 0x84, 0x84, 0x18, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x04, 0x84, 0x04, 0x28, 0x00, 0x00, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x04, 0x84, 0x04, 0x28, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x08, 0x84, 0x08, 0x48, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x08, 0x84, 0x08, 0x48, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x10, 0x84, 0x10, 0x88, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x20, 0x84, 0x20, 0xfc, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x40, 0x84, 0x40, 0x08, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0xfc, 0x78, 0xfc, 0x08, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

};

const unsigned char bitmap_Controls [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x03, 0xc0, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x1c, 0x73, 0x9d, 0xc4, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x12, 0x49, 0x11, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x12, 0x49, 0x11, 0x24, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x12, 0x49, 0x11, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x03, 0xdc, 0x49, 0x91, 0xc6, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x07, 0xa4, 0x08, 0x00, 0x00, 0x80, 0x70, 0x21, 0x04, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x08, 0x20, 0x08, 0x00, 0x00, 0x80, 0x90, 0xe1, 0x8c, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x08, 0x24, 0xca, 0x00, 0x21, 0x00, 0x90, 0x21, 0x94, 0xe7, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x08, 0x25, 0x0c, 0x00, 0x79, 0x00, 0x88, 0x21, 0x54, 0x90, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x08, 0x25, 0x0c, 0x1c, 0x21, 0x38, 0x90, 0x21, 0x64, 0x91, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x08, 0x25, 0x0a, 0x00, 0x21, 0x00, 0x90, 0x21, 0x24, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x07, 0xb5, 0xca, 0x00, 0x02, 0x00, 0x72, 0x21, 0x04, 0x97, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x07, 0x88, 0x20, 0x24, 0x08, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 
	0x04, 0x48, 0x20, 0x20, 0x08, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 
	0x04, 0x4e, 0x23, 0x24, 0xca, 0x00, 0x71, 0xd2, 0xe4, 0xe3, 0xba, 0x23, 0xb9, 0xe5, 0xc0, 0x00, 
	0x04, 0x29, 0x24, 0x25, 0x0c, 0x00, 0x49, 0x2a, 0x44, 0x92, 0x26, 0x42, 0x09, 0x25, 0x20, 0x00, 
	0x04, 0x49, 0x24, 0x25, 0x0c, 0x1c, 0x49, 0xe4, 0x44, 0x92, 0x3d, 0x42, 0x39, 0x25, 0x20, 0x00, 
	0x04, 0x49, 0x24, 0x25, 0x0a, 0x00, 0x49, 0x0c, 0x44, 0x92, 0x21, 0x82, 0x49, 0x25, 0x20, 0x00, 
	0x07, 0x8e, 0x37, 0x35, 0xca, 0x00, 0x49, 0xf2, 0x68, 0xe2, 0x3c, 0x82, 0x39, 0xe5, 0xc0, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x38, 0xe3, 0xc3, 0x8e, 0xe7, 0x38, 0x01, 0xdc, 0xe7, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x24, 0x92, 0x42, 0x48, 0x98, 0x40, 0x01, 0x24, 0x94, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x24, 0x92, 0x42, 0x48, 0xf6, 0x30, 0x71, 0x24, 0xf4, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0x24, 0x92, 0x42, 0x48, 0x81, 0x08, 0x01, 0x24, 0x84, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x07, 0xb8, 0x93, 0xc3, 0x88, 0xf7, 0x38, 0x01, 0x24, 0xf4, 0x9e, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

using namespace mg;

#define SPLASH_SCREENS_COUNT 2
const Screen<const unsigned char[SCREEN_WIDTH * 8]> screen1
{
	.page = &bitmap_FMRadio,
	.displayIntervalMs = 3000
};

const Screen<const unsigned char[SCREEN_WIDTH * 8]> screen2
{
	.page = &bitmap_Controls,
	.displayIntervalMs = 5000
};

Screen<const unsigned char[SCREEN_WIDTH * 8]> screensArray[SPLASH_SCREENS_COUNT] = { screen1, screen2 };

void clear()
{
	display.clearDisplay();
	display.display();
}

void renderPage(const unsigned char* bitmap[SCREEN_WIDTH * 8])
{
  // Display bitmap
  display.drawBitmap(0, 0, *bitmap, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  display.display();
}

SplashScreen<const unsigned char[SCREEN_WIDTH * 8]> splashScreen(screensArray, SPLASH_SCREENS_COUNT, clear, renderPage);


void setup()
{
  Serial.begin(9600);
  
  // initialize the OLED object
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  splashScreen.display();
}

void loop() 
{
	splashScreen.tick();
}
