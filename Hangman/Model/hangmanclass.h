#ifndef HANGMANCLASS_H
#define HANGMANCLASS_H
#pragma once

#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>

enum class Picture { ONE,
                    TWO,
                    THREE,
                    FOUR,
                    FIVE,
                    SIX,
                    SEVEN
                  };

class hangmanClass
{
public:
    hangmanClass();
    ~hangmanClass();

    void initGame();

    void processGuess(std::string guess);

    char getCharResponse();

    Picture showGallows();
    std::string showHiddenPhrase();
    std::string showPhrase();

    std::string newPhrase();

    void loadPhrases();
    void shufflePhrases();

    bool letterGuessed(std::string guess);

    bool won();
    bool lost();

private:
    std::string phrase;
    std::vector <std::string> phrases;

    static const int ALLOWED_MISSES = 6;

    std::map<std::string, int> _correctGuesses;
    std::map<std::string, int> misses;
    std::string dash;
    std::string spaces;

    static const std::vector<Picture> _pictureList;
};


#endif // HANGMANCLASS_H
