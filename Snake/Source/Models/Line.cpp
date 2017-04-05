#include "Line.h"

Line::Line() : _width(Settings::DefaultLineWidth)
{
	InitializeVertices();

	if (!ModelManager::getInstance().findVBO(Settings::ModelLine))
	{
		_vbo = ModelManager::getInstance().getVBO(Settings::ModelLine);
		loadModelToVRAM();
	}
	else
		_vbo = ModelManager::getInstance().getVBO(Settings::ModelLine);
}

void Line::InitializeVertices()
{
	float width = _width*(float(2) / Settings::ApplicationWidth);

	_vertices.clear();
	Vertex vert;

	vert._position.x = 0.0f;
	vert._position.y = 1.0f;
	vert._position.z = 0.0f;
	vert._color = Settings::LineColor;
	_vertices.push_back(vert);

	vert._position.x = 0.0f;
	vert._position.y = -1.0f;
	vert._position.z = 0.0f;
	vert._color = Settings::LineColor;
	_vertices.push_back(vert);

	vert._position.x = width;
	vert._position.y = -1.0f;
	vert._position.z = 0.0f;
	vert._color = Settings::LineColor;
	_vertices.push_back(vert);

	vert._position.x = width;
	vert._position.y = -1.0f;
	vert._position.z = 0.0f;
	vert._color = Settings::LineColor;
	_vertices.push_back(vert);

	vert._position.x = width;
	vert._position.y = 1.0f;
	vert._position.z = 0.0f;
	vert._color = Settings::LineColor;
	_vertices.push_back(vert);

	vert._position.x = 0.0f;
	vert._position.y = 1.0f;
	vert._position.z = 0.0f;
	vert._color = Settings::LineColor;
	_vertices.push_back(vert);
}