#include "stdafx.h"
#include "CardClass.h"
#include "DeckClass.h"
#include <iostream>
#include <string>
using namespace std;

CardClass *SetupDeck() {
	static CardClass arr[4][13];
	static string numberToSuit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	static string numberToName[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	for (int counterOne = 0; counterOne < 4; counterOne++) {
		for (int counterTwo = 0; counterTwo < 13; counterTwo++) {
			arr[counterOne][counterTwo]::setSuit(counterOne);
			arr[counterOne][counterTwo]::setNumber(counterTwo);
			arr[counterOne][counterTwo]::setState(false);
		}
	}

	return arr;
}