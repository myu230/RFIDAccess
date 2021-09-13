#include "LCD.h"

LiquidCrystal g_lcd(19, 18, 17, 16, 15, 14);

void setupLCD() {
  g_lcd.begin(16, 2);
}

void LCD_defaultDisplay() {
  g_lcd.clear();
  g_lcd.print("-Access Control-");
  g_lcd.setCursor(0, 1);
  g_lcd.print(" Scan Your Tag!");
}

void LCD_tagAdded() {
  g_lcd.clear();
  g_lcd.setCursor(0, 0);
  g_lcd.print("   Tag Added!");  
  delay(100);
}

void LCD_tagRemoved() {
  g_lcd.clear();
  g_lcd.setCursor(0, 0);
  g_lcd.print("  Tag Removed!");
    delay(100);
}

void LCD_masterCard() {
  g_lcd.clear();
  g_lcd.print("Program mode:");
  g_lcd.setCursor(0, 1);
  g_lcd.print("Add/Remove Tag");
}

void LCD_accessGranted() {
  g_lcd.clear();
  g_lcd.setCursor(0, 0);
  g_lcd.print(" Access Granted!");
  delay(100);
}

void LCD_accessDenied() {
  g_lcd.clear();
  g_lcd.setCursor(0, 0);
  g_lcd.print(" Access Denied!");
  delay(100);
}

void LCD_errorMasterCard() {
  g_lcd.clear();
  g_lcd.print("Error: Can not ");
  g_lcd.setCursor(0, 1);
  g_lcd.print("change master");
  delay(100);
}

void LCD_errorSlotsFull() {
  g_lcd.clear();
  g_lcd.print("Error: No slots ");
  g_lcd.setCursor(0, 1);
  g_lcd.print("available!");
  delay(100);  
}
