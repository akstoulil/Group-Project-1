#include "stdafx.h"
#include "CardClass.h"
#include "Hand.h"
#include "stdlib.h"
#include "FunctionMain.cpp"
#include <vector>

//this constructor will create a vector of  empty card objects
Hand::Hand() : handVec()
{

}

//method to add a card to your hand
void Hand::AddCard(CardClass deck[][]) 
{
	//create a random set of "coordinates" to select suit and number of the card in the matrix: DeckObject created in main
	int randomCardX = rand() % 4;
	int randomCardY = rand() % 13;

	//draws a card from the deck  using the coord. above, by filling the vector
	handVec.push_back(deck[randomCardX][randomCardY]);

	int exit = 0; // variable to exit my loop
	int vectorPosition = handVec.size() - 1; //used to make sure I'm changing the right card in my loop

	//loop to check to see if the card has been drawn
	while (exit == 0)
	{
		//if card hasn't been picked before, set the deck's equivalent card's state to true
		if (handVec[vectorPosition].getState == false)
		{
			deck[randomCardX][randomCardY].setState(true);
			exit = 1;
		}
		//otherwise pick another card from the deck
		else
		{
			//two new random coordinates
			randomCardX = rand() % 4;
			randomCardY = rand() % 13;

			//replace the card
			handVec[vectorPosition] = deck[randomCardX][randomCardY];
		}
	}

	//print to user what they drew
	cout << "You have drawn the " << handVec[vectorPosition].getNumber() << " of " << handVec[vectorPosition].getSuit() << "." << endl;

	//check to see if user has busted
	if (checkBust(handVec) == true)
	{
		//we need to add chip loss/delete hand RIGHT HERE ***********
		cout << "You have busted, the chips go to the dealer." << endl;
	}
	
}

// method to add two initial cards to hand
void Hand::DrawTwo(CardClass deck[][])
{
	//create 2 random "coordinates" to select suit and number of the cards in the matrix: DeckObject created in main
	int randomCardX1 = rand() % 4;
	int randomCardY1 = rand() % 13;

	int randomCardX2 = rand() % 4;
	int randomCardY2 = rand() % 13;

	
	//draws the initial 2 cards using the coord. created above, by filling the vector
	handVec.push_back(deck[randomCardX1][randomCardY1]);
	handVec.push_back(deck[randomCardX2][randomCardY2]);

	int exit = 0; // variable to be changed to escape loop

	//while loop responsible for reiterating until both cards are both confirmed not to be previously drawn
	while (exit == 0)
	{
		//if both cards are not picked, set their set state to true, and exit loop
		if (handVec[0].getState == false && handVec[1].getState == false)
		{
			deck[randomCardX1][randomCardY1].setState(true);
			deck[randomCardX2][randomCardY2].setState(true);
			exit = 1;
		}
		//card 1 has been previously drawn, but not card 2
		else if (handVec[0].getState == true && handVec[1].getState == false)
		{
			//get two new random coordinates
			randomCardX1 = rand() % 4;
			randomCardY1 = rand() % 13;

			//grab the values from selected card, and assign them to the first card
			handVec[0] = deck[randomCardX1][randomCardY1];
		}
		//card 1 hasn't been previously drawn, but 2 has
		else if (handVec[0].getState == false && handVec[1].getState == true)
		{
			//get two new random coordinates
			randomCardX2 = rand() % 4;
			randomCardY2 = rand() % 13;

			//grab the values from selected card, and assign them to the second card
			handVec[1] = deck[randomCardX2][randomCardY2];
		}
		//else will either be both cards, have been previously drawn, or something went wrong
		//either way, redraw both cards
		else
		{
			//get two new random coordinates for use in card1
			randomCardX1 = rand() % 4;
			randomCardY1 = rand() % 13;

			//grab the values from selected card, and assign them to card1
			handVec[0] = deck[randomCardX1][randomCardY1];

			//get two new random coordinates for use in card2
			randomCardX2 = rand() % 4;
			randomCardY2 = rand() % 13;

			//grab the values from selected card, and assign them to card2
			handVec[1] = deck[randomCardX2][randomCardY2];
		}

		//now that we have two unique cards, lets print out to the user, what they drew
		cout << "You have drawn the " << handVec[0].getNumber() << " of " << handVec[0].getSuit() << " and the " << handVec[1].getNumber() << " of " << handVec[1].getSuit() << "." << endl;
	}
}

//function to check whether the user busted after drawing
bool Hand::checkBust(vector<CardClass>& v)
{
	int total = 0; //responsible for holding my running total
	const int BUST = 21;

	//grabbing all the number values of each card in the vector
	for (int i = 0; i < v.size(); i++)
	{
		total += v[i].getNumber;
	}

	//if else block returning true if busted, and false if not
	if (total > BUST)
	{
		//will need to have the player lose chips here, and also continue on
		return true;
	}
	else
	{
		return false;
	}
}
