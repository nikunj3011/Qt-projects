#include "game.h"
#include "Model/card.h"
#include "Model/deck.h"


Game::Game()
{

}



void Game::setFlipped(int index)
{
    _cards.at(index)->flip();
}

void Game::setCardAtN(CardPtr card){

    _cards.push_back(card);
}

std::string Game::getText(int index)
{
    return _cards[index]->toString();
}

CardColor Game::getCardColor(int index)
{
    return _cards[index]->getColor();
}

CardPtr Game::getCardN(int index)
{
    return _cards.at(index);
}

void Game::selectCardN(int index)
{

_cards.at(index)->setMatched(false); ///
    if (index < _cards.size() )
    {
        _cards.at(index)->flip();

        for (int i=0;i<_cards.size();++i)
        {
            if (_cards.at(i)->isFlipped() && i != index && !_cards.at(i)->isMatched()){

                /////
                if(_cards.at(index)->getMatchValue(*_cards.at(i)) > 0){
                    _cards.at(index)->setMatched(true);
                    _cards.at(i)->setMatched(true);
                }
                else{
                    _cards.at(i)->flip();
                }
                score += _cards.at(index)->getMatchValue(*_cards.at(i));
            }
        }
    }
}

int Game::getScore()
{
    return score;
}



