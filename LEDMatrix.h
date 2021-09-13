#include <Arduino.h>

#define LATCH_PIN 6 // Pin connected to ST_CP of 74HC595
#define CLOCK_PIN 5 // Pin connected to SH_CP of 74HC595
#define DATA_PIN  7 // Pin connected to DS of 74HC595

void setupLED();

void LEDCross(int timeCount);
void LEDOK(int timeCount);
void LEDSmile(int timeCount);
void LEDFrown(int timeCount);
void LEDError(int timeCount);
void LEDAdd(int timeCount);
void LEDSub(int timeCount);
void LEDClear();
