#include "Doorlock.h"
#include "AccessCard.h"
#include "LCD.h"
#include "LEDMatrix.h"

#define SERVO_OUPPUT_PIN 8


// External Global Variables defined in other source files:
extern AccessCard g_masterCard;
extern AccessCard g_clearCard;
extern MFRC522 g_mfrc;
extern boolean g_bDebug;
extern Servo g_servo;
extern LiquidCrystal g_lcd;

void setup() {
  Serial.begin(9600);
  setupAccessCard();
  setupDoorlock(SERVO_OUPPUT_PIN);
  setupLCD();
  setupLED();
  Serial.println("Please put the card to the induction area...");
}

void loop() {
  AccessCard card;

  LCD_defaultDisplay();

  boolean b_successfulRead = false;
  if (readCard(&card)) {
    if (g_bDebug) {
      Serial.println("Card read success!");
    }
    if (compareCard(&card, &g_masterCard)) {
     LCD_masterCard();
      Serial.println("Master card!");
      Serial.println("Add Remove Card!");

      delay(2000);
      do{
        b_successfulRead = readCard(&card);
        if (g_bDebug && b_successfulRead) {
         Serial.println("Card 2 read success!");
        }
       }while(!b_successfulRead);

      if (compareCard(&card, &g_masterCard)) {
          LCD_errorMasterCard();
          LEDError(2000);
          Serial.println("Cannot change master");
      }else{
        int slotNum = findCardInSlot(&card);
        if (slotNum == -1){
          slotNum = addCardToSlot(&card);
          Serial.print("Card added to slot: ");
          Serial.print(slotNum, DEC);
          Serial.println();
          
          if (slotNum == -1){
             LCD_errorSlotsFull();
             LEDError(2000);
          }else
          {
            LCD_tagAdded();
            LEDAdd(2000);
          }
                 
        }else{
          clearSlot(slotNum);
          LCD_tagRemoved();
          LEDSub(2000);
          Serial.print("Card removed from slot: ");
          Serial.print(slotNum, DEC);
          Serial.println();
        }
         /*for (int i = 0; i < 100; i++){
           if (compareCard(&card, &g_cards[i])){
            Serial.println("Card Removed");
            copyCard(&g_cards[i], &g_clearCard);
            return;
           }else {
            Serial.println("Card Added");
            copyCard(&g_cards[i], &card);
            return;
           }
         }*/
      }
    } else {
      Serial.println("Not master card!");

      int slotNum = findCardInSlot(&card);

      if (slotNum == -1){
        LCD_accessDenied();
        Serial.println("Access Denied");
        LEDCross(2000);
        return;
      }else{
        LCD_accessGranted();
        openDoor(); 
        Serial.println("Access Granted");
        LEDSmile(2000);
        closeDoor();
        return;
      }
      
  /*    
       for (int i = 0; i < 100; i++){
         if (compareCard(&card, &g_cards[i])) {
            openDoor(); 
            Serial.println("Access Granted");
            delay(1000);
            closeDoor();
            return;
          }else{
            Serial.println("Access Denied");
            return;
          }
       }

*/
      /*openDoor(); 
      delay(1000);
      closeDoor();
  
*/
    // use the logic below if you want to set new master card
    boolean bShouldSetNewMaster = false;
    if (bShouldSetNewMaster) {
      setMasterCard(&card);
    }
  }
  }
  delay(500);

}
