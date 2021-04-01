#pragma once
#include <iostream>
#include "Hand.h"


class Game
{
public:
	Game();
	~Game();

	void play_();
	void gamesMenu() const;
	void showPayTable() const;
	void welcome() const;
	void dealHand();
	void findValueOftheHand() const;
	char getUserInput()const;

};

