#pragma once
#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include "models/letter.h"
#include "settings/settings.h"

#include <iostream>

class Scoreboard {
	
public:

	Scoreboard();

	void initText();

	void initFinalMessage();

	void clearFinalMessage();

	void draw();

	const int getLevel() const;

	void setLevel(unsigned short);

	const int getScore() const;

	void setScore(unsigned short);

	const int getHiScore() const;

	void setHiScore(unsigned short);

	void readHiScore();

	void writeHiScore();

	void updateScore();

	const int getSpeed() const;

	void setSpeed(unsigned short);

	~Scoreboard();

private:

	std::vector<Letter> _text;

	std::vector<Letter> _finalMessage;

	unsigned short _level;

	unsigned short _speed;

	unsigned short _score;

	unsigned short _hiScore;
};

#endif	// !MENU_H