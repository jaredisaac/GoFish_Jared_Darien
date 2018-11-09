// Darien Church (dac4457) and Jared Vochoska (jiv329)
//
// FILE:  player.cpp

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "player.h"
#include "card.h"

using namespace std;


// Default constructor for Player
Player::Player() {
    myName = "";
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
}


//adds a card to the hand
void Player::addCard(Card c) {
    this->myHand.push_back(c);
}


// books specified cards
void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}


//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2) {
    for (int i = 0; i < myHand.size(); i++) {
        for (int j = 0; j < myHand.size(); j++) {
            if ((i != j) && (myHand[i] == myHand[j])) {
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}


//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i].getRank() == c.getRank())
            return true;
    }
}


//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
// Chooses random card from Player's hand and returns it
Card Player::chooseCardFromHand() const {
    int index = rand() % myHand.size();
    return myHand[index];
}


//Does the player have the card c in her hand?
// returns boolean true if card is in hand, else false
bool Player::cardInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i] == c)
            return true;
    }
    return false;
}


//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c) {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i] == c) {
            Card temp = myHand[i];
            myHand.erase(myHand.begin() + i);
            return temp;
        }
    }
}


// returns Player's hand as a string
string Player::showHand() const {
    string myString = "";
    for (int i = 0; i < myHand.size(); i++) {
        myString = myString + " " + myHand[i].toString();
    }
    return myString;
}


// returns Player's book as a string
string Player::showBooks() const {
    string myString = "";
    for (int i = 0; i != myBook.size(); i++) {
        myString = myString + " " + myBook[i].toString();
    }
    return myString;
}


// returns Player's hand size
int Player::getHandSize() const {
    return myHand.size();
}


// returns Player's book size
int Player::getBookSize() const {
    return myBook.size();
}


//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
// bool checkHandForPair(Card &c1, Card &c2);


//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c
// bool sameRankInHand(Card c) const;