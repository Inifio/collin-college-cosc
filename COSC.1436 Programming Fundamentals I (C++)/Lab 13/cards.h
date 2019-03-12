#ifndef CARDS_H
#define CARDS_H

enum Suits {
	Hearts = 3,
	Diamonds,
	Clubs,
	Spades
};

enum Values {
	Two,	// 0
	Three,	// 1
	Four,	// 2
	Five,	// 3
	Six,	// 4
	Seven,	// 5
	Eight,	// 6
	Nine,	// 7
	Ten,	// 8
	Jack,	// 9
	Queen,	// 10
	King,	// 11
	Ace		// 12
};

struct Card
{
	Suits	Suit;
	Values	Value;
};

const int NumPlayers(4);
const int CardsInHand(5);

void InitDeck(Card[]);
bool IsThreeOfaKind(Card[]);
bool IsStraightFlush(Card[]);
bool IsFourOfaKind(Card[]);
bool IsFullHouse(Card[]);
bool IsStraight(Card[]);
bool IsTwoPair(Card[]);
bool IsOnePair(Card[]);
bool IsFlush(Card[]);
void ShowCard(const Card &);
void Shuffle(Card[]);
void Sort(Card[]);

#endif