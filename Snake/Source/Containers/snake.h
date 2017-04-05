#pragma once

#include "models/quad.h"
#include "models/letter.h"
#include <string.h>

class Snake
{
public:
	explicit Snake(const glm::vec3&);

	void eat();

	void move();

	void die();

	void draw();

	bool isAlive();

	unsigned int getSize();

	void setAllowMove(bool);
	
	const glm::vec3 getHeadPosition() const;

	void setHeadPosition(const glm::vec3&);

	const glm::vec3 getHeadMoveDirection();

	void setHeadMoveDirection(const glm::vec3&);

	bool detectBodyCollision(const glm::vec3&);

protected:

private:

	bool _allowMove;

	bool _isAlive;

	std::vector<Quad> _snakeBody;

	glm::vec3 _tailPosition;
	glm::vec3 _tailMoveDirection;
	glm::vec3 _tailRotation;

};