/*
Ben Schrandt bschrandt@cnm.edu
Project 6: Blackjack game
game.h
*/

#ifndef GAME_H
#define GAME_H
#include "Logger.h"
#include "Hand.h"
#include "Deck.h"



using namespace std;

class Game
{
private:
	int bet{ 0 };
	double money{ 1000 };
	int wins{ 0 }, losses{ 0 }, ties{ 0 }, numberOfBets{ 0 };
	Deck deck;
	Hand playersHand;
	Hand dealersHand;
	Logger log; //will it construct from here, or do I need this in the game constructor also?
	int best, dBest; //This variable keeps score for the player so they don't have to

public:
	//string error{ "" };
	Game(); //default constructor
	bool SetBet(int b);
	void InitialDeal(); //deal player and dealer 2 cards
	string ShowPlayerHand(); //returns playersHand.Show(false, false) (hand class method)
	string ShowDealersHand(bool hide); //returns dealersHand.Show(true, hide) (hand class method)
	bool IsBlackJack(); //returns playersHand.blackjack (hand class method)
	bool PlayerBusted(); //returns playersHand.busted (hand class method)
	bool PlayerContinues(); //checks if players hand is busted or over 22. If not busted and under 21 return true else return false
	void PlayerHits(); //adds Card to playersHand
	string PlayerWins(); //return decription "Player Wins!" Then adds amount of bet and tells how much money player has. (blackjack win is 1.5 * bet)
	bool DealerContinues(); //checks if dealer MustHit (hand class method)
	string DealerWins(); //Starts with "Player Loses" and shows amount of bet and tells how much money player has.
	string Tie(); //return string starting with "tie" and tells player how much money they have
	string NoResults(); // placeholder returns "" (empty string)
	string ShowResults(); //determines disposition of game and calls one of the methods above for description.
	void ClearHands(); //calls clearHand method for both hands (clearhand is a hand method)
	bool IsLogOpened() { return log.IsLogOpen(); } //(log class method)
	void EndGame(); //creates summary string and calls loggers closelog (log class method) with string as argument
	string GetBest(bool IsDealer);//Gets the best score
	double GetMon();

};

#endif