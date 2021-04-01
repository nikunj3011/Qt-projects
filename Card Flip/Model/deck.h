#ifndef Deck_hpp
#define Deck_hpp

#include <vector>
#include <memory>

class Card;
using CardPtr = std::shared_ptr<Card>;


class Deck
{
public:
    Deck();

    bool isEmpty() const;
    CardPtr drawCard();

    void shuffle();

private:
    std::vector<CardPtr> _deck;
    int _topOfDeck;

};


#endif /* Deck_hpp */
