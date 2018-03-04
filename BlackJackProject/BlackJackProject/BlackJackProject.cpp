// BlackJackProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FunctionMain.cpp"
#include "CardClass.h"
#include <iostream>
#include <vector>
#include "PlayerClass.h"
using namespace std;

//Const integers for number of cards per suit, and number of suits
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

		//Program sets up the deck of cards
		CardClass DeckObject[numSuits][numCardsPerSuit];
		SetupDeck(DeckObject);

		cout << "--------------------------------------------------" << endl;

		//Program creates a new hand for the player and draws two cards from the deck object
		PlayerClass user = PlayerClass::PlayerClass();
		user.initializeHand(DeckObject);

		//Program sets up the dealer's hand
		PlayerClass dealer = PlayerClass::PlayerClass();
		dealer.initializeDealerHand(DeckObject);

		cout << "--------------------------------------------------" << endl;

		//If the user total is equal to the dealer's total
		if (user.getCard_total() == 21 && dealer.getCard_total() == 21) {

			//Display that it is a tie
			cout << "Tie game! Both the player and dealer have Blackjack!" << endl;
			playerTurn = false;
			aiTurn = false;

		}

		//If the user has 21, and the dealer total is less than 21
		if (user.getCard_total() == 21 && dealer.getCard_total() < user.getCard_total()) {

			//Program displays that you have a Blackjack, and that you have won
			cout << "Blackjack! You have won!" << endl;
			playerTurn = false;
			aiTurn = false;
			
		}

		//If the dealer has a Blackjack, and you have less than 21
		if (dealer.getCard_total() == 21 && user.getCard_total() < dealer.getCard_total()) {

			//Program displays that the dealer has won
			cout << "The dealer has a Blackjack! You lost." << endl;
			playerTurn = false;
			aiTurn = false;

		}
		else {

			//Program displays the dealer's current total
			cout << "Current Dealer Total: " << dealer.getCard_total() << endl;

		}

		//While loop to control the player turn for if splitting was not chosen
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
				aiTurn = false;

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
		//Program logic for if the user has chosen to split their deck
		while (playerTurn == true && user.getCheckSplit() == true) {

			//If split is true
			if (user.getCheckSplit() == true) {

				//Set the bet for the second deck equal to the first bet
				int bet2 = chipsToBet;

				//If the user total for hand 1 or hand 2 is less than or equal to 21
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

						//Program prompts the user for which deck they want to add the card to
						int choice;
						cout << "Enter 1 to add a card to hand 1, or enter two to add a card to hand 2: ";
						cin >> choice;

						//If statements to control what deck the card is added to
						if (choice == 1 && user.getSplitHandTotal1() < maxCardValue) {

							//Program adds the card to the deck
							user.addToSplit(DeckObject, choice);

							if (user.getSplitHandTotal1() > maxCardValue && user.getSplitHandTotal2() > maxCardValue) {

								playerTurn = false;

							}

						}
						else if (choice == 2 && user.getSplitHandTotal2() < maxCardValue) {

							//Program adds the card to the deck
							user.addToSplit(DeckObject, choice);

							if (user.getSplitHandTotal1() > maxCardValue && user.getSplitHandTotal2() > maxCardValue) {

								playerTurn = false;

							}

						}
						else {

							/*
								Program displays an error for if the user input is invalid, or if the user
								has tried to add a card to a deck that has already reached 21
							*/
							cout << "Error, that is not a valid hand, or hand is at 21 already" << endl;

						}

					}
					else if (playerChoice == 2) {

						//Program displays that you have ended your turn
						cout << "You have ended your turn" << endl;
						playerTurn = false;

					}
					else if (playerChoice == 3) {

						//Program prompts the user for which hand they want to add it to
						int choice;
						cout << "Enter 1 to add a card to hand 1, or enter two to add a card to hand 2: ";
						cin >> choice;

						//Logic for deciding what hand to add the card to
						if (choice == 1 && user.getSplitHandTotal1() < maxCardValue) {

							//Program adds a card to the split hand, doubles the bet, and ends the turn
							user.addToSplit(DeckObject, choice);
							chipsToBet *= 2;
							playerTurn = false;

						}
						else if (choice == 2 && user.getSplitHandTotal2() < maxCardValue) {

							//Program adds a card to the split hand, doubles the bet, and ends the turn
							user.addToSplit(DeckObject, choice);
							bet2 *= 2;
							playerTurn = false;

						}
						else {

							/*
								Program displays an error for if the user input is invalid, or if the user
								has tried to add a card to a deck that has already reached 21
							*/
							cout << "Error, that is not a valid hand, or hand is at 21 already" << endl;

						}

					}
					else if (playerChoice == 4) {

						//Program ends the game
						gameContinue = false;
						playerTurn = false;
						aiTurn = false;

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

		}
		
		/*
		Ai Does it's logic here and figures out a winner for the round
		*/
		//Logic to perform if the user has not split their deck
		while (aiTurn == true && user.getCheckSplit() == false) {

			//If the dealer total is less than 17
			if (dealer.getCard_total() < 17) {

				//Dealer draws a new card
				dealer.addDealerCard(DeckObject);

			}

			//If the dealer total is greater than or equal to 17, and less than 21, and the user total is less than or equal to 21
			if (dealer.getCard_total() >= 17 && dealer.getCard_total() <= 21 && user.getCard_total() <= 21) {

				//Program displays the dealer's total
				cout << "The dealer's total is: " << dealer.getCard_total() << endl;

				//If the user total is greater than the dealer's total
				if (user.getCard_total() > dealer.getCard_total()) {

					//Display that you have won
					cout << "You have won!" << endl;
					aiTurn = false;

				}

				//If the user total is less than the dealer total
				if (user.getCard_total() < dealer.getCard_total()) {

					//Display that you have lost
					cout << "You have lost." << endl;
					aiTurn = false;

				}

				//If the user total is equal to the dealer total
				if (user.getCard_total() == dealer.getCard_total()) {

					//Display that it is a tie
					cout << "It is a tie!" << endl;
					aiTurn = false;

				}
			}

			//If the dealer total is greater than 21 and the user total is greater than 21
			if (dealer.getCard_total() > 21 && user.getCard_total() > 21) {

				//Program displays the dealer total, and calculates how close the player and ai are to 21
				cout << "The dealer's total is: " << dealer.getCard_total() << endl;
				int playerCardTotal = user.getCard_total() - 21;
				int dealerCardTotal = dealer.getCard_total() - 21;

				//If the player is closer to 21
				if (playerCardTotal < dealerCardTotal) {

					//Display that the player has won
					cout << "You have won!" << endl;
					aiTurn = false;

				}

				//If the dealer is closer to 21
				if (dealerCardTotal < playerCardTotal) {

					//Display that the player has lost
					cout << "You have lost." << endl;
					aiTurn = false;

				}

				//If the player total and the dealer total are equal
				if (playerCardTotal == dealerCardTotal) {

					//Display that it is a tie
					cout << "It is a tie!" << endl;
					aiTurn = false;

				}

			}

			//If the user total is greater than 21, and the dealer total is less than or equal to 21
			if (user.getCard_total() > 21 && dealer.getCard_total() <= 21) {

				//Display the dealer total, and display that the player has lost
				cout << "The dealer's total is: " << dealer.getCard_total() << endl;
				cout << "You have lost." << endl;
				aiTurn = false;

			}

			//If the dealer total is greater than 21, and the user total is less than or equal to 21
			if (dealer.getCard_total() > 21 && user.getCard_total() <= 21) {

				//Display the dealer total, and display that the player has won
				cout << "The dealer's total is: " << dealer.getCard_total() << endl;
				cout << "You have won!" << endl;
				aiTurn = false;

			}
		}

		/*
			This section is for the logic of if the player has split their hand
		*/
		//While it is the ai turn, and the player has split their hand
		while (aiTurn == true && user.getCheckSplit() == true) {

			//If the dealer total is less than 17
			if (dealer.getCard_total() < 17) {

				//Add a card to the dealer's hand
				dealer.addDealerCard(DeckObject);

			}

			//If the dealer total is greater than or equal to 17 and less than or equal to 21, and the hand 1 total is less than or equal to 21
			if (dealer.getCard_total() >= 17 && dealer.getCard_total() <= 21 && user.getSplitHandTotal1() <= 21) {

				//Program displays the dealer's total
				cout << "The dealer's total is: " << dealer.getCard_total() << endl;

				//If the hand 1 total is greater than the dealer total
				if (user.getSplitHandTotal1() > dealer.getCard_total()) {

					//Program displays that the hand 1 has won
					cout << "Hand 1 has won!" << endl;
					aiTurn = false;

				}

				//If the hand 1 total is less than the dealer's total
				if (user.getSplitHandTotal1() < dealer.getCard_total()) {

					//Program displays that hand 1 has lost
					cout << "Hand 1 has lost." << endl;
					aiTurn = false;

				}

				//If the hand 1 total is equal to the dealer total
				if (user.getSplitHandTotal1() == dealer.getCard_total()) {

					//Program displays that the hand 1 has tied with the dealer
					cout << "Hand 1 has tied with the dealer!" << endl;
					aiTurn = false;

				}

			}

			//If the dealer total is greater than or equal to 17 and less than or equal to 21, and the hand 2 total is less than or equal to 21
			if (dealer.getCard_total() >= 17 && dealer.getCard_total() <= 21 && user.getSplitHandTotal2() <= 21) {

				//If the hand 2 total is greater than the dealer total
				if (user.getSplitHandTotal2() > dealer.getCard_total()) {
					
					//Display that hand 2 has won
					cout << "Hand 2 has won!" << endl;
					aiTurn = false;

				}

				//If the hand 2 total is less than the dealer total
				if (user.getSplitHandTotal2() < dealer.getCard_total()) {

					//Display that hand 2 has lost
					cout << "Hand 2 has lost." << endl;
					aiTurn = false;

				}

				//If hand 2 total is equal to the dealer total
				if (user.getSplitHandTotal2() == dealer.getCard_total()) {

					//Program displays that hand 2 has tied with the dealer
					cout << "Hand 2 has tied with the dealer!" << endl;
					aiTurn = false;

				}

			}

			//If the dealer total is greater than 21 and the hand 1 total is greater than 21
			if (dealer.getCard_total() > 21 && user.getSplitHandTotal1() > 21) {

				//Program displays the dealer total, and calculates how close the hands are to 21
				cout << "The dealer's total is: " << dealer.getCard_total() << endl;
				int playerCardTotal = user.getSplitHandTotal1() - 21;
				int dealerCardTotal = dealer.getCard_total() - 21;

				//If the player is closer to 21
				if (playerCardTotal < dealerCardTotal) {

					//Program displays that hand 1 has won
					cout << "Hand 1 has won!" << endl;
					aiTurn = false;

				}

				//If the dealer is closer to 21
				if (dealerCardTotal < playerCardTotal) {

					//Program displays that hand 1 has lost
					cout << "Hand 1 has lost." << endl;
					aiTurn = false;

				}

				//If the player hand is equal to the dealer hand
				if (playerCardTotal == dealerCardTotal) {

					//Program displays that it is a tie
					cout << "Hand 1 has tied with the dealer!" << endl;
					aiTurn = false;

				}

			}

			//If the dealer total is greater than 21 and the hand 2 total is greater than 21
			if (dealer.getCard_total() > 21 && user.getSplitHandTotal2() > 21) {

				//Program calculates how close each hand is to 21
				int playerCardTotal = user.getSplitHandTotal2() - 21;
				int dealerCardTotal = dealer.getCard_total() - 21;

				//If the player is closer to 21
				if (playerCardTotal < dealerCardTotal) {

					//Display that hand 2 has won
					cout << "Hand 2 has won!" << endl;
					aiTurn = false;

				}

				//If the dealer is closer to 21
				if (dealerCardTotal < playerCardTotal) {

					//Display that hand 2 has lost
					cout << "Hand 2 has lost." << endl;
					aiTurn = false;

				}

				//If hand 2 is equal to the dealer
				if (playerCardTotal == dealerCardTotal) {

					//Program displays that it is a tie
					cout << "Hand 2 has tied with the dealer!" << endl;
					aiTurn = false;

				}

			}

			//If the hand 1 total is greater than 21 and the dealer total is less than or equal to 21
			if (user.getSplitHandTotal1() > 21 && dealer.getCard_total() <= 21) {

				//Display the dealer total, and that hand 1 has lost
				cout << "The dealer's total is: " << dealer.getCard_total() << endl;
				cout << "Hand 1 has lost." << endl;
				aiTurn = false;

			}

			//If the dealer total is greater than 21 and the hand 1 total is greater than or equal to 21
			if (dealer.getCard_total() > 21 && user.getSplitHandTotal1() <= 21) {

				//Display the dealer total, and that hand 1 has won
				cout << "The dealer's total is: " << dealer.getCard_total() << endl;
				cout << "Hand 1 has won!" << endl;
				aiTurn = false;

			}

			//If the user total is greater than 21, and the dealer total is less than or equal to 21
			if (user.getSplitHandTotal2() > 21 && dealer.getCard_total() <= 21) {

				//Display that hand 2 has lost
				cout << "Hand 2 has lost." << endl;
				aiTurn = false;

			}

			//If the dealer total is greater than 21, and the user total is less than or equal to 21
			if (dealer.getCard_total() > 21 && user.getSplitHandTotal2() <= 21) {

				//Display that hand 2 has won
				cout << "Hand 2 has won!" << endl;
				aiTurn = false;

			}
			
		}

		//Program prompts the user for if they want to play another game
		cout << "--------------------------------------------------" << endl;
		cout << "Do you wish to play again? Enter y for yes or n for no: ";
		char playerContinue;
		cin >> playerContinue;

		//If the player chooses not to play again
		if (playerContinue == 'n' || playerContinue == 'N') {

			//Set gameContinue to false
			gameContinue = false;

		}
		else {

			//Program resets the values
			gameContinue = true;
			playerTurn = true;
			aiTurn = true;
			user.clearHand();
			dealer.clearHand();
			cout << "--------------------------------------------------" << endl;

		}
	}

	return 0;
}

