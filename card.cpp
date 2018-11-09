// Darien Church (dac4457) and Jared Vochoska (jiv329)
//
// FILE: card.cpp

#include <iostream>
#include <string>
#include "card.h"

using namespace std;


// Default constructor for Card class
// Ace of spades by default
Card::Card(){
    myRank = 1;
    mySuit = spades;
}


// Constructor for card with specific rank and suit
Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}


// Function toString() converts a given card to a string representation
// returns string version e.g. Ac 4h Js
string Card::toString() const{
    string out = "";
    out=out+rankString(myRank);
    out=out+suitString(mySuit);
    return out;
}


// function sameSuitAs(c) returns a boolean true if the passed card c is the same suit as the given card
// returns a boolean false if suit is different
bool Card::sameSuitAs(const Card& c) const {
    return (c.mySuit == mySuit);
}


int  Card::getRank() const{
    return myRank;
}  // return rank, 1..13


string Card::suitString(Suit s) const{
    string out = "";
    if(s == spades){
        out+="s";
    }
    if(s == hearts){
        out+="h";
    }
    if(s == diamonds){
        out+="d";
    }
    if(s == clubs){
        out+="c";
    }
    return out;
}  // return suit as simplified string "s", "h",...


string Card::rankString(int r) const{
    string out = "";
    if(r == 1){
        out += "A";
    }
    if (r == 2)
        out += "2";
    if (r == 3)
        out += "3";
    if (r == 4)
        out += "4";
    if (r == 5)
        out += "5";
    if (r == 6)
        out += "6";
    if (r == 7)
        out += "7";
    if (r == 8)
        out += "8";
    if (r == 9)
        out += "9";
    if (r == 10)
        out += "10";
    if(r == 11){
        out += "J";
    }
    if(r == 12){
        out += "Q";
    }
    if(r == 13){
        out += "K";
    }
    return out;
}  // return rank as simplified "A", "2", ..."Q"


// Overridden == operator to evaluate rank of two cards
bool Card::operator == (const Card& rhs) const{
    bool out = false;
    if(rhs.myRank == myRank)
        out = true;
    return(out);
}


// Overridden != operator to evaluate rank of two cards
bool Card::operator != (const Card& rhs) const{
    bool out = true;
    if(rhs.myRank != myRank){
        out = false;
    }
    return(out);
}
