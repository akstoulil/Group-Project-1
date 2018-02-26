#pragma once
#include <string>
#include <iostream>

using namespace std;

class CardClass {
	//Set up necessary variables, 
	//cardNumber is 0-13, ..., 10 = 9, Jack = 10, Queen = 11, King = 12, Ace = 0
	//cardSuit is  0-3, Hearts = 0, Diamonds = 1, Clubs = 2, Spades = 3
	//hasBeenDrawn will be used for identifying whether or not the card has been drawn already
private:
	int cardNumber;
	int cardSuit;
	bool hasBeenDrawn;
	string suitName;
	string numberName;

public:
	//Default Constructor
	CardClass() {
		cardNumber = 0, cardSuit = 0; hasBeenDrawn = false;
	}
	//Constructor with provided values
	CardClass(int newCardNumber, int newCardSuit, bool newDrawState) {
		cardNumber = newCardNumber;
		cardSuit = newCardSuit;
		hasBeenDrawn = newDrawState;
	}

	//Card number accessor and mutator
	int getNumber() {
		return cardNumber;
	}
	void setNumber(int newCardNumber) {
		cardNumber = newCardNumber;
	}

	//Card suit accessor and mutator
	int getSuit() {
		return cardSuit;
	}
	void setSuit(int newCardSuit) {
		cardSuit = newCardSuit;
	}

	//Card state accessor and mutator
	bool getState() {
		return hasBeenDrawn;
	}
	void setState(bool newDrawState) {
		hasBeenDrawn = newDrawState;
	}

	string getSuitName() {
		return suitName;
	}

	void setSuitName(string newSuitName) {
		suitName = newSuitName;
	}

	string getNumberName() {
		return numberName;
	}

	void setNumberName(string newNumberName) {
		numberName = newNumberName;
	}

	void displayCardInfo() {

		//static string numberToSuit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
		//static string numberToName[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

		cout << "You have drawn the " << getNumberName() << " of " << getSuitName() << endl;

	}
	void dealerCardInfo() {
		cout << "The dealer has drawn the " << getNumberName() << " of " << getSuitName() << endl;
	}
};

