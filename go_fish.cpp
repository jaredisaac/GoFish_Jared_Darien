// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void dealHand(Deck &d, Player &p, int numCards){
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

int main() {
   ofstream outFile("gofish_results.txt");
   if(outFile.is_open()){

       Player j("Jared");
       Player d("Darien");

       Deck deck1;
       deck1.shuffle();

       dealHand(deck1,j,7);
       dealHand(deck1,d,7);

       bool gameOver = false;
       bool tie = false;
       Player *currentPlayer = &j;
       Player *otherPlayer = &d;
       Player *winner;

       while(!gameOver){
           //check for a winner
           if ((currentPlayer->getBookSize() == 28) || (otherPlayer->getBookSize() == 28) || ((currentPlayer->getBookSize() == 26) && (otherPlayer->getBookSize() == 26))) {
               gameOver = true;
               if(currentPlayer->getBookSize() > otherPlayer->getBookSize()){
                   winner = currentPlayer;
               }else{
                   if(currentPlayer->getBookSize() < otherPlayer->getBookSize()){
                       winner = otherPlayer;
                   }else{
                       tie = true;
                   }
               }
           } else {
               //check for pairs
               Card book1;
               Card book2;

               while(currentPlayer->checkHandForBook(book1,book2)){
                   currentPlayer->removeCardFromHand(book1);
                   currentPlayer->removeCardFromHand(book2);
                   currentPlayer->bookCards(book1,book2);
               }

               while(otherPlayer->checkHandForBook(book1,book2)){
                   otherPlayer->removeCardFromHand(book1);
                   otherPlayer->removeCardFromHand(book2);
                   otherPlayer->bookCards(book1,book2);
               }
               outFile<<currentPlayer->getName()<<"'s turn:"<<endl;
               outFile<<j.getName()<<" has: "<<j.showHand()<<endl;
               outFile<<j.getName()<<"'s book has: "<<j.showBooks()<<endl;
               outFile<<d.getName()<<" has: "<<d.showHand()<<endl;
               outFile<<d.getName()<<"'s book has: "<<d.showBooks()<<endl;

               //if hand is empty, add a card
               if((currentPlayer->getHandSize() == 0) && (deck1.size() != 0)){
                   Card newCard = deck1.dealCard();
                   currentPlayer->addCard(newCard);
                   outFile<<currentPlayer->getName()<<" draws "<<newCard.toString()<<endl;

                   if(currentPlayer->getName() == "Jared"){
                       currentPlayer = &d;
                       otherPlayer = &j;
                   }else{
                       if(currentPlayer->getName() == "Darien") {
                           currentPlayer = &j;
                           otherPlayer = &d;
                       }
                   }
               }else{
                   if((currentPlayer->getHandSize() == 0) && (deck1.size() == 0)){
                   outFile<<"There are no more cards left"<<endl<<endl;
                   }else {
                       Card currentCard = currentPlayer->chooseCardFromHand();
                       outFile<<currentPlayer->getName()<<" asks - Do you have a "<<currentCard.rankString(currentCard.getRank())<<"?"<<endl;

                       //checks for card  of same rank
                       if(otherPlayer->rankInHand(currentCard)){
                           outFile << otherPlayer->getName() << " says - Yes."<<endl;
                           while (otherPlayer->cardInHand(currentCard)){
                             Card transferCard = otherPlayer->removeCardFromHand(currentCard);
                             currentPlayer->addCard(transferCard);
                           }
                       }else{
                           outFile<<otherPlayer->getName()<<" says - Go Fish"<<endl;
                           Card gofishCard = deck1.dealCard();
                           currentPlayer->addCard(gofishCard);
                           outFile<< currentPlayer->getName()<< " draws "<<gofishCard.toString()<<endl;

                           if(currentPlayer->getName() == "Jared"){
                               currentPlayer = &d;
                               otherPlayer = &j;
                           }else{
                               if(currentPlayer->getName() == "Darien") {
                                   currentPlayer = &j;
                                   otherPlayer = &d;
                               }
                           }
                       }
                   }
               }
           }
       }
       if (tie) {
           outFile << "Tie Game" << endl;
       } else {
           outFile <<winner->getName()<< " is the winner." << endl;
       }
    outFile << "Cards left in deck: " << deck1.size() << endl;
   }
    outFile.close();
    return 0;
}
