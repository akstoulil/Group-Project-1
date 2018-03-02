#pragma once
#include "CardClass.h"
#include <vector>
#include <random>
#include <iostream>
#include <time.h>

class PlayerClass
{
protected:
	int card_total;
	int splitHandTotal1;
	int splitHandTotal2;
	bool checkSplit;
	vector<CardClass> currentHand;
	vector<vector<CardClass>> splitHands;

public:

	PlayerClass() {

		card_total = 0;
		checkSplit = false;
		vector<CardClass> sHand1;
		vector<CardClass> sHand2;
		splitHands.push_back(sHand1);
		splitHands.push_back(sHand2);

	}

	int setCard_total(int t)
	{
		card_total = t;
	}

	int getCard_total() const
	{
		return card_total;
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

	//Method to draw the first two cards
	void initializeHand(CardClass arr[][13]) {

		//Loop counter
		int counter = 0;

		while (counter < 2) {

			//Generating a random number to pick a card from
			srand(time(NULL));

			int randomSuit = rand() % 4;
			int randomNumber = rand() % 13;

			//If the card hasn't already been drawn
			if (arr[randomSuit][randomNumber].getState() == false) {

				//Get the card
				CardClass card = arr[randomSuit][randomNumber];

				//If the card is an ace
				if (card.getNumber() == 1) {

					//Program prompts the user for if they want to count it as either 1 or 11
					char cardInput;
					cout << "Do you want to count the Ace as either 1 or 11? Enter y for 11, enter n for no: ";
					cin >> cardInput;

					//If yes
					if (cardInput == 'y') {

						//Set the value to 11
						card.setNumber(11);

					}

				}

				//Push back the card, add to the total, display the card info, set the drawn state to true, and increment the counter
				currentHand.push_back(card);

				card_total += card.getNumber();

				card.displayCardInfo();

				arr[randomSuit][randomNumber].setState(true);

				counter++;

			}

		}

		//Display the current total
		cout << "Your current total is: " << getCard_total() << endl;

		//If the two card values are the same
		if (currentHand[0].getNumber() == currentHand[1].getNumber()) {

			//Program asks the user for if they want to split their hand
			char choice;
			cout << "You have drawn two cards of the same value. Do you want to split? y for yes, n for no: ";
			cin >> choice;

			//If yes
			if (choice == 'y' || choice == 'Y') {

				//Push back the two cards to the two hands
				splitHands[0].push_back(currentHand[0]);
				splitHands[1].push_back(currentHand[1]);

				//Add the card values to the hand totals
				splitHandTotal1 += splitHands[0][0].getNumber();
				splitHandTotal2 += splitHands[1][0].getNumber();

				//Counter
				int c = 0;
				
				while (c < 2) {

					//Program generates a random number for the cards
					srand(time(NULL));

					int randomSuit = rand() % 4;
					int randomNumber = rand() % 13;

					//If the card hasn't been drawn
					if (arr[randomSuit][randomNumber].getState() == false) {

						//Get the card
						CardClass card = arr[randomSuit][randomNumber];

						//If the card is an ace
						if (card.getNumber() == 1) {

							//Program prompts the user for if they want to count it as 1 or 11
							char cardInput;
							cout << "Do you want to count the Ace as either 1 or 11? Enter y for 11, enter n for no: ";
							cin >> cardInput;

							//If yes
							if (cardInput == 'y') {

								//Set the value to 11
								card.setNumber(11);

							}

						}

						//Push back the card, display the card, set the card to drawn, and increment the counter
						splitHands[c].push_back(card);
						card.displayCardInfo();
						arr[randomSuit][randomNumber].setState(true);

						c++;

					}

				}

				//Set checkSplit to true and add to the split totals
				checkSplit = true;
				splitHandTotal1 += splitHands[0][1].getNumber();
				splitHandTotal2 += splitHands[1][1].getNumber();

				//Program displays the current totals in each hand
				cout << "Your current total for hand 1 is: " << splitHandTotal1 << endl;
				cout << "Your current total for hand 2 is: " << splitHandTotal2 << endl;

			}
		}

	}

	//Method to add cards to a hand
	void addCard(CardClass arr[][13]) {

		//Controller for the while loop
		bool cardDrawn = false;

		while (cardDrawn == false) {

			//Program generates a random number
			srand(time(NULL));

			int randomSuit = rand() % 4;
			int randomNumber = rand() % 13;

			//If the card has not been drawn
			if (arr[randomSuit][randomNumber].getState() == false) {

				//Get the card
				CardClass card = arr[randomSuit][randomNumber];

				//If the card is an ace
				if (card.getNumber() == 1) {

					//Program prompts the user for if they want to count it as 1 or 11
					char cardInput;
					cout << "Do you want to count the Ace as either 1 or 11? Enter y for 11, enter n for no: ";
					cin >> cardInput;

					//If yes
					if (cardInput == 'y') {

						//Set the value to 11
						card.setNumber(11);

					}

				}

				//Push back the card, add to the total, display the card info, set the drawn state to true, and end the loop
				currentHand.push_back(card);

				card_total += card.getNumber();
				arr[randomSuit][randomNumber].setState(true);

				card.displayCardInfo();

				cardDrawn = true;

			}
		}

		//Display the current total
		cout << "Your current total is: " << getCard_total() << endl;

	}

	//Method to add cards to a split hand
	void addToSplit(CardClass arr[][13], const int pos) {

		//Controller for the while loop
		bool cardDrawn = false;

		while (cardDrawn == false) {

			//Program generates a random number
			srand(time(NULL));

			int randomSuit = rand() % 4;
			int randomNumber = rand() % 13;

			//If the card hasn't been drawn
			if (arr[randomSuit][randomNumber].getState() == false) {

				//Get the card
				CardClass card = arr[randomSuit][randomNumber];

				//If the card is an ace
				if (card.getNumber() == 1) {

					//Program prompts the user for if they want to count it as a 1 or 11
					char cardInput;
					cout << "Do you want to count the Ace as either 1 or 11? Enter y for 11, enter n for no: ";
					cin >> cardInput;

					//If yes
					if (cardInput == 'y') {

						//Set the value to 11
						card.setNumber(11);

					}

				}

				//Push back the card, add to the total, display the card info, set the drawn state to true, and end the loop
				splitHands[pos].push_back(card);

				card_total += card.getNumber();
				arr[randomSuit][randomNumber].setState(true);

				card.displayCardInfo();

				cardDrawn = true;

			}
		}

	}

	//This method initializes the dealer hand
	void initializeDealerHand(CardClass arr[][13]) {

		//Counter and variable to hold a running total
		int counter = 0;
		int currentTotal = 0;

		while (counter < 2) {

			//Program generates a random number
			srand(time(NULL));

			int randomSuit = rand() % 4;
			int randomNumber = rand() % 13;

			//If the card hasn't been drawn
			if (arr[randomSuit][randomNumber].getState() == false) {

				//Get the card
				CardClass card = arr[randomSuit][randomNumber];

				//If the card is an ace
				if (card.getNumber() == 1) {

					//If the current total plus the ace counted as an 11 is equal to 21
					if ((currentTotal + 11) == 21 || currentTotal <= 6) {

						//Set the value of the ace to 11
						card.setNumber(11);

					}
					else {

						//Set the value of the ace to 1
						card.setNumber(1);

					}

				}

				//Program pushes back the card
				currentHand.push_back(card);
				currentTotal += card.getNumber();

				//Display what the dealer has drawn
				cout << "The dealer has drawn the " << card.getNumberName() << " of " << card.getSuitName() << endl;

				//Add to the total, set the state to drawn, and increment the counter
				card_total += card.getNumber();

				arr[randomSuit][randomNumber].setState(true);

				counter++;

			}

		}

	}

	//This method adds a card to the dealer hand
	void addDealerCard(CardClass arr[][13]) {

		//Controller for the while loop
		bool cardDrawn = false;

		while (cardDrawn == false) {

			//Program generates a random number
			srand(time(NULL));

			int randomSuit = rand() % 4;
			int randomNumber = rand() % 13;

			//If the card hasn't been drawn
			if (arr[randomSuit][randomNumber].getState() == false) {

				//Get the card
				CardClass card = arr[randomSuit][randomNumber];

				//If the card is an ace
				if (card.getNumber() == 1) {

					//If the current total plus the ace as an 11 is equal to 21
					if ((card_total + 11) <= 21) {

						//Set the value to 11
						card.setNumber(11);

					}
					else {

						//Set the value to 1
						card.setNumber(1);

					}

				}

				//Push back the card, add to the total, set the state of the card, and end the loop
				currentHand.push_back(card);

				card_total += card.getNumber();
				arr[randomSuit][randomNumber].setState(true);

				//Program displays what the dealer has drawn
				cout << "The dealer has drawn the " << card.getNumberName() << " of " << card.getSuitName() << endl;

				cardDrawn = true;

			}
		}

	}

	//Method to clear out the hands
	void clearHand() {

		//Program clears the current non split hand
		currentHand.clear();

		//If the split hands are not empty
		if (splitHands.empty() == false) {

			//Clear out the items
			splitHands[0].clear();
			splitHands[1].clear();

		}

		//Set the total back to 0
		card_total = 0;
		splitHandTotal1 = 0;
		splitHandTotal2 = 0;

	}
};