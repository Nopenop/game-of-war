#include "deck.h"
#include "card.h"
#include <string>
#include <vector>
#include <stdlib.h>

Deck::Deck(short int isPlayer){
    if (isPlayer == 1){
        std::vector<Card> cards;
        return;
    }
    for (unsigned short int i = 0; i < 52; i++) {
        Card* currCard = new Card(i,i);
        addCard(currCard);
    }

}
void Deck::addCard(Card* card){
    if (cards.size() >= 52){
        return;
    }
    if (card==nullptr){
        return;
    }
    cards.push_back(*card);
}
Card* Deck::drawCard(){
    if (cards.size() <= 0){
        return nullptr;
    }
    Card* ptr = new Card(cards[cards.size()-1].val,cards[cards.size()-1].suit);
    cards.pop_back();
    return ptr;
}
std::string Deck::toString() const{
    if (cards.size() == 0){
        return "There are no cards in this deck";
    }
    std::string returnString = cards[cards.size()-1].toString();
    return returnString;
}