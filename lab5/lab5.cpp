/* Zach Lindler
 * zelindl
 * Lab 5
 * Lab Section 002
 * TA: Hunter Ross / Emily Merritt
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include "stdlib.h"
#include "string.h"
using namespace std;
enum Suit { SPADES=0, HEARTS=1, DIAMONDS=2, CLUBS=3 };

typedef struct Card {
  Suit suit;
  int value;
} Card;

string get_suit_code(Card& c);
string get_card_name(Card& c);
bool suit_order(const Card& lhs, const Card& rhs);

int myrandom (int i){
  return std::rand()%i;
}


int main(int argc, char const *argv[]) {
  // IMPLEMENT as instructed below
  /*This is to seed the random generator */
  srand(unsigned (time(0)));

  /*Create a deck of cards of size 52 (hint this should be an array) and
   *initialize the deck*/
   Card deck[52];
   int count=0;
   for(int type=0;type<=3;type++){
     for(int num=2;num<=14;num++){
       deck[count].suit=static_cast<Suit>(type);
       deck[count].value=num;
       count++;
     }
   }

  /*After the deck is created and initialzed we call random_shuffle() see the
   *notes to determine the parameters to pass in.*/
   random_shuffle(deck, deck+52);

   /*Build a hand of 5 cards from the first five cards of the deck created
    *above*/
    //Initialize the array for the hand.
    Card hand[5];
    //Draw a hand of 5 cards off the top of the deck.
    for(int cHand=0;cHand<5;cHand++){
      hand[cHand].suit=deck[cHand].suit;
      hand[cHand].value=deck[cHand].value;
    }

    /*Sort the cards.  Links to how to call this function is in the specs
     *provided*/
     sort(&hand[0], &hand[5], suit_order);

     /*Now print the hand below. You will use the functions get_card_name and
      *get_suit_code */
     for(int pHand=0;pHand<5;pHand++){
       //Set width to 10, right-aligned. Print the value of the card, then the
        //suit. New line.
       cout<<setw(10)<<right<<get_card_name(hand[pHand])<<" of "<<get_suit_code(hand[pHand])<<endl;
     }

  //End
  return 0;
}


/*Parameters: Two structs containing two different cards' information.
 *
 *Returns:    A boolean value "true" or "false"
 *
 *Purpose:    This function compares two cards' suits to determine if one has
 *            a higher value than the other. If the right-hand suit is greater, return
 *            "true"; otherwise, return "false". If two cards have the same
 *            suit, it then compares the numbers on the cards in the statements
 *            manner.
*/
bool suit_order(const Card& lhs, const Card& rhs) {
  //If the left suit is smaller than the right suit, return true.
  if(lhs.suit<rhs.suit){
    return true;
  }
  //If the right suit is smaller than the left suiut, return false.
  else if (lhs.suit>rhs.suit){
    return false;
  }
  else{
    //If both suits are equal:
    //If the left card's value is smaller than the right card's value, return
      //true.
    if(lhs.value < rhs.value){
      return true;
    }
    //If the right card's value is smaller than the left card's value, returns
      //false.
    else{
      return false;
    }
  }
}

/*Parameters: The struct containing a card's information.
 *
 *Returns:    A string containing the character for the suit of that card.
 *
 *Purpose:    This function takes an input of a card struct and reads in the
 *            number in the "suit" member. It then associates that number with
 *            the corresponding suit in the SUIT enum, then returns the
 *            character encoding to be used in the cout statements to print
 *            the card.
 */

string get_suit_code(Card& c) {
  //Switch based on the suit of the card.
  switch (c.suit) {
    case SPADES:    return "\u2660";
    case HEARTS:    return "\u2661";
    case DIAMONDS:  return "\u2662";
    case CLUBS:     return "\u2663";
    default:        return "";
  }
}

/*Parameters: The struct containing a card's information.
 *
 *Returns:    The value or name of a card, ranging from 2-10 and "Jack" to "Ace"
 *
 *Purpose:    This function takes an input of a card struct and reads in the
 *            value of the card. It then returns the name of the card,
 *            especially the non-integer names like Jack, Queen, King, Ace.
*/

string get_card_name(Card& c) {
  //Switch based on the value of the card.
  switch (c.value){
    case 2:   return "2";
    case 3:   return "3";
    case 4:   return "4";
    case 5:   return "5";
    case 6:   return "6";
    case 7:   return "7";
    case 8:   return "8";
    case 9:   return "9";
    case 10:  return "10";
    case 11:  return "JACK";
    case 12:  return "QUEEN";
    case 13:  return "KING";
    case 14:  return "ACE";
    default:  return "";

  }
}
