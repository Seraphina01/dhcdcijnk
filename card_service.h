#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H
#include"model.h"

int addCard(Card card);
int initCardList();
Card* queryCards(const char* pName, int* pIndex);
void releaseCardList();

#endif 


