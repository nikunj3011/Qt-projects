#include "model/hangmanClass.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>

const std::vector<Picture> hangmanClass::_pictureList ={ Picture::ONE,
                                                 Picture::TWO,
                                                 Picture::THREE,
                                                 Picture::FOUR,
                                                 Picture::FIVE,
                                                 Picture::SIX,
                                                 Picture::SEVEN
                                                     };

hangmanClass::hangmanClass()
{
    loadPhrases();
    shufflePhrases();
}


hangmanClass::~hangmanClass()
{
}

char hangmanClass::getCharResponse()
{
    char userInput;

    std::cin >> userInput;

    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cin >> userInput;
    }

    return userInput;
}

std::string hangmanClass::showHiddenPhrase()
{
    return dash;
}

std::string hangmanClass::showPhrase()
{
    return spaces;
}

void hangmanClass::initGame()
{
    _correctGuesses.clear();
    misses.clear();
    spaces = "";
    dash = "";
}

void hangmanClass::loadPhrases()
{
    std::ifstream inFile("C:/Users/MSI/Downloads/hangman-master/Media/images/hangman.txt");
    if (!inFile.fail())
    {
        do{
            getline(inFile, phrase);
            phrases.push_back(phrase);
        }while (!inFile.eof());

        inFile.close();
    }
    else
    {											// fail catch
        std::cout << "Error opening file for write\n";
        exit(EXIT_FAILURE);
    }

}


void hangmanClass::shufflePhrases()
{
    srand ( (unsigned int)time(NULL) );
    std::random_device rng;
    std::mt19937 urng(rng());
    std::shuffle(phrases.begin(), phrases.end(), urng);
}

Picture hangmanClass::showGallows()
{

    switch (misses.size())
    {
    case 0:\
        return Picture::ONE;
        break;
    case 1:
        return Picture::TWO;
        break;
    case 2:
        return Picture::THREE;
        break;
    case 3:
        return Picture::FOUR;
        break;
    case 4:
        return Picture::FIVE;
        break;
    case 5:
        return Picture::SIX;
        break;
    default:
        return Picture::SEVEN;
        break;
    }
}

void hangmanClass::processGuess(std::string guess)
{
    if(won() || lost())
        return;

    size_t found = spaces.find(guess);

    if (found != std::string::npos)
    {
        size_t found = spaces.find(guess, 0);
        while (found != std::string::npos)
        {
            dash.replace(found, 1, guess);
            found = spaces.find(guess, found + 1);
        }
        _correctGuesses[guess]++;
    }

    else
    {
        misses[guess]++;
    }
}

std::string hangmanClass::newPhrase()
{
    phrase = phrases[0];

    for (auto p : phrase)
    {
        if (p == ' ')
        {
            dash.append("  ");
        }
        else
        {
            dash.append("_ ");
        }
    }


    for (auto p : phrase)
    {
        spaces.push_back(p);
        spaces.push_back(' ');
    }


    _correctGuesses[" "]++;

    return dash;
}

bool hangmanClass::won()
{
    for (auto c : phrase)
    {
        std::string s(1, c);
        auto it = _correctGuesses.find(s);
        if (it == _correctGuesses.end())
        {
            return false;
        }
    }
    return true;
}

bool hangmanClass::lost()
{
    if (misses.size() >= ALLOWED_MISSES)
    {
        return true;
    }
    else
        return false;
}

bool hangmanClass::letterGuessed(std::string guess)
{
    auto itr2 = misses.find(guess);
    if (itr2 != misses.end())
    {
        return true;
    }

    auto itr = _correctGuesses.find(guess);
    if (itr != _correctGuesses.end())
    {
        return true;
    }

    return false;
}
