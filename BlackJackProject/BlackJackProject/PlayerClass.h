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
	int splitHandTotal1;
	int splitHandTotal2;
	bool playerChoice;
	bool checkSplit;
	int chipsToPlay;
	vector<CardClass> currentHand;
	vector<vector<CardClass>> splitHands;

public:

	PlayerClass() {

		chipsToBet = 0;
		card_total = 0;
		chipsToPlay = 0;
		checkSplit = false;
		vector<CardClass> sHand1;
		vector<CardClass> sHand2;
		splitHands.push_back(sHand1);
		splitHands.push_back(sHand2);

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

	int getSplitHandTotal1() {

		return splitHandTotal1;

	}

	int getSplitHandTotal2() {

		return splitHandTotal2;

	}

	bool getCheckSplit() const {

		return checkSplit;

	}

	void initializeHand(CardClass arr[][13]) {

		int counter = 0;

		while (counter < 2) {

			srand(time(NULL));

			int randomSuit = rand() % 4;
			int randomNumber = rand() % 13;

			if (arr[randomSuit][randomNumber].getState() == false) {

				CardClass card = arr[randomSuit][randomNumber];

				if (card.getNumber() == 1) {

					char cardInput;
					cout << "Do you want to count the Ace as either 1 or 11? Enter y for 11, enter n for no: ";
					cin >> cardInput;

					if (cardInput == 'y') {

						card.setNumber(11);

					}

				}

				currentHand.push_back(card);

				card_total += card.getNumber();

				card.displayCardInfo();

				arr[randomSuit][randomNumber].setState(true);

				counter++;

			}

		}

		cout << "Your current total is: " << getCard_total() << endl;

		if (currentHand[0].getNumber() == currentHand[1].getNumber()) {

			char choice;
			cout << "You have drawn two cards of the same value. Do you want to split? y for yes, n for no: ";
			cin >> choice;

			if (choice == 'y' || choice == 'Y') {

				splitHands[0].push_back(currentHand[0]);
				splitHands[1].push_back(currentHand[1]);

				splitHandTotal1 += splitHands[0][0].getNumber();
				splitHandTotal2 += splitHands[1][0].getNumber();

				int c = 0;
				
				while (c < 2) {

					srand(time(NULL));

					int randomSuit = rand() % 4;
					int randomNumber = rand() % 13;

					if (arr[randomSuit][randomNumber].getState() == false) {

						CardClass card = arr[randomSuit][randomNumber];

						if (card.getNumber() == 1) {

							char cardInput;
							cout << "Do you want to count the Ace as either 1 or 11? Enter y for 11, enter n for no: ";
							cin >> cardInput;

							if (cardInput == 'y') {

								card.setNumber(11);

							}

						}

						splitHands[c].push_back(card);
						card.displayCardInfo();
						arr[randomSuit][randomNumber].setState(true);

						c++;

					}

				}

				checkSplit = true;
				splitHandTotal1 += splitHands[0][1].getNumber();
				splitHandTotal2 += splitHands[1][1].getNumber();

				cout << "Your current total for hand 1 is: " << splitHandTotal1 << endl;
				cout << "Your current total for hand 2 is: " << splitHandTotal2 << endl;

			}
		}

	}

	void addCard(CardClass arr[][13]) {

		bool cardDrawn = false;

		while (cardDrawn == false) {

			srand(time(NULL));

			int randomSuit = rand() % 4;
			int randomNumber = rand() % 13;

			if (arr[randomSuit][randomNumber].getState() == false) {

				CardClass card = arr[randomSuit][randomNumber];

				if (card.getNumber() == 1) {

					char cardInput;
					cout << "Do you want to count the Ace as either 1 or 11? Enter y for 11, enter n for no: ";
					cin >> cardInput;

					if (cardInput == 'y') {

						card.setNumber(11);

					}

				}

				currentHand.push_back(card);

				card_total += card.getNumber();
				arr[randomSuit][randomNumber].setState(true);

				card.displayCardInfo();

				cardDrawn = true;

			}
		}

		cout << "Your current total is: " << getCard_total() << endl;

	}

	void addToSplit(CardClass arr[][13], const int pos) {

		bool cardDrawn = false;

		while (cardDrawn == false) {

			srand(time(NULL));

			int randomSuit = rand() % 4;
			int randomNumber = rand() % 13;

			if (arr[randomSuit][randomNumber].getState() == false) {

				CardClass card = arr[randomSuit][randomNumber];

				if (card.getNumber() == 1) {

					char cardInput;
					cout << "Do you want to count the Ace as either 1 or 11? Enter y for 11, enter n for no: ";
					cin >> cardInput;

					if (cardInput == 'y') {

						card.setNumber(11);

					}

				}

				splitHands[pos].push_back(card);

				card_total += card.getNumber();
				arr[randomSuit][randomNumber].setState(true);

				card.displayCardInfo();

				cardDrawn = true;

			}
		}

	}

	void clearHand() {

		currentHand.clear();

		if (splitHands.empty() == false) {

			splitHands[0].clear();
			splitHands[1].clear();

		}

		card_total = 0;

	}
};