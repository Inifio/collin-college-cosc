#include <iostream>

using namespace std;

#include <stdlib.h>
#include <time.h>

#include "Cards.h"

char * ValueNames[] = {
	"Two",
	"Three",
	"Four",
	"Five",
	"Six",
	"Seven",
	"Eight",
	"Nine",
	"Ten",
	"Jack",
	"Queen",
	"King",
	"Ace"
};

void InitDeck(Card Deck[])
{
	int		i;
	Suits	S;
	Values	V;

	srand(time(0));
	i = 0;
	for (S = Hearts; S <= Spades; S = (Suits)(S + 1))
		for (V = Two; V <= Ace; V = (Values)(V + 1))
		{
			Deck[i].Suit = S;
			Deck[i].Value = V;
			i++;
		}
}

bool IsThreeOfaKind(Card Hand[])
{
	if ((Hand[0].Value == Hand[2].Value) ||
		(Hand[1].Value == Hand[3].Value) ||
		(Hand[2].Value == Hand[4].Value))
		return true;
	else
		return false;
}

bool IsStraightFlush(Card Hand[])
{
	if ((Hand[0].Suit == Hand[1].Suit) &&
		(Hand[1].Suit == Hand[2].Suit) &&
		(Hand[2].Suit == Hand[3].Suit) &&
		(Hand[3].Suit == Hand[4].Suit)) {

		if (((Hand[0].Suit + 1) == Hand[1].Suit) &&
			((Hand[1].Suit + 1) == Hand[2].Suit) &&
			((Hand[2].Suit + 1) == Hand[3].Suit) &&
			((Hand[3].Suit + 1) == Hand[4].Suit)) {
			return true;
		}
		else
			return false;

	}
	else
		return false;
}

bool IsFourOfaKind(Card Hand[])
{
	if ((Hand[0].Value == Hand[3].Value) ||
		(Hand[1].Value == Hand[4].Value))
		return true;
	else
		return false;
}

bool IsFullHouse(Card Hand[]) {
	if ((Hand[0].Value == Hand[2].Value)) {
		if ((Hand[3].Value) == (Hand[4].Value)) {
			return true;
		}
		else
			return false;
	}
	if ((Hand[2].Value) == (Hand[4].Value)) {
		if ((Hand[0].Value) == (Hand[1].Value)) {
			return true;
		}
		else
			return false;
	}
	return false;
}

/*bool IsFullHouse(Card Hand[])	// Needs Work
{
	if ((Hand[0].Value == Hand[2].Value) || // If true check the rest for same value
		(Hand[1].Value == Hand[3].Value) ||
		(Hand[2].Value == Hand[4].Value))

		if ((Hand[0].Value == Hand[1].Value) ||
			(Hand[1].Value == Hand[2].Value) ||
			(Hand[2].Value == Hand[3].Value) ||
			(Hand[3].Value == Hand[4].Value)) {
			return true;
		}
		else
			return false;

	else
		return false;
}*/

bool IsFlush(Card Hand[])
{
	if ((Hand[0].Suit == Hand[1].Suit) &&
		(Hand[1].Suit == Hand[2].Suit) &&
		(Hand[2].Suit == Hand[3].Suit) &&
		(Hand[3].Suit == Hand[4].Suit)) {
		return true;
	}
	else
		return false;
}

bool IsStraight(Card Hand[])
{
	if (((Hand[0].Suit + 1) == Hand[1].Suit) &&
		((Hand[1].Suit + 1) == Hand[2].Suit) &&
		((Hand[2].Suit + 1) == Hand[3].Suit) &&
		((Hand[3].Suit + 1) == Hand[4].Suit)) {
		return true;
	}
	else
		return false;
}

bool IsTwoPair(Card Hand[])
{
	if ((Hand[0].Value == Hand[1].Value))
		if ((Hand[2].Value == Hand[3].Value) ||
			(Hand[3].Value == Hand[4].Value))
			return true;
		else
			return false;
	else
		if ((Hand[1].Value == Hand[2].Value))
			if ((Hand[3].Value == Hand[4].Value))
				return true;
			else
				return false;
	else
		return false;
}

bool IsOnePair(Card Hand[])
{
	if ((Hand[0].Value == Hand[1].Value) ||
		(Hand[1].Value == Hand[2].Value) ||
		(Hand[2].Value == Hand[3].Value) ||
		(Hand[3].Value == Hand[4].Value)) {
		return true;
	}
	else
		return false;
}




void ShowCard(const Card & C)	// passing a structure by reference makes the program more efficient
{
	cout << ValueNames[C.Value] << " of " << (char)C.Suit << ", ";
}

void Shuffle(Card Deck[])
{
	int		i;
	int		j;
	Card	Temp;

	for (i = 0; i < 52; i++)
	{
		j = rand() % 52;
		Temp = Deck[i];
		Deck[i] = Deck[j];
		Deck[j] = Temp;
	}
}

void Sort(Card Hand[]) {

	Card temp;
	bool sorted;

	do {
		sorted = true;
		for (int i = 0; i < 5; i++) {
			if ((Hand[i].Value) < (Hand[i + 1].Value)) {
				temp = Hand[i];
				Hand[i] = Hand[i + 1];
				Hand[i + 1] = temp;
				sorted = false;
			}
		}

	} while (!sorted);
}