#include "modelmanager.h"

ModelManager* ModelManager::instance = 0;

ModelManager::ModelManager()
{}

ModelManager& ModelManager::getInstance()
{
	static ModelManager instance;

	return instance;
}

const bool ModelManager::findVBO(std::string model) const
{
	if (_vbos.find(model) == _vbos.end())
		return false;
	return true;
}

const GLuint ModelManager::getVBO(std::string model)
{
	if (_vbos.find(model) == _vbos.end())
		genVBO(model);

	return _vbos[model];
}

void ModelManager::genVBO(std::string model)
{
	GLuint _vbo;
	glGenBuffers(1, &_vbo);

	_vbos[model] = _vbo;
}

ModelManager::~ModelManager() 
{
	for (std::unordered_map<std::string, GLuint>::iterator it = _vbos.begin(); it != _vbos.end(); ++it)
		glDeleteBuffers(1, &it->second);
}