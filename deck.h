#ifndef DECK_H
#define DECK_H
#include <string>
#include <vector>
#include "card.h"
class Deck{
    public:
    std::vector<Card> cards;
    Deck(short int isPlayer);
    void addCard(Card* card);
    Card* drawCard();
    std::string toString() const;
};
#endif