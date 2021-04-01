#pragma once
#include <map>
#include <string>

enum class PokerHand {
    isRoyalFlush, isStraitFlush, isFourOfaKind, isFullHouse,
    isFlush, isStrait, isThreeOfakind, isTwoPair, isJacksOrBetter, isPair
};

class VideoPoker
{
public:
    static const std::map<PokerHand, std::string> paySheet;
};

