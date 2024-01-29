#ifndef CARD_H
#define CARD_H
#include <string>
class Card{
    public:
    unsigned short int val;
    unsigned short int suit;
    Card(unsigned short int val,unsigned short int suit);
    void setVal(unsigned short int val);
    void setSuit(unsigned short int suit);
    std::string toString() const;
};
#endif