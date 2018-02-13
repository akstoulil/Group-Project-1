#pragma once
#include "CardClass.h"
#include <vector>
#include <random>
#include <iostream>
#include <time.h>

class PlayerClass
{
protected:
	int chipsToBet;
	int card_total;
	bool playerChoice;
	int chipsToPlay;
	vector<CardClass> currentHand;

public:

	PlayerClass() {

		chipsToBet = 0;
		card_total = 0;
		chipsToPlay = 0;

	}

	PlayerClass(int chipsToBet, int card_total, bool playerChoice, int chipsToPlay)
	{
		chipsToBet = 0;
		card_total = 0;
		playerChoice = false;
		chipsToPlay = 0;
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

	void initializeHand(CardClass arr[][13]) {

		int counter = 0;

		while (counter < 2) {

			srand(time(NULL));

			int randomSuit = rand() % 4;
			int randomNumber = rand() % 13;

			if (arr[randomSuit][randomNumber].getState() == false) {

				CardClass card = arr[randomSuit][randomNumber];
				currentHand.push_back(card);

				counter++;

				card_total += card.getNumber();
				cout << card.getNumber() << endl;

				arr[randomSuit][randomNumber].setState(true);

			}
		}

	}
};