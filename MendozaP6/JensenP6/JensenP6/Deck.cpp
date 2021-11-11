#include "Deck.h"


Deck::Deck()
{
	//Seed random engine
	engine.seed(chrono::system_clock::now().
		time_since_epoch().count());


	//Initialize cards array from 0-51
	for (int i = 0; i < 51; i++)
	{
		cards[i] = i;
	}
	 /*cards[52] = { 0,1,2,3,4,5,6,7,8,9,10
		,11,12,13,14,15,16,17,18,19,20
		,21,22,23,24,25,26,27,28,29,30
		,31,32,33,34,35,36,37,38,39,40
		,41,42,43,44,45,46,47,48,49,50
		,51 };*/
		
	
	//Initialize topCard
	topCard = { 0 };

	Shuffle();
	

}

void Deck::Shuffle()
{



	//If not generate two new random numbers


	//Write shuffle code
	for (int i = 0; i < 52; i++)
	{
		int random1 = RandomCard();
		int random2 = RandomCard();
		//Use RandomCard() method to shuffle the deck by 
		//randomly switching two cards
		//int randomNumbers = RandomCard();

		//Check that the two random Number generated are different
		while (random1 == random2)
		{
			random1 = RandomCard();
			random2 = RandomCard();
		}
		/*int r = i + randomNumbers;
		int temp = cards[i];
		cards[i] = cards[r];
		cards[r] = temp;*/
		int temp = cards[random1];
		cards[random1] = cards[random2];
		cards[random2] = temp;
	}



}

int Deck::RandomCard()
{
	
	uniform_int_distribution<unsigned int>
		randomInt(0, 51);
	int r = randomInt(engine);
	return r;
}

//I started trying to figure this out, idk if this is correct -Richard
void Deck::Deal(Card& c)
{
	Shuffle();
	if (topCard > 34)
	{
		Shuffle();
		topCard = 0;
	}
	else
	{
		topCard++;
	}
	Card newCard(RandomCard());

	c = newCard;
	c.SetIValue(newCard.GetIValue());
	c.GetSuit();

	
}
