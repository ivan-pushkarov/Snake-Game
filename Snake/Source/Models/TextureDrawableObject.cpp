#include "texturedrawableobject.h"

TextureDrawableObject::TextureDrawableObject() : Model(Shadersmanager::getInstance().getProgramID(Settings::TextureShader))
{
	glGenTextures(1, &_texture);
}

void TextureDrawableObject::loadVertexArrays()
{
	_colors.clear();
	_textures.clear();
	_positions.clear();

	for (std::vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it)
	{
		_positions.push_back(it->_position.x);
		_positions.push_back(it->_position.y);
		_positions.push_back(it->_position.z);
	}

	for (std::vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it)
	{
		_textures.push_back(it->_textureCoordinate.x);
		_textures.push_back(it->_textureCoordinate.y);
	}
}

void TextureDrawableObject::loadModelToVRAM()
{
	int _numVertices = _vertices.size();

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	loadVertexArrays();

	glBufferData(GL_ARRAY_BUFFER, _numVertices * 5 * sizeof(GLfloat), NULL, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, _numVertices * 3 * sizeof(GLfloat), _positions.data());
	glBufferSubData(GL_ARRAY_BUFFER, _numVertices * 3 * sizeof(GLfloat), _numVertices * 2 * sizeof(GLfloat), _textures.data());
}

void TextureDrawableObject::draw()
{
	unsigned int _numVertices = _vertices.size();

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	glUseProgram(_programID);

	GLuint matrixID = glGetUniformLocation(_programID, "mT");
	GLuint colorID = glGetUniformLocation(_programID, "_Color");
	GLuint textureID = glGetUniformLocation(_programID, "_Texture");
	GLuint positionID = glGetAttribLocation(_programID, "_Position");
	GLuint texturePosID = glGetAttribLocation(_programID, "_TexturePosition");
	
	glEnableVertexAttribArray(colorID);
	glEnableVertexAttribArray(matrixID);
	glEnableVertexAttribArray(positionID);
	glEnableVertexAttribArray(texturePosID);
	
	glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(texturePosID, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(_numVertices * 3 * sizeof(GLfloat)));
	
	glUniform4fv(colorID, 1, glm::value_ptr(Settings::TextColor));
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(_transform));

	glDrawArrays(GL_TRIANGLE_STRIP, 0, _numVertices);

	glDisableVertexAttribArray(colorID);
	glDisableVertexAttribArray(matrixID);
	glDisableVertexAttribArray(positionID);
	glDisableVertexAttribArray(texturePosID);
}

TextureDrawableObject::~TextureDrawableObject()
{
	glDeleteTextures(1, &_texture);
}