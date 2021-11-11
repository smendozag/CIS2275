#include "Card.h"
#include"Deck.h"




Card::Card(int n)
{

	int iSuit = 0;
	//Determine Suit by deviding
	iSuit = n / 13;

	//Determine point value
	iValue = (n % 13) + 1;



	switch (iSuit)
	{
	case 0: suit = "Spades";
		break;
	case 1: suit = "Hearts";
		break;
	case 2: suit = "Clubs";
		break;
	case 3: suit = "Diamonds";
		break;

	default:cout << "Suit is out of range";
		break;
	}
	stringstream ss;
	//ss << iValue;
	switch (iValue)
	{
	case 1: value = "Ace";
		break;
	case 2:
		ss << iValue;
		value = ss.str();
		break;
	case 3:
		ss << iValue;
		value = ss.str();
		break;
	case 4:
		ss << iValue;
		value = ss.str();
		break;
	case 5:
		ss << iValue;
		value = ss.str();
		break;
	case 6:
		ss << iValue;
		value = ss.str();
		break;
	case 7:
		ss << iValue;
		value = ss.str();
		break;
	case 8:
		ss << iValue;
		value = ss.str();
		break;
	case 9:
		ss << iValue;
		value = ss.str();
		break;
	case 10:
		ss << iValue;
		value = ss.str();
		break;
	case 11: value = "Jack";
		break;
	case 12: value = "Queen";
		break;
	case 13: value = "King";
		break;
	default:
		break;
	}

	//Adjust point value further
	if (iValue > 10) {
		iValue = 10;
	}
}

Card::Card() {}
