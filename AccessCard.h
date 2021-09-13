#ifndef ACCESS_CARD_H
#define ACCESS_CARD_H

#include <Arduino.h>
#include <MFRC522.h>

#define MFRC_SELECT_PIN 10
#define MFRC_RESET_PIN 9
#define MAX_SLOTS 1

// !IMPORTANT!
// AccessCard(); // must call this function in setup

typedef struct AccessCard {
	byte uid[4];
};

typedef struct AccessCardSlot{
  boolean b_isCardPresent;
  AccessCard card;
};

void setupAccessCard();

// AccessCard related functions
boolean readCard(AccessCard *pOutCard);
boolean readNewCard(AccessCard *pOutCard);
boolean isSlotEmpty(int slotNum);
int findCardInSlot(const AccessCard *pCard);

boolean compareCard(const AccessCard* pCard1, const AccessCard* pCard2);
void printCardId(const AccessCard* pCard);
int addCardToSlot(AccessCard *pCard);
void clearSlot(int slotNum);

// Master Card related functions
void setMasterCard(const AccessCard* pNewMasterCard);
void copyCard(AccessCard* pCard1,AccessCard* pCard2);

#endif // !ACCESS_CARD_H
