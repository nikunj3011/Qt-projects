#include "deck.h"
#include "card.h"
#include <algorithm>
#include <stdexcept>

Deck::Deck()
{
    if (_deck.size() != 0)
        _deck.clear();

    for (auto f : Card::faces)
        for (auto s : Card::suits)
            _deck.push_back(std::make_shared<Card>(Card(f,s)));

    _topOfDeck = _deck.size() -1;
}



bool Deck::isEmpty() const
{
    return (_topOfDeck < 0);
}

CardPtr Deck::drawCard(){

    if(isEmpty())
        return nullptr;
    else
        return _deck[_topOfDeck--];
}


void Deck::shuffle()
{
    std::for_each(_deck.begin(),
                  _deck.end(),
                  [](CardPtr& e)
    {
        if (e->isFlipped())
        {
            e->flip();
        }
        else
        {
            e->setMatched(false);
        }
    });


    for (size_t i=0;i<_deck.size();++i)
    {
        swap(_deck[i],  _deck[i + (rand() % (_deck.size()-i))]);
    }
    _topOfDeck = _deck.size()-1;

}
