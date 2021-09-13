#include "LEDMatrix.h"

void setupLED(){
 // set pins to output
 pinMode(LATCH_PIN, OUTPUT);
 pinMode(CLOCK_PIN, OUTPUT);
 pinMode(DATA_PIN, OUTPUT);
}

void LEDCross(int timeCount){
  
  byte x[] = { 0x7E, 0xBD, 0xDB, 0xE7};
  byte y[] = { 0x81, 0x42, 0x24, 0x18};

 for (int t = 0; t < timeCount; t++)
 {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(LATCH_PIN, LOW);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, x[i]);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, y[i]);
      digitalWrite(LATCH_PIN, HIGH);
    }
 }

  LEDClear();
}

void LEDOK(int timeCount){
  byte x[] = { 0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};
  byte y[] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x08, 0x10};

   for (int t = 0; t < timeCount; t++)
   {
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, x[i]);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, y[i]);
        digitalWrite(LATCH_PIN, HIGH);
      }
   }
   
   LEDClear();
}

void LEDSmile(int timeCount){
  byte x[] = { 0xC3, 0xBD, 0x5A, 0x7E, 0x66};
  byte y[] = { 0x81, 0x42, 0x28, 0x10, 0x04};

   for (int t = 0; t < timeCount; t++)
   {
      for (int i = 0; i < 5; i++)
      {
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, x[i]);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, y[i]);
        digitalWrite(LATCH_PIN, HIGH);
      }
   }
   
   LEDClear();
}


void LEDFrown(int timeCount){
  byte x[] = { 0xC3, 0xBD, 0x5A, 0x7E, 0x66};
  byte y[] = { 0x81, 0x42, 0x24, 0x10, 0x08};

   for (int t = 0; t < timeCount; t++)
   {
      for (int i = 0; i < 5; i++)
      {
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, x[i]);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, y[i]);
        digitalWrite(LATCH_PIN, HIGH);
      }
   } 
   
   LEDClear();
}

void LEDError(int timeCount){
  byte x[] = { 0xC3, 0x66, 0x7E, 0xA5 };
  byte y[] = { 0x81, 0x38, 0x04, 0x42 };

   for (int t = 0; t < timeCount; t++)
   {
      for (int i = 0; i < 4; i++)
      {
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, x[i]);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, y[i]);
        digitalWrite(LATCH_PIN, HIGH);
      }
   }
   
   LEDClear();
}

void LEDAdd(int timeCount){
  byte x[] = { 0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDD, 0xBF, 0x7F, 0xF8 };
  byte y[] = { 0x80, 0x41, 0x20, 0x10, 0x08, 0x04, 0x08, 0x10, 0x02 };

   for (int t = 0; t < timeCount; t++)
   {
      for (int i = 0; i < 9; i++)
      {
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, x[i]);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, y[i]);
        digitalWrite(LATCH_PIN, HIGH);
      }
   }
   
   LEDClear();
}

void LEDSub(int timeCount){
  byte x[] = { 0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F, 0xF8};
  byte y[] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x08, 0x10, 0x02 };

   for (int t = 0; t < timeCount; t++)
   {
      for (int i = 0; i < 9; i++)
      {
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, x[i]);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, y[i]);
        digitalWrite(LATCH_PIN, HIGH);
      }
   }
   
   LEDClear();
}

void LEDClear(){

  byte clearLED = 0x00; 
  
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, clearLED);
  digitalWrite(LATCH_PIN, HIGH);
}
