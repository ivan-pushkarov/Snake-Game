#include "Model.h"

Model::Model(GLuint programID) : _programID(programID)
{
	_scale = glm::vec3(1.0, 1.0, 1.0);
	_rotation = glm::quat(glm::vec3(0.0, 0.0, 0.0));
	_translate = glm::vec3(0.0);

	_moveDirection = glm::vec3(0.0, 0.0, 0.0);
}

const glm::vec3 Model::getPosition() const
{
	return _translate;
}

void Model::setPosition(const glm::vec3& translate)
{
	_translate = translate;

	calcTransform();
}

const glm::vec3 Model::getScale() const
{
	return _scale;
}

void Model::setScale(const glm::vec3& scale)
{
	_scale = scale;

	calcTransform();
}


const glm::vec3 Model::getMoveDirection() const
{
	return _moveDirection;
}

void Model::setMoveDirection(const glm::vec3& moveDirection)
{
	if (_moveDirection != moveDirection)
	{
		if (_moveDirection == Settings::UP)
		{
			if (moveDirection == Settings::RIGHT)
			{
				rotateRight();
			}
			else
			{
				rotateLeft();
			}
		}

		if (_moveDirection == Settings::DOWN)
		{
			if (moveDirection == Settings::RIGHT)
			{
				rotateLeft();
			}
			else
			{
				rotateRight();
			}
		}

		if (_moveDirection == Settings::RIGHT)
		{
			if (moveDirection == Settings::UP)
			{
				rotateLeft();
			}
			else
			{
				rotateRight();
			}
		}

		if (_moveDirection == Settings::LEFT)
		{
			if (moveDirection == Settings::UP)
			{
				rotateRight();
			}
			else
			{
				rotateLeft();
			}
		}
	}

	_moveDirection = moveDirection;
}

const glm::vec3 Model::getRotation() const
{
	return _eulerAngles;
}

void Model::setRotation(const glm::vec3& eulerAngles)
{
	_eulerAngles = eulerAngles;
	_rotation = glm::quat(_eulerAngles);

	calcTransform();
}

void Model::move()
{
	_translate += getMoveDirection() * glm::length(Settings::Distance);

	calcTransform();
}

void Model::rotateLeft()
{
	_eulerAngles += glm::vec3(0, 0, Settings::Rotation);
	_rotation = glm::quat(_eulerAngles);

	calcTransform();
}

void Model::rotateRight()
{
	_eulerAngles += glm::vec3(0, 0, -Settings::Rotation);
	_rotation = glm::quat(_eulerAngles);
	
	calcTransform();
}

void Model::calcTransform()
{
	_transform = glm::translate(glm::mat4(1.0f), _translate) * glm::mat4(_rotation) * glm::scale(glm::mat4(1.0f), _scale);
}

const glm::mat4 Model::getTransform() const
{
	return _transform;
}