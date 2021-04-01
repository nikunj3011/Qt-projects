#include "VideoPoker.h"
const std::map<PokerHand, std::string> VideoPoker::paySheet{
{PokerHand::isRoyalFlush, "800"},
{PokerHand::isStraitFlush, "50"},
{PokerHand::isFourOfaKind, "25"},
{PokerHand::isFullHouse, "9"},
{PokerHand::isFlush, "6"},
{PokerHand::isStrait, "4"},
{PokerHand::isThreeOfakind, "3"},
{PokerHand::isTwoPair, "2"},
{PokerHand::isJacksOrBetter, "1"},
{PokerHand::isPair, "1"}
};