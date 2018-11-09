//
// Created by Darien on 11/8/2018.
//

#include "deck.h"
#include <time.h>
Deck::Deck(){
    myIndex = 0;
    for(int i = 0; i < 13 ; i++){
        myCards[i]= *(new Card(i+1,Card::spades));
        myCards[i + 13]= *(new Card(i+1,Card::hearts));
        myCards[i + 26]= *(new Card(i+1,Card::diamonds));
        myCards[i + 39]= *(new Card(i+1,Card::clubs));
    };
};           // pristine, sorted deck

void Deck::shuffle(){
    srand((unsigned)time(NULL));
    int randomNum = 0;
    for(int j = 0; j < 2; j++) {
        for (int i = myIndex; i < Deck::SIZE; i++) {
            randomNum = ((rand() % (SIZE - i)) + i);
            Card temp = myCards[i];
            myCards[i] = myCards[randomNum];
            myCards[randomNum] = temp;
        };
    };
};   // shuffle the cards in the current deck
Card Deck::dealCard() {
    if(myIndex != (SIZE)) {
        myIndex++;
        return (myCards[myIndex - 1]);
    };
};   // get a card, after 52 are dealt, fail

int  Deck::size() const{
    return (SIZE - myIndex);
};