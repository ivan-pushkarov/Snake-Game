#include "BasicDrawableObject.h"

BasicDrawableObject::BasicDrawableObject() : Model(ShadersManager::getInstance().getProgramID(Settings::BasicShader))
{}

void BasicDrawableObject::loadVertexArrays()
{
	_colors.clear();
	_positions.clear();

	for (std::vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it)
	{
		_positions.push_back(it->_position.x);
		_positions.push_back(it->_position.y);
		_positions.push_back(it->_position.z);
	}

	for (std::vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it)
	{
		_colors.push_back(it->_color.x);
		_colors.push_back(it->_color.y);
		_colors.push_back(it->_color.z);
		_colors.push_back(it->_color.w);
	}
}

void BasicDrawableObject::loadModelToVRAM()
{
	int _numVertices = _vertices.size();

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	loadVertexArrays();

	glBufferData(GL_ARRAY_BUFFER, _numVertices * 7 * sizeof(GLfloat), NULL, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, _numVertices * 3 * sizeof(GLfloat), _positions.data());
	glBufferSubData(GL_ARRAY_BUFFER, _numVertices * 3 * sizeof(GLfloat), _numVertices * 4 * sizeof(GLfloat), _colors.data());
}

void BasicDrawableObject::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	glUseProgram(_programID);

	GLuint positionID = glGetAttribLocation(_programID, "_Position");
	GLuint colorID = glGetAttribLocation(_programID, "_Color");
	GLuint matrixID = glGetUniformLocation(_programID, "mT");

	glEnableVertexAttribArray(positionID);
	glEnableVertexAttribArray(colorID);
	glEnableVertexAttribArray(matrixID);

	glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(_vertices.size() * 3 * sizeof(GLfloat)));

	glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(_transform));

	glDrawArrays(GL_TRIANGLES, 0, _vertices.size());
}