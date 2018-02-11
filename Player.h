#pragma once
class Player
{
protected:
	int chipsToBet;
	int card_total;
	bool playerChoice;
	int chipsToPlay;
public:
	Player(int chipsToBet, int card_total, bool playerChoice, int chipsToPlay)
	{
		chipsToBet = 0.0;
		card_total = 0;
		playerChoice = 0;
		chipsToPlay = 0.0;
	}

	int setchipsToBet(int b)
	{
		chipsToBet = b;
	}
	int setCard_total(int t)
	{
		card_total = t;
	}
	bool setPlayerChoice(bool p)
	{
		playerChoice = p;
	}
	int setchipsToPlay(int ctp)
	{
		chipsToBet = ctp;
	}

	int getchipsToBet() const
	{
		return chipsToBet;
	}

	int getCard_total() const
	{
		return card_total;
	}

	bool getPlayerChoice() const
	{
		return playerChoice;
	}
	int getchipsToPlay() const
	{
		return chipsToPlay;
	}

};

	


