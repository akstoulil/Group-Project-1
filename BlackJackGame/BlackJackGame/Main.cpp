// BlackJack Game runner file
// This program allows one person to play Blackjack, alone, against a dealer and a few other program-ran opponents
// Github repo: https://github.com/akstoulil/Group-Project-1
// Written by: Logan Christianson, Austin Stoulil<everyone insert your names here>

#include "stdafx.h"
#include "FunctionMain.cpp"
#include <iostream>
#include "Hand.h";
#include "Hand.cpp";

using namespace std;

int main() {
	cout << "Welcome to the game of Blackjack!" << endl;

	//*DeckObject is a pointer to the game's CardClass Array (i.e. the deck) that's returned from the SetupDeck() function
	//That's in the FunctionMain.cpp file
	CardClass *DeckObject = SetupDeck();

	//Variables to store the player's choice, number of chips, and continue information
	int playerChoice;
	int numberOfChips;
	bool gameContinue = true;

	//Program creates a new hand for the player and draws two cards from the deck object
	Hand playerHand();
	DeckObject.drawTwo(playerHand);

	//Program prompts the user for the starting amount of chips they are entering with
	cout << "Please enter the amount of starting chips you want to have: ";
	cin >> numberOfChips;

	//While loop checks to make sure that the number of chips entered is greater than zero
	while (numberOfChips <= 0) {

		//Program displays an error message and prompts for a new value
		cout << "Error, starting bet must be at least greater than zero. Please enter a new number: ";
		cin >> numberOfChips;

	}

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
			playerHand.addCard();

		}
		else if (playerChoice == 2) {

			//Program displays that you have ended your turn
			cout << "You have ended your turn" << endl;

		}
		else if (playerChoice == 3) {

			//Program calls the method to double down
			playerHand.doubleDown();

		}
		else if (playerChoice == 4) {

			//Program ends the game
			gameContinue = false;

		}
		else {

			//While loop checks to see if the player has entered the correct input
			while (playerChoice != 1 || playerChoice != 2 || playerChoice != 3 || playerChoice != 4) {

				//Program displays an error message and prompts the user to enter a new input option
				cout << "Error, the choice entered was not on the available list. Please enter a new choice: ";
				cin >> playerChoice;

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
	}

	return 0;
}
