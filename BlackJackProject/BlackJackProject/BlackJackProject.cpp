// BlackJackProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FunctionMain.cpp"
#include "CardClass.h"
#include <iostream>
#include <vector>
#include "Hand.h"
#include "Hand.cpp"
#include "PlayerClass.h"
using namespace std;

const int numCardsPerSuit = 13;
const int numSuits = 4;

int main()
{
	cout << "Welcome to the game of Blackjack!" << endl;

	//*DeckObject is a pointer to the game's CardClass Array (i.e. the deck) that's returned from the SetupDeck() function
	//That's in the FunctionMain.cpp file

	//Variables to store the player's choice and other information
	int playerChoice;
	int maxCardValue = 21;
	bool gameContinue = true;
	bool playerTurn = true;
	bool aiTurn = true;

	//While loop checks to make sure that the user wants to continue playing
	while (gameContinue == true) {

		int chipsToBet;

		//Program prompts the user to enter the amount of chips they wish to bet
		cout << "Please enter the amount of chips you wish to bet: ";
		cin >> chipsToBet;

		//While loop checks to make sure that the user has entered a valid amount for chipsToBet
		while (chipsToBet <= 0) {

			//Program displays an error message and prompts the user for a new value
			cout << "Error, chips to bet must be greater than zero. Please enter again: ";
			cin >> chipsToBet;

		}

		CardClass DeckObject[numSuits][numCardsPerSuit];
		SetupDeck(DeckObject);

		//Program creates a new hand for the player and draws two cards from the deck object
		PlayerClass user = PlayerClass::PlayerClass();
		user.initializeHand(DeckObject);

		while (playerTurn == true && user.getCard_total() <= maxCardValue && user.getCheckSplit() == false) {

			//Program displays the available options to choose from
			cout << "--------------------------------------------------" << endl;
			cout << "Please choose what action you would like to take: " << endl;
			cout << "Enter 1 to Hit" << endl;
			cout << "Enter 2 to Stand" << endl;
			cout << "Enter 3 to Double Down" << endl;
			cout << "Enter 4 to Surrender" << endl;
			cin >> playerChoice;

			//If statements to determine what choice the player has made
			if (playerChoice == 1) {

				//Program calls the method to add a card to the player hand
				user.addCard(DeckObject);
				cout << "\n";

			}
			else if (playerChoice == 2) {

				//Program displays that you have ended your turn
				cout << "You have ended your turn" << endl;
				playerTurn = false;

			}
			else if (playerChoice == 3) {

				//Program calls the method to double down
				//playerHand.doubleDown();
				chipsToBet *= 2;
				user.addCard(DeckObject);
				playerTurn = false;

			}
			else if (playerChoice == 4) {

				//Program ends the game
				gameContinue = false;
				playerTurn = false;

			}
			else {

				//While loop checks to see if the player has entered the correct input
				while (playerChoice != 1 || playerChoice != 2 || playerChoice != 3 || playerChoice != 4) {

					//Program displays an error message and prompts the user to enter a new input option
					cout << "Error, the choice entered was not on the available list. Please enter a new choice: ";
					cin >> playerChoice;

				}

			}
		}

		/*
			This section of code controls the player logic for if the player has chosen to
			split their deck.
		*/
		if (user.getCheckSplit() == true) {

			int bet2 = chipsToBet;

			if (user.getSplitHandTotal1() <= maxCardValue || user.getSplitHandTotal2() <= maxCardValue) {

				//Program displays the available options to choose from
				cout << "--------------------------------------------------" << endl;
				cout << "Please choose what action you would like to take: " << endl;
				cout << "Enter 1 to Hit" << endl;
				cout << "Enter 2 to Stand" << endl;
				cout << "Enter 3 to Double Down" << endl;
				cout << "Enter 4 to Surrender" << endl;
				cin >> playerChoice;

				//If statements to determine what choice the player has made
				if (playerChoice == 1) {

					int choice;
					cout << "Enter 1 to add a card to hand 1, or enter two to add a card to hand 2: ";
					cin >> choice;

					if (choice == 1 && user.getSplitHandTotal1() <= maxCardValue) {

						user.addToSplit(DeckObject, choice);

					}
					else if (choice == 2 && user.getSplitHandTotal2() <= maxCardValue) {

						user.addToSplit(DeckObject, choice);

					}
					else {

						cout << "Error, that is not a valid hand" << endl;

					}

				}
				else if (playerChoice == 2) {

					//Program displays that you have ended your turn
					cout << "You have ended your turn" << endl;
					playerTurn = false;

				}
				else if (playerChoice == 3) {

					//Program calls the method to double down
					int choice;
					cout << "Enter 1 to add a card to hand 1, or enter two to add a card to hand 2: ";
					cin >> choice;

					if (choice == 1 && user.getSplitHandTotal1() <= maxCardValue) {

						user.addToSplit(DeckObject, choice);
						chipsToBet *= 2;
						playerTurn = false;

					}
					else if (choice == 2 && user.getSplitHandTotal2() <= maxCardValue) {

						user.addToSplit(DeckObject, choice);
						bet2 *= 2;
						playerTurn = false;

					}
					else {

						cout << "Error, that is not a valid hand" << endl;

					}

				}
				else if (playerChoice == 4) {

					//Program ends the game
					gameContinue = false;
					playerTurn = false;

				}
				else {

					//While loop checks to see if the player has entered the correct input
					while (playerChoice != 1 || playerChoice != 2 || playerChoice != 3 || playerChoice != 4) {

						//Program displays an error message and prompts the user to enter a new input option
						cout << "Error, the choice entered was not on the available list. Please enter a new choice: ";
						cin >> playerChoice;

					}

				}

			}

		}
		/*
		Ai Does it's logic here and figures out a winner for the round
		*/

		//Program prompts the user for if they want to play another game
		cout << "Do you wish to play again? Enter y for yes or n for no: ";
		char playerContinue;
		cin >> playerContinue;

		//If the player chooses not to play again
		if (playerContinue == 'n' || playerContinue == 'N') {

			//Set gameContinue to false
			gameContinue = false;

		}
		else {

			gameContinue = true;
			playerTurn = true;
			user.clearHand();
			
		}
	}

	return 0;
}

