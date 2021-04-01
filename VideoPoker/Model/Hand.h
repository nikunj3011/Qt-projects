#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Deck.h"
#include <algorithm>
#include <sstream>

using CardPtr = std::shared_ptr<Card>;

class Hand
{
public:
	Hand();
	~Hand();

	void addCard(CardPtr);
	void clear();
	int size();
	bool isPair() const;
	bool isJacksOrBetter() const;
	bool isTwoPair()const;
	bool isThreeOfakind()const;
	bool isStrait()const;
	bool isFlush()const;
	bool isFullHouse()const;
	bool isFourOfaKind()const;
	bool isStraitFlush() const;
	bool isRoyalFlush() const;
	std::string toString() const;

private:
	std::vector<CardPtr> hand;
	std::map<Face, int> checkFace;
	std::map<Suit, int> checkSuit;
	std::set<Face> checkForStrait;
};

