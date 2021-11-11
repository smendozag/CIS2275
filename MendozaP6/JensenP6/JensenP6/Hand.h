// Richard Jensen rjensen10@cnm.edu
// Program 6: Group Project

// Hand.h -> Implementing a hand of cards for both player and dealer

#ifndef HAND_H
#define HAND_H

using namespace std;

#include<array>
#include<iostream>
#include<string>
#include<sstream>
#include"Card.h"
#include<fstream>

class Hand
{
private:
	static const int MAX_CARDS{ 12 };
	int numCards{ 0 };
	string showHand{ "" };
	array<Card, MAX_CARDS> cards;

public:
	Hand() = default;

	void AddCard(Card c);
	string Show(bool isDealer, bool hideFirstCard);
	bool BlackJack();
	bool Under(int n);
	int BestScore();
	bool MustHit();
	bool Busted();
	void ClearHand();

};



#endif // !HAND_H
