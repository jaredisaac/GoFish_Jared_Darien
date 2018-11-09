//
// Created by Darien on 11/8/2018.
//

#include <iostream>
#include <string>
#include "card.h"


Card::Card(){
    myRank = 1;
    mySuit = spades;
};          // default, ace of spades

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
};

string Card::toString()              const{
    string out = "";
    out=out+rankString(myRank);
    out=out+suitString(mySuit);
    return out;
};  // return string version e.g. Ac 4h Js

bool Card::sameSuitAs(const Card& c) const{
    if(c.mySuit == mySuit){
        return true;
    }else{
        return false;
    };
};  // true if suit same as c

int  Card::getRank()                 const{
    return myRank;
};  // return rank, 1..13

string Card::suitString(Suit s)      const{
    string out = "";
    if(s == spades){
        out+="s";
    };
    if(s == hearts){
        out+="h";
    };
    if(s == diamonds){
        out+="d";
    };
    if(s == clubs){
        out+="c";
    };
    return out;
};  // return "s", "h",...

string Card::rankString(int r)       const{
    string out = "";
    if(r == 1){
        out += "A";
    };
    if((r > 1)&&(r < 11)){
        out += to_string(r);
    };
    if(r == 11){
        out += "J";
    };
    if(r == 12){
        out += "Q";
    };
    if(r == 13){
        out += "K";
    };
    return out;
};  // return "A", "2", ..."Q"


bool Card::operator == (const Card& rhs) const{
    bool out = false;
    if(rhs.myRank == myRank){
            out = true;
    };
    return(out);
};
bool Card::operator != (const Card& rhs) const{
    bool out = true;
    if(rhs.myRank != myRank){
        out = false;
    };
    return(out);
};
