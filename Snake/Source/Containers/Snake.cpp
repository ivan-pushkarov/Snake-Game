#include "Snake.h"

Snake::Snake(const glm::vec3& position) : _allowMove(true), _isAlive(true)
{
	int direction = rand() % 4;

	_snakeBody.push_back(Quad(Settings::ModelSnake));
	_snakeBody[0].setPosition(position);

	switch (direction) {
		case 0:
			_snakeBody[0].setMoveDirection(Settings::UP);
			_snakeBody[0].rotateLeft();
			break;
		case 1:
			_snakeBody[0].setMoveDirection(Settings::RIGHT);
			break;
		case 2:
			_snakeBody[0].setMoveDirection(Settings::DOWN);
			_snakeBody[0].rotateRight();
			break;
		case 3:
			_snakeBody[0].setMoveDirection(Settings::LEFT);
			_snakeBody[0].rotateLeft();
			_snakeBody[0].rotateLeft();
			break;
	}
	
	_snakeBody[0].setColor(Settings::SnakeColor);
	
}

void Snake::eat()
{
	_snakeBody.push_back(Quad(Settings::ModelSnake));
	_snakeBody.back().setPosition(_tailPosition);
	_snakeBody.back().setMoveDirection(_tailMoveDirection);
	_snakeBody.back().setRotation(_tailRotation);
	_snakeBody.back().setColor(Settings::SnakeColor);
}

const glm::vec3 Snake::getHeadPosition() const
{
	return _snakeBody[0].getPosition();
}

void Snake::setHeadPosition(const glm::vec3& position)
{
	_snakeBody[0].setPosition(position);
}

const glm::vec3 Snake::getHeadMoveDirection()
{
	return _snakeBody[0].getMoveDirection();
}

void Snake::setHeadMoveDirection(const glm::vec3& direction)
{
	if (_isAlive)
	{

		if (((direction == Settings::UP && _snakeBody[0].getMoveDirection() != Settings::DOWN) ||
			(direction == Settings::DOWN && _snakeBody[0].getMoveDirection() != Settings::UP) ||
			(direction == Settings::RIGHT && _snakeBody[0].getMoveDirection() != Settings::LEFT) ||
			(direction == Settings::LEFT && _snakeBody[0].getMoveDirection() != Settings::RIGHT)) && _allowMove)
		{
			_snakeBody[0].setMoveDirection(direction);
		}

		setAllowMove(false);
	}
}

bool Snake::detectBodyCollision(const glm::vec3& position)
{
	for (std::vector<Quad>::iterator it = _snakeBody.begin() + 1; it != _snakeBody.end(); ++it)
	{
		if (glm::length(it->getPosition() - position) < Settings::epsilion)
		{
			return true;
		}
	}
	return false;
}

void Snake::move()
{
	if (_isAlive)
	{
		// move
		glm::vec3 moveDirectionHead = _snakeBody[0].getMoveDirection();
		glm::vec3 moveDirectionCurrent = _snakeBody[0].getMoveDirection();

		_tailPosition = _snakeBody.back().getPosition();
		_tailMoveDirection = _snakeBody.back().getMoveDirection();
		_tailRotation = _snakeBody.back().getRotation();

		glm::vec3 position;
		glm::vec3 translate;

		for (std::vector<Quad>::iterator it = _snakeBody.begin(); it != _snakeBody.end(); ++it)
		{
			translate = glm::vec3(0.0f);
			position = it->getPosition();

			if (it->getMoveDirection() == Settings::UP && fabs(it->getPosition().y - Settings::TopLeftSquare.y) < Settings::epsilion)
			{
				position.y = Settings::TopLeftSquare.y;

				translate = Settings::DOWN;
				translate *= (glm::length(Settings::Distance) * (Settings::PlaygroundHeight - 1));
			}
			else if (it->getMoveDirection() == Settings::DOWN && fabs(it->getPosition().y - Settings::BottomRightSquare.y) < Settings::epsilion)
			{
				position.y = Settings::BottomRightSquare.y;

				translate = Settings::UP;
				translate *= (glm::length(Settings::Distance) * (Settings::PlaygroundHeight - 1));
			}
			else if (it->getMoveDirection() == Settings::LEFT && fabs(it->getPosition().x - Settings::TopLeftSquare.x) < Settings::epsilion)
			{
				position.x = Settings::TopLeftSquare.x;

				translate = Settings::RIGHT;
				translate *= (glm::length(Settings::Distance) * (Settings::PlaygroundWidth - 1));
			}
			else if (it->getMoveDirection() == Settings::RIGHT && fabs(it->getPosition().x - Settings::BottomRightSquare.x) < Settings::epsilion)
			{
				position.x = Settings::BottomRightSquare.x;

				translate = Settings::LEFT;
				translate *= (glm::length(Settings::Distance) * (Settings::PlaygroundWidth - 1));
			}

			position += translate;

			if (translate != glm::vec3(0.0f))
			{
				it->setPosition(position);
			}
			else
			{
				it->move();
			}

			if (it->getMoveDirection() != moveDirectionCurrent)
			{
				// rotate the node
				moveDirectionHead = moveDirectionCurrent;
				moveDirectionCurrent = it->getMoveDirection();
				if (it != _snakeBody.begin())
				{
					it->setMoveDirection(moveDirectionHead);
				}
			}
		}

		setAllowMove(true);

	}
}

unsigned int Snake::getSize()
{
	return _snakeBody.size();
}

bool Snake::isAlive()
{
	return _isAlive;
}

void Snake::setAllowMove(bool allowMove)
{
	_allowMove = allowMove;
}

void Snake::draw()
{
	// Draw the snake
	for (std::vector<Quad>::iterator it = _snakeBody.begin() + 1; it != _snakeBody.end(); ++it)
	{
		it->draw();
	}

	_snakeBody.begin()->draw();
}

void Snake::die()
{
	_isAlive = false;
}