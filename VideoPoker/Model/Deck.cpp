#include "Deck.h"
#include <time.h>

Deck::Deck()
{
	for (auto f : Card::faces)
		for (auto s : Card::suits)
			deck.push_back(std::make_shared<Card>(Card(f, s)));
	topOfDeck = deck.size() - 1;

	srand(unsigned(time(0)));
}

Deck::~Deck()
{
}

bool Deck::isEmpty() const
{
	return (topOfDeck < 0);
}

void Deck::shuffle()
{
	for (int i = 0; i < deck.size(); ++i)
	{
		swap(deck[i], deck[rand() % deck.size()]);
	}
	topOfDeck = deck.size() - 1;
}


CardPtr Deck::draw()
{
	return deck.at(topOfDeck--);
}


