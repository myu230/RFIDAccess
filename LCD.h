#include <LiquidCrystal.h>
#include <SPI.h>

void setupLCD();

void LCD_defaultDisplay();
void LCD_tagAdded();
void LCD_tagRemoved();
void LCD_masterCard();
void LCD_accessGranted();
void LCD_accessDenied();
void LCD_errorMasterCard();
void LCD_errorSlotsFull();
