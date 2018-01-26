//I've set this file up so we can keep our driver file relatively clean. We can throw most/any relevant functions
//in this file here and call them in the driver file as needed. This file should be properly #include'd

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
			//I've forgotten the proper syntax for this
			arr[counterOne][counterTwo]:setSuit(counterOne);
			arr[counterOne][counterTwo]:setNumber(counterTwo);
			arr[counterOne][counterTwo]:setState(false);
		}
	}

	return arr; //I don't know why this is erroring
}