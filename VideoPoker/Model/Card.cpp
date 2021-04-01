#include "Card.h"

std::string Card::toString() const
{
	return faceNames.at(face) + " of " + suitNames.at(suit);
}


const std::set<Suit> Card::suits{
	Suit::CLUB,
	Suit::DIAMOND,
	Suit::HEART,
	Suit::SPADE };

const std::set<Face> Card::faces{
	Face::ACE,
	Face::TWO,
	Face::THREE,
	Face::FOUR,
	Face::FIVE,
	Face::SIX,
	Face::SEVEN,
	Face::EIGHT,
	Face::NINE,
	Face::TEN,
	Face::JACK,
	Face::QUEEN,
	Face::KING };

const std::map<Face, std::string> Card::faceNames{
{Face::ACE, "A"},
{Face::TWO, "2"},
{Face::THREE, "3"},
{Face::FOUR, "4"},
{Face::FIVE, "5"},
{Face::SIX, "6"},
{Face::SEVEN, "7"},
{Face::EIGHT, "8"},
{Face::NINE, "9"},
{Face::TEN,"10"},
{Face::JACK, "J"},
{Face::QUEEN, "Q"},
{Face::KING, "K"}
};

const std::map<Suit, std::string> Card::suitNames{
	{Suit::HEART, "heart"},
	{Suit::DIAMOND, "diamond"},
	{Suit::CLUB, "club"},
	{Suit::SPADE, "spade"}
};

std::ostream& operator<<(std::ostream& os, Card& c)
{
	os << c.toString();
	return os;
}
