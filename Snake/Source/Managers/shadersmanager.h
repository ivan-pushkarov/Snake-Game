#pragma once
#ifndef SHADERSYSTEM_H
#define SHADERSYSTEM_H

#include "vertex/vertex.h"
#include <string>
#include <unordered_map>

class Shadersmanager
{
public:

	static Shadersmanager& getInstance();

	const GLuint getProgramID(std::string);

	const GLuint makeShaderProgram(const char*, const char*);

	~Shadersmanager();

private:

	Shadersmanager();

	const GLuint makeVertexShader(char* &shaderSource);

	void readFile(const char* filename, char* &contents);

	const GLuint makeFrangmentShader(char* &shaderSource);

	static Shadersmanager* instance;

	std::unordered_map<std::string, GLuint> _shaders;

};

#endif // !SHADERSYSTEM_H
