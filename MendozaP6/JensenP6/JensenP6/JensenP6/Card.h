#ifndef CARD_H
#define CARD_H
//#include "Deck.h"
#include<iostream>
#include<string>
#include<array>
#include<random>
#include<sstream>
#include<chrono>
#include<cstdlib>
using namespace std;

class Card
{
private:
	int iValue;  //numeric value corresponding to the card
	string value;  //”Ace” “2” through “9”, “Ten”, “Jack”, “Queen”, “King”
	string suit;  //”S”, “H”, “C”, “D”

public:
	Card();
	Card(int n);
	void SetIValue(int val) { iValue = val; }

	string GetValue() { return value; }
	int GetIValue() { return iValue; }
	string GetSuit() { return suit; }


};

#endif
