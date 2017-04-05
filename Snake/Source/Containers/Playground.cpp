#include "Playground.h"

Playground::Playground() : _paused(true), _speed(Settings::SnakeSpeed), _active(true)
{
	_width = Settings::PlaygroundWidth;
	_height = Settings::PlaygroundHeight;

	for (int j = _height / 2; j > -_height / 2; j--)
	{
		for (int i = -_width / 2; i < _width / 2; i++)
		{
			Quad quad(Settings::ModelPlayground);
			quad.setPosition(glm::vec3(glm::length(Settings::Distance) * (0.0025*Settings::ApplicationWidth) * i, glm::length(Settings::Distance) * (0.0025*Settings::ApplicationWidth) * j, 0.0f) + Settings::PlaygroundOffset);
			_tiles.push_back(quad);
		}
	}

	_snake = new Snake(_tiles[getRandomPositionOnGrid()].getPosition());

	_mouse = new Quad(Settings::ModelMouse);
	_mouse->setPosition(_tiles[getRandomPositionOnGrid()].getPosition());
	_mouse->setColor(Settings::MouseColor);

	while (glm::length(_snake->getHeadPosition() - _mouse->getPosition()) < Settings::epsilion)
		_mouse->setPosition(_tiles[getRandomPositionOnGrid()].getPosition());

	_scoreboard = new Scoreboard();
}

Playground::~Playground()
{
	delete _snake;
	delete _mouse;
	delete _scoreboard;
}

const int Playground::getRandomPositionOnGrid() const
{
	return rand() % (Settings::PlaygroundWidth * Settings::PlaygroundHeight);
}

bool Playground::play()
{
	//Check if the snake has reached the maximum size and if the level is completed
	if (_snake->getSize() == _scoreboard->getLevel() * Settings::SnakeMagnitude)
	{
		SDL_Delay(Settings::LevelCompletedDelay);

		if (_scoreboard->getLevel() == Settings::NumberOfLevels)
		{
			pause();
			_active = false;
			_scoreboard->initFinalMessage();
		}
		else
		{
			_scoreboard->setLevel(_scoreboard->getLevel() + 1);
			_scoreboard->setSpeed(_scoreboard->getSpeed() + 1);

			_speed -= Settings::IncreaseSpeed;
			restart();
		}
	}

	SDL_Delay(_speed);

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_KEYDOWN || e.type == SDL_QUIT)
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == 'q')
			{
				if (_scoreboard->getHiScore() == _scoreboard->getScore())
				{
					_scoreboard->writeHiScore();
				}
				return 1;
			}

			if (e.key.keysym.sym == 'r')
			{
				restart();
			}

			if (e.key.keysym.sym == 'w' || e.key.keysym.scancode == SDL_SCANCODE_UP)
			{
				_snake[0].setHeadMoveDirection(Settings::UP);
			}

			if (e.key.keysym.sym == 's' || e.key.keysym.scancode == SDL_SCANCODE_DOWN)
			{
				_snake[0].setHeadMoveDirection(Settings::DOWN);
			}

			if (e.key.keysym.sym == 'a' || e.key.keysym.scancode == SDL_SCANCODE_LEFT)
			{
				_snake[0].setHeadMoveDirection(Settings::LEFT);
			}

			if (e.key.keysym.sym == 'd' || e.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			{
				_snake[0].setHeadMoveDirection(Settings::RIGHT);
			}

			if (e.key.keysym.sym == 'p')
			{
				pause();
			}

		}
	}

	if (!_paused)
	{
		_snake->move();
		detectCollision();
	}

	return 0;
}

void Playground::pause()
{
	if (_active)
	{
		_paused = !_paused;
	}
}

bool Playground::detectCollision()
{
	bool collision = false;
	bool result = false;

	if (glm::length(_snake->getHeadPosition() - _mouse->getPosition()) < Settings::epsilion)
	{
		collision = true;
		result = collision;
		_snake->eat();
		_scoreboard->updateScore();

		while (collision)
		{
			collision = false;
			_mouse->setPosition(_tiles[getRandomPositionOnGrid()].getPosition());

			if (glm::length(_snake->getHeadPosition() - _mouse->getPosition()) < Settings::epsilion || _snake->detectBodyCollision(_mouse->getPosition()))
			{
				collision = true;
			}
		}
	}

	if (_snake->detectBodyCollision(_snake->getHeadPosition()))
	{
		_snake->die();
	}

	if (_snake->isAlive())
	{
		_snake->setAllowMove(true);
	}
	else
	{
		_snake->setAllowMove(false);
		_scoreboard->initFinalMessage();
	}

	return result;
}

void Playground::restart()
{
	delete _snake;
	_snake = new Snake(_tiles[getRandomPositionOnGrid()].getPosition());

	delete _mouse;
	_mouse = new Quad(Settings::ModelMouse);
	_mouse->setPosition(_tiles[getRandomPositionOnGrid()].getPosition());
	_mouse->setColor(Settings::MouseColor);

	while (glm::length(_snake->getHeadPosition() - _mouse->getPosition()) < Settings::epsilion)
		_mouse->setPosition(_tiles[getRandomPositionOnGrid()].getPosition());

	_paused = true;

	_scoreboard->initText();

	if (_scoreboard->getHiScore() == _scoreboard->getScore())
	{
		_scoreboard->writeHiScore();
	}

	_scoreboard->clearFinalMessage();
	_scoreboard->setScore(0);
	
	if (!_active)
	{
		_scoreboard->setLevel(1);
		_scoreboard->setSpeed(1);

		_active = true;
		_speed = Settings::SnakeSpeed;
	}
}

void Playground::draw()
{
	for (std::vector<Quad>::iterator it = _tiles.begin(); it != _tiles.end(); ++it)
	{
		it->draw();
	}
	
	_snake->draw();

	_mouse->draw();

	_scoreboard->draw();
}