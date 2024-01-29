#include <iostream>
#include <stdlib.h>
#include "card.h"
#include "deck.h"
#include "time.h"

void shuffle(Deck *mainDeck, Deck *player1, Deck *player2){
    

    for(int i = 0; i < mainDeck->cards.size(); i++){
        unsigned int random= rand()%52;
        Card* temp = new Card(mainDeck->cards[i].val,mainDeck->cards[i].suit);
        mainDeck->cards[i] = mainDeck->cards[random];
        mainDeck->cards[random] = *temp;
    }
    bool isPlayer1 = true;
    while(mainDeck->cards.size() != 0){
        if (isPlayer1) player1->addCard(mainDeck->drawCard());
        else player2->addCard(mainDeck->drawCard());
        isPlayer1 = !isPlayer1;
    }
}
void shufflePlayer(Deck *player){

    for(int i = 0; i < player->cards.size(); i++){
        unsigned int random= rand()%52;
        Card* temp = new Card(player->cards[i].val,player->cards[i].suit);
        player->cards[i] = player->cards[random];
        player->cards[random] = *temp;
    }
}

void giveCards(Deck *mainDeck, Deck *player){
    while(mainDeck->cards.size() != 0){
        player->addCard(mainDeck->drawCard());
    }
}

void cardsAreSame(Deck *mainDeck, Deck *player1, Deck *player2){
    mainDeck->addCard(player1->drawCard());
    mainDeck->addCard(player2->drawCard());
    mainDeck->addCard(player1->drawCard());
    mainDeck->addCard(player2->drawCard());
    
    Card* player1TopCard = player1->drawCard();
    Card* player2TopCard = player2->drawCard();

    mainDeck->addCard(player1TopCard);
    mainDeck->addCard(player2TopCard);

    if (player1TopCard->val > player2TopCard->val) giveCards(mainDeck,player1);
    else if (player2TopCard->val > player1TopCard->val) giveCards(mainDeck,player2);
    else {
        cardsAreSame(mainDeck, player1, player2);
    }
}

int mainGame(Deck *mainDeck, Deck *player1, Deck *player2){
    // main game function. Returns 0, 1, or 2
    // 0 for continue
    // 1 for player 1 won
    // 2 for player 2 won
    

    // check to see if someone's hand is empty
    // to determine who is the loser
    if (player1->cards.size() == 0) return 2;
    if (player2->cards.size() == 0) return 1;

    std::cout << "Player 1 plays: " + player1->toString() << std::endl;
    std::cout << "Player 2 plays: " + player2->toString() << std::endl;

    Card* player1TopCard = player1->drawCard();
    Card* player2TopCard = player2->drawCard();

    mainDeck->addCard(player1TopCard);
    mainDeck->addCard(player2TopCard);

    if (player1TopCard->val > player2TopCard->val) {
        std::cout << "Player 1 wins round!" <<std::endl;
        giveCards(mainDeck,player1);
        shufflePlayer(player1);
        }
    else if (player2TopCard->val > player1TopCard->val) {
        std::cout << "Player 2 wins round!" <<std::endl;
        giveCards(mainDeck,player2);
        shufflePlayer(player1);
        }
    else {
        cardsAreSame(mainDeck, player1, player2);
        shufflePlayer(player1);
        shufflePlayer(player2);
    }
    std::cout<<player1->cards.size()<<std::endl;
    std::cout<<player2->cards.size()<<std::endl;
    return 0;
}

int main() {
    std::cout << "The game of war!" << std::endl;
    // Deck* deck = new Deck(0);
    // std::cout << deck->toString() << std::endl;
    // Card* c1 = deck->drawCard();
    // std::cout << c1->toString() << std::endl;
    // std::cout << deck->toString() << std::endl;
    // deck = new Deck(1);
    // std::cout << deck->toString() << std::endl;
    Deck *mainDeck = new Deck(0);
    Deck *player1 = new Deck(1);
    Deck *player2 = new Deck(1);
    shuffle(mainDeck,player1,player2);
    int condition = mainGame(mainDeck, player1, player2);
    int balling = 0;
    srand(time(0));
    while(condition == 0){
        std::cout<<"Next Turn"<<std::endl;
        // std::cin >> balling;
        condition = mainGame(mainDeck, player1, player2);
    }
    std::cout << condition << std::endl;
    switch(condition){
        case(1):
        std::cout << "Player 1 one" << std::endl;
        break;
        case(2):
        std::cout << "Player 2 one" << std::endl;
        break;
    } 




}