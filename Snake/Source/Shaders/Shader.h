#pragma once

#include "vertex/vertex.h"

class Shader {

public:

	Shader(const char*, const char*);

	const GLuint getProgramID() const;

	void readFile(const char*, char* &);

	GLuint makeFrangmentShader(const char*);

	GLuint makeVertexShader(const char*);

	GLuint makeShaderProgram(const char*, const char*);

private:

	GLuint _programID;

	GLuint _vertexShaderID;

	GLuint _fragmentShaderID;
};