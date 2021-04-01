#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Card.h"

struct Card;
using CardPtr = std::shared_ptr<Card>;

class Deck
{
public:
	Deck();
	~Deck();
	bool isEmpty() const;
	CardPtr draw();
	void shuffle();

private:
	std::vector<CardPtr> deck;
	int topOfDeck;
};

