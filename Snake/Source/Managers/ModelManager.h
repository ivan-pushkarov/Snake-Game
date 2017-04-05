#pragma once

#include "vertex/vertex.h"
#include <unordered_map>

class ModelManager {
public:

	static ModelManager& getInstance();

	const bool findVBO(const std::string& model) const;

	const GLuint getVBO(const std::string& model);

	void genVBO(const std::string& model);

	~ModelManager();

protected:

private:

	ModelManager();

	std::unordered_map<std::string, GLuint> _vbos;

};