// FILE:  player.cpp

#include <iostream>
#include <string>
#include <vector>

#include "player.h"
#include "card.h"
using namespace std;


Player::Player() {
    myName = "";
}


//adds a card to the hand
void Player::addCard(Card c) {
    this->myHand.push_back(c);
}


void Player::bookCards(Card c1, Card c2) {
    int index1 = 0, index2 = 0;
    for (int i = 0; i < myHand.end(); i++) {
        if (myHand[i] == c1)
            index1 = i;
        if (myHand[i] == c2)
            index2 = i;
    }
    myBook.push_back(c1);
    myBook.push_back(c2);
    myHand.erase(index1);
    myHand.erase(index2);
}


//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2) {
    for (int i = 0; i < myHand.end(); i++) {
        for (int j = 0; j < myHand.end; j++) {
            if ((i != j) && (myHand[i] == myHand[j])) {
                c1 = myHand[i];
                c2 = myHand[j];
            }
        }
    }
}


//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const;

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const;

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const;

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c);

string Player::showHand() const;
string Player::showBooks() const;

int Player::getHandSize() const;
int Player::getBookSize() const;

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool checkHandForPair(Card &c1, Card &c2);

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

bool sameRankInHand(Card c) const;