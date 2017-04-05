#pragma once

#include <time.h>
#include "vertex/vertex.h"
#include "managers/modelmanager.h"
#include "managers/Shadersmanager.h"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

class Model {

public:

	explicit Model(GLuint);

	const glm::vec3 getPosition() const;

	void setPosition(const glm::vec3&);


	const glm::vec3 getScale() const;

	void setScale(const glm::vec3&);


	const glm::vec3 getMoveDirection() const;

	void setMoveDirection(const glm::vec3&);


	const glm::vec3 getRotation() const;

	void setRotation(const glm::vec3&);


	void move();


	void rotateLeft();

	void rotateRight();


	const glm::mat4 getTransform() const;

	virtual void loadModelToVRAM() = 0;

	virtual void InitializeVertices() = 0;

protected:

	// VBO Buffer ID
	GLuint _vbo; 

	// Shader program ID
	GLuint _programID;

	glm::vec3 _scale;

	glm::vec3 _eulerAngles;

	glm::quat _rotation;

	glm::vec3 _translate;

	glm::mat4 _transform;

	glm::vec3 _moveDirection;

	std::vector<Vertex> _vertices;

	// Buffer of all the vertices of the model
	std::vector<GLfloat> _positions;

	std::vector<GLfloat> _textures;

	std::vector<GLfloat> _colors;

private:

	void calcTransform();

};