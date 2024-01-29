#include "card.h"
#include <string>

Card::Card(unsigned short int val,unsigned short int suit){
    setVal(val);
    setSuit(suit);
}
void Card::setVal(unsigned short int val){
    this->val = val%13;
}
void Card::setSuit(unsigned short int suit){
    this->suit = suit%4;
}

std::string Card::toString() const{
    std::string returnString = "";
    switch(val){
        case(12):
        returnString += "Ace";
        break;
        case(11):
        returnString += "King";
        break;
        case(10):
        returnString += "Queen";
        break;
        case(9):
        returnString += "Jack";
        break;
        case(8):
        returnString += "10";
        break;
        default:
        returnString += char(val + 50);
    }
    returnString += " of ";
    switch(suit){
        case(0):
        returnString += "Clubs";
        break;
        case(1):
        returnString += "Diamonds";
        break;
        case(2):
        returnString += "Hearts";
        break;
        case(3):
        returnString += "Spades";
        break;
    }
    return returnString;
}