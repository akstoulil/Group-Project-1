#pragma once

using namespace std;
class Hand
{
	private:
		vector<CardClass> handVec;
	public:
		Hand();
		void AddCard(CardClass deck[][]);
		void DrawTwo(CardClass deck[][]);
		bool checkBust(vector<CardClass> & v);
};

