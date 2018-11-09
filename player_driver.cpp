// FILE: go_fish.cpp
//
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


int main( )
{
    int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << "Joe's hand size is " << p1.getHandSize() << endl;
    cout << "Joe's book size is " << p1.getBookSize() << endl;

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    Card c1(1, Card::spades);
    Card c2(2, Card::diamonds);
    Card c3(1, Card::hearts);

    p1.addCard(c1);
    p2.addCard(c2);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    cout << p1.cardInHand(c1) << endl;
    p1.removeCardFromHand(c1);
    cout << p1.cardInHand(c1) << endl;

    cout << p1.getName() <<" has : " << p1.showHand() << endl;

    cout << (p1.chooseCardFromHand()).toString() << endl;
    cout << (p1.chooseCardFromHand()).toString() << endl;
    cout << (p1.chooseCardFromHand()).toString() << endl;

    cout << p1.rankInHand(c3) << endl;
    p1.addCard(c1);
    cout << p1.rankInHand(c3) << endl;
    p1.addCard(c3);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << "Joe's hand size is " << p1.getHandSize() << endl;

    Card book1, book2;
    p1.checkHandForBook(book1, book2);
    p1.bookCards(book1, book2);
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p1.getName() <<" has : " << p1.showBooks() << endl;

    cout << "Joe's hand size is " << p1.getHandSize() << endl;
    cout << "Joe's book size is " << p1.getBookSize() << endl;

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}