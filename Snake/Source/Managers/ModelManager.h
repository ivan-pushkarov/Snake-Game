#pragma once
#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "vertex/vertex.h"
#include <unordered_map>

class ModelManager {
public:

	static ModelManager& getInstance();

	const bool findVBO(std::string model) const;

	const GLuint getVBO(std::string model);

	void genVBO(std::string model);

	~ModelManager();

protected:

private:

	ModelManager();

	static ModelManager* instance;

	std::unordered_map<std::string, GLuint> _vbos;

};

#endif // !MODELMANAGER_H