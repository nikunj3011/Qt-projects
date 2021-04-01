#include "Hand.h"

Hand::Hand()
{
}


Hand::~Hand()
{
}

void Hand::addCard(CardPtr p)
{
	hand.push_back(p);
	checkFace[p->face]++;
	checkSuit[p->suit]++;
	checkForStrait.insert(p->face);

}

void Hand::clear()
{
	hand.clear();
	checkFace.clear();
	checkSuit.clear();
	checkForStrait.clear();
}

int Hand::size()
{
	return hand.size();
}

bool Hand::isPair() const
{
	auto itr = std::find_if(checkFace.begin(), checkFace.end(), [](std::pair<Face, int>e) {return e.second == 2; });

	if (itr != checkFace.end())
	{
		return true;
	}
	else
		return false;
}

bool Hand::isJacksOrBetter() const
{
	auto itr = std::find_if(checkFace.begin(), checkFace.end(), [](std::pair<Face, int>e) {return e.second == 2; });

	if (itr != checkFace.end())
	{
		if (itr->first == Face::JACK || itr->first == Face::QUEEN || itr->first == Face::KING || itr->first == Face::ACE)
			return true;
	}
	else
		return false;
}

bool Hand::isThreeOfakind() const
{
	auto itr = std::find_if(checkFace.begin(), checkFace.end(), [](std::pair<Face, int>e) {return e.second == 3; });
	if (itr != checkFace.end())
	{
		return true;
	}
	else
		return false;

}

bool Hand::isFourOfaKind() const
{
	auto itr = std::find_if(checkFace.begin(), checkFace.end(), [](std::pair<Face, int>e) {return e.second == 4; });
	if (itr != checkFace.end())
	{
		return true;
	}
	else
		return false;
}

bool Hand::isFullHouse() const
{
	if (isPair() == true && isThreeOfakind() == true)
	{
		return true;
	}
	else
		return false;
}

bool Hand::isTwoPair() const
{
	auto itr = std::count_if(checkFace.begin(), checkFace.end(), [](std::pair<Face, int>e) {return e.second == 2; });
	if (itr == 2)
	{
		return true;
	}
	return false;
}

bool Hand::isFlush() const
{
	auto itr = std::find_if(checkSuit.begin(), checkSuit.end(), [](std::pair<Suit, int>e) {return e.second == 5; });

	if (itr != checkSuit.end())
	{
		return true;
	}
	return false;
}

bool Hand::isStrait() const
{
	if (checkForStrait.size() == hand.size())
	{
		int tmp = 0;
		int count = 0;
		int firstHand = 0;
		int totalForHightFlush = 0;
		for (auto itr : checkForStrait)
		{
			totalForHightFlush += static_cast<int>(itr);
			if (firstHand == 0)
			{

				tmp = static_cast<int>(itr);
				count++;
				firstHand++;
				if (itr == Face::ACE)
					totalForHightFlush += 13;
			}

			if (tmp + count == static_cast<int>(itr))
			{
				count++;
			}
			if (count == 5)
			{
				return true;
			}
			if (totalForHightFlush == 55)
			{
				return true;
			}

		}
	}
	return false;
}

bool Hand::isStraitFlush() const
{
	if (isFlush() == true && isStrait() == true)
	{
		return true;
	}
	return false;
}

bool Hand::isRoyalFlush() const
{
	if (isStraitFlush() == true)
	{
		int kingAndAs = 0;
		for (auto itr : checkForStrait)
		{
			if (itr == Face::ACE)
			{
				kingAndAs++;
			}

			if (itr == Face::KING)
			{
				kingAndAs++;
			}
			if (kingAndAs == 2)
			{
				return true;
			}

		}
	}
	return false;
}

std::string Hand::toString() const
{
	std::stringstream ss;
	std::string myHand;
	int count = 1;

	for (auto itr : hand)
	{
		ss << count << ": " << *itr << "\n";
		count++;
	}

	return ss.str();
}


