#pragma once

#include "vertex/vertex.h"
#include <string>
#include <unordered_map>

class ShadersManager
{
public:

	static ShadersManager& getInstance();

	const GLuint getProgramID(const std::string&);

	const GLuint makeShaderProgram(const char*, const char*);

	~ShadersManager();

private:

	ShadersManager();

	const GLuint makeVertexShader(char* &shaderSource);

	void readFile(const char* filename, char* &contents);

	const GLuint makeFrangmentShader(char* &shaderSource);

	std::unordered_map<std::string, GLuint> _shaders;

};