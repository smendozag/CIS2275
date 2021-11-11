#ifndef DECK_H
#define DECK_H


#include "Card.h"
#include<random>


class Deck
{
private:
	//array <int, 52>  cards;	//array of 52 cards
	int cards[52];
	int topCard;	//0-51, index of the next card to be dealt
	std::default_random_engine engine;	//Creates an object of the random engine 



public:

	Deck();
	void Shuffle();
	int RandomCard();
	void Deal(Card& c);
};

#endif
