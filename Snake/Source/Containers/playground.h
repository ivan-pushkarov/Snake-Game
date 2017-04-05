#pragma once

#include <string>
#include "models/line.h"
#include "models/quad.h"
#include "snake.h"
#include "scoreboard.h"

class Playground
{
public:

	Playground();

	~Playground();

	void draw();

	bool play();

	void pause();

	void restart();

	bool detectCollision();

	const int getRandomPositionOnGrid() const;

protected:

private:

	std::vector<Quad> _tiles;

	Quad* _mouse;

	Snake* _snake;

	Scoreboard* _scoreboard;

	unsigned int _speed;

	int _width;
	int _height;

	bool _paused;
	bool _active;

	SDL_Event e;

};