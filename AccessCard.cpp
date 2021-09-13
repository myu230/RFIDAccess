#include "AccessCard.h"
#include <SPI.h>

MFRC522 g_mfrc(MFRC_SELECT_PIN, MFRC_RESET_PIN); // global MFRC522 intance
boolean g_bDebug = true; // indicates whether or not we're in debug mode

AccessCard g_masterCard = {
	{ 0x5B, 0x79, 0xC8, 0x10 }
};

AccessCard g_invalidCard = {
  { 0x00, 0x00, 0x00, 0x00 }
};

AccessCardSlot g_cardSlots[MAX_SLOTS];

void setupAccessCard() {
	SPI.begin();
	g_mfrc.PCD_Init();
}

boolean readCard(AccessCard* pOutCard) {
	if (!g_mfrc.PICC_IsNewCardPresent() || !g_mfrc.PICC_ReadCardSerial()) {
		return false;
	}

	if (g_bDebug) {
		Serial.print("Card UUID: ");
	}

	for (byte i = 0; i < g_mfrc.uid.size; i++) {
		if (g_bDebug) {
			Serial.print(g_mfrc.uid.uidByte[i], HEX);
			Serial.print(" ");
		}

		pOutCard->uid[i] = g_mfrc.uid.uidByte[i];
	}

	if (g_bDebug) {
		Serial.println("");
	}

	return true;
}

boolean compareCard(const AccessCard* pCard1, const AccessCard* pCard2) {
	for (byte i = 0; i < 4; i++) {
		if (pCard1->uid[i] != pCard2->uid[i]) {
			return false;
		}
	}

	return true;
}

void printCardId(const AccessCard* pCard) {
	for (byte i = 0; i < 4; i++) {
		Serial.print(pCard->uid[i], HEX);
		Serial.print(" ");
	}
}

void setMasterCard(const AccessCard* pNewMasterCard) {
	for (byte i = 0; i < 4; i++) {
		g_masterCard.uid[i] = pNewMasterCard->uid[i];
	}

	if (g_bDebug) {
		Serial.print("New Master Card Set to :");
		printCardId(pNewMasterCard);
	}
}

void copyCard(AccessCard* pCard1,AccessCard* pCard2) {
  for (byte i = 0; i < 4; i++) {
    pCard1->uid[i] = pCard2->uid[i];
  }

  if (g_bDebug) {
    Serial.print("copied:");
        printCardId(pCard1);
  }
}

int findCardInSlot(const AccessCard *pCard)
{  
  for (int i = 0; i < MAX_SLOTS; i++)
  {
    if (compareCard(pCard, &g_cardSlots[i].card))
    {
      return i;  
    }
  }
  
  return -1;
}

boolean isSlotEmpty(int slotNum)
{
  if (slotNum >=0 && slotNum < MAX_SLOTS){
    if (g_cardSlots[slotNum].b_isCardPresent)
    {
      return false;
    }
   return true;
   }
      
   return false;
}

int addCardToSlot(AccessCard *pCard)
{
  int emptySlotIndex = -1;
  for (int i = 0; i < MAX_SLOTS; i++){
    if (isSlotEmpty(i)){
      emptySlotIndex = i;
      break;
    }
  }
  if (emptySlotIndex != -1){
    copyCard(&g_cardSlots[emptySlotIndex].card, pCard);
    g_cardSlots[emptySlotIndex].b_isCardPresent = true;
  }
  else{
    Serial.println("No slots available");
  }

  return emptySlotIndex;
}

void clearSlot(int slotNum){
  if (slotNum >=0 && slotNum < MAX_SLOTS){
  copyCard(&g_cardSlots[slotNum].card, &g_invalidCard);
  g_cardSlots[slotNum].b_isCardPresent = false;
  }
}
