#include "Hand.h"

void Hand::AddCard(Card c)
{
	//Add a card, c, to the array of cards
	cards[numCards] = c;

	//Increment the card number counter
	numCards++;
}

string Hand::Show(bool isDealer, bool hideFirstCard)
{
	string card{ "" };
	stringstream ss{ "" };
	bool hide{ hideFirstCard };


	if (isDealer) //Checks to see if we are displaying dealer's hand or player's
	{
		for (int i = 0; i < numCards; i++) //Loops display for all cards in dealers hand 
		{
			card = cards[i].GetValue(); //Assigns the card value(ie. 2, king, ...)
			card.append(" of " + cards[i].GetSuit()); //Adds the suit to the end of the string

			if (!hide)
			{
				card = "? (Hidden until player stays)"; //If the first card needs to be hidden,
				// First line is replaced
				hide = true;

			}

			ss << "\r\n " << i+1 << ". " << card; //Creates a nicer looking format
		}
		card = ss.str(); //Converts formatting stringstream to a string
		
	}
	else //Displays the players hand //Same format as above
	{

		for (int i = 0; i < numCards; i++)
		{
			card = cards[i].GetValue();
			card.append(" of " + cards[i].GetSuit());

			ss << "\r\n " << i + 1 << ". " << card;
		}
		card = ss.str();
	}
	
	return card; //Returns either the player's or the dealer's hand
}

bool Hand::BlackJack()
{
	bool BJ{ false };

	//If there are two cards and they total 21, blackjack, else not true
	if (numCards == 2 && BestScore() == 21)
	{
		BJ = true;
	}

	return BJ;
}

bool Hand::Under(int n)
{
	bool bUnder{ false };

	//If the best score is less than the dealer's value, n, it is Under
	if (BestScore() < n)
	{
		bUnder = true;
	}

	return bUnder;
}

int Hand::BestScore()
{
	int total{ 0 };
	bool haveAce{ false };
	int acePlace{ 0 }, aceNum{ 0 };

	//Adds all cards currently in the hand
	for (int i = 0; i < numCards; i++)
	{
		//Checks if there are any aces in the hand and sets haveAce to true
		//Sets all of the aces to 11 for the initial count
		if (cards[i].GetIValue() == 1 || cards[i].GetIValue() == 11)
		{
			haveAce = true;
			acePlace = i;
			aceNum++;
			cards[acePlace].SetIValue(11); //Switches the value of all aces back to 11
		}

		total = total + cards[i].GetIValue(); //Totals all of the cards
	}
	
	//Checks to see if the total is over 21 and if it has an ace
	//If it does, it switches the ace from 11 to 1, to see if it can bring it under 22
	if (total > 21 && haveAce)
	{
		int n{ 0 }; 
		while (n < aceNum && total > 21) //Checks total multiple times(In case there are multiple aces)
			//Breaks out if n >= aceNum, as to stop checking past the number of aces in the hand
			//Also breaks out if total is back underneath 22
		{
			for (int a = 0 ; a<numCards; a++) //Checks cards to see if there 
				//Are anymore aces with a value 11, if not this won't do anything
			{
				if (cards[a].GetIValue() == 11)
				{
					cards[a].SetIValue(1); //Sets the value of the 11-value ace to 1
					a = numCards; //Sets a equal to numCards false so to break out of the loop
					//after changing one ace
				}
			}

			total = 0; //Sets total back to zero to recount

			//Recounts reset ace
			for (int i = 0; i < numCards; i++)
			{
				total = total + cards[i].GetIValue();
			}

			n++;
		}
	}

	return total; //Returns either the original, or the ace-modified total
}

bool Hand::MustHit()
{
	bool bHit{ true };

	//(For the dealer) If the best score is under 17, they must hit.
	if (BestScore() < 17)
	{
		bHit = true;
	}
	else bHit = false;

	return bHit;
}

bool Hand::Busted()
{
	bool bBust{ false };

	//If best score is over 21, then it is busted
	if (BestScore() > 21)
	{
		bBust = true;
	}

	return bBust;
}

void Hand::ClearHand()
{
	//Clears hand value back to no cards
	showHand = "";
	numCards = 0;
}

