#include <iostream>

using namespace std;

#include "Cards.h"

void main()
{
	Card	C1;
	Card	Deck[52];
	Card	Hands[NumPlayers][CardsInHand];
	int		i;
	int		j;
	int		k = 0;

	C1.Suit = Hearts;
	C1.Value = Eight;

	//	ShowCard (C1);

	InitDeck(Deck);

	Shuffle(Deck);

	for (i = 0; i < NumPlayers; i++) {
		for (j = 0; j < CardsInHand; j++) {
			Hands[i][j] = Deck[k];
			k++;
			Sort(Hands[i]);
		}
	}

	for (i = 0; i < NumPlayers; i++) {
		cout << "\nHand " << i + 1 << ": " << endl;
		for (j = 0; j < CardsInHand; j++) {
			ShowCard(Hands[i][j]);
		}
		cout << endl;

		if (IsStraightFlush(Hands[i]))
			cout << "\nSTRAIGHT FLUSH" << endl;
		else if (IsFourOfaKind(Hands[i]))
			cout << "\nFOUR OF A KIND" << endl;
		else if (IsFullHouse(Hands[i]))
			cout << "\nFULL HOUSE" << endl;
		else if (IsFlush(Hands[i]))
			cout << "\nFLUSH" << endl;
		else if (IsStraight(Hands[i]))
			cout << "\nSTRAIGHT" << endl;
		else if (IsThreeOfaKind(Hands[i]))
			cout << "\nTHREE OF A KIND" << endl;
		else if (IsTwoPair(Hands[i]))
			cout << "\nTWO PAIR" << endl;
		else if (IsOnePair(Hands[i]))
			cout << "\nPAIR" << endl;
		else
			cout << "\nHIGH CARD" << endl;

		cout << "\n\t=============================" << endl;
	}
}