#include "Game.h"

Game::Game()
{
	log.StartLog(money);
	/*bool bLog{ false };
	bLog = IsLogOpened();
	if (!bLog)
	{
		stringstream ss;
		ss << "\nLogger unable to be opened.";
		error = ss.str();
	}*/
}

bool Game::SetBet(int b)
{
	if (b > 0 && b <= money )
	{
		numberOfBets++;
		bet = b;
		return true;
		
	}
	else
	{
		
		return false;
		//display message in status box of form, play does not continue.
		//tell player to enter new bet and press BET button again
	}


}

void Game::InitialDeal()
{
	for (int i = 0; i < 2; i++)
	{
		
		Card card1;
		Card card2;
		deck.Deal(card1);
		dealersHand.AddCard(card1);
		deck.Deal(card2);
		playersHand.AddCard(card2);
		//will need card and deck classes done before I'll be able to figure out exactly how this works
	}
	best = playersHand.BestScore();
	dBest = dealersHand.BestScore();
}

string Game::ShowPlayerHand()
{
	return playersHand.Show(false, false);
}

string Game::ShowDealersHand(bool hide)
{
	return dealersHand.Show(true, hide);
}

bool Game::IsBlackJack()
{
	return playersHand.BlackJack();
}

bool Game::PlayerBusted()
{
	return playersHand.Busted();
}

bool Game::PlayerContinues()
{
	if (PlayerBusted() == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::PlayerHits()
{
	Card newCard;
	deck.Deal(newCard);
	playersHand.AddCard(newCard);
	//will need card and deck classes done before I'll be able to figure out exactly how this works
	best = playersHand.BestScore();
}

string Game::PlayerWins()
{
	wins++;
	stringstream desc;
	desc << "Player Wins!\n";
	if (IsBlackJack())
	{
		money += (bet * 1.5);
		desc << "Player got BlackJack!\n";

	}
	else
	{
		money += bet;
	}
	desc << "Player now has $" << money << ".\n";
	log.WriteLog(desc.str());
	return desc.str();
}

bool Game::DealerContinues()
{
	if (dealersHand.MustHit())
	{
		Card newCard;
		deck.Deal(newCard);
		dealersHand.AddCard(newCard);
		//will need card and deck classes done before I'll be able to figure out exactly how this works
		return true;
	}
	else
	{
		dBest = dealersHand.BestScore();
		return false;
	}
}

string Game::DealerWins()
{
	losses++;
	stringstream desc;
	desc << "Player Loses.\r\n"
		<< "Player bet $" << bet << ".";
	money -= bet;
	desc << "\r\nPlayer now has $" << money << " left.\n";

	log.WriteLog(desc.str());
	return desc.str();

}

string Game::Tie()
{
	ties++;
	stringstream desc;
	desc << "The game is a tie. Player has $" << money << ".\n";

	log.WriteLog(desc.str());
	return desc.str();
}

string Game::NoResults()
{
	return "";
}

string Game::ShowResults()
{
	if (PlayerBusted() && dealersHand.Busted())
	{

		return Tie();
	}
	else if (PlayerBusted() && !dealersHand.Busted())
	{
		return DealerWins();
	}
	else if (dealersHand.Busted() && !PlayerBusted())
	{
		return PlayerWins();
	}
	else if (playersHand.BestScore() > dealersHand.BestScore())
	{
		return PlayerWins();
	}
	else if (playersHand.BestScore() < dealersHand.BestScore())
	{
		return DealerWins();
	}
	else if (playersHand.BestScore() == dealersHand.BestScore())
	{
		return PlayerWins();
	}
	else
	{
		return NoResults();
	}

}

void Game::ClearHands()
{
	playersHand.ClearHand();
	dealersHand.ClearHand();
}

void Game::EndGame()
{
	stringstream summary;
	summary << "Game summary: Player played " << numberOfBets << " games total.\n"
		<< "Player won " << wins << " times, and lost " << losses << " times.\n"
		<< "Player tied with the dealer " << ties << " times.\n"
		<< "Player ended the game with $" << money << ". Thanks for playing!";
	log.CloseLog(summary.str());

}

string Game::GetBest(bool IsDealer)
{
	string sBest{""};

	if (IsDealer)
	{
		sBest = to_string(dBest);
	}
	else sBest = to_string(best);

	return sBest;
}

double Game::GetMon()
{
	return money;
}