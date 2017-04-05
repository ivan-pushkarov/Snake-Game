#include "ModelManager.h"

ModelManager::ModelManager()
{}

ModelManager::~ModelManager()
{
	for (std::unordered_map<std::string, GLuint>::iterator it = _vbos.begin(); it != _vbos.end(); ++it)
	{
		glDeleteBuffers(1, &it->second);
	}
}

ModelManager& ModelManager::getInstance()
{
	static ModelManager instance;

	return instance;
}

const bool ModelManager::findVBO(const std::string& model) const
{
	if (_vbos.find(model) == _vbos.end())
	{
		return false;
	}
	return true;
}

const GLuint ModelManager::getVBO(const std::string& model)
{
	if (_vbos.find(model) == _vbos.end())
	{
		genVBO(model);
	}
	return _vbos[model];
}

void ModelManager::genVBO(const std::string& model)
{
	GLuint _vbo;
	glGenBuffers(1, &_vbo);

	_vbos[model] = _vbo;
}