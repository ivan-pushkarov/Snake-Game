#include "quad.h"

Quad::Quad(std::string model) :
	_quadSize(Settings::QuadSize),
	_player(model)
{
	InitializeVertices();

	if (!ModelManager::getInstance().findVBO(model))
	{
		_vbo = ModelManager::getInstance().getVBO(model);
		loadModelToVRAM();
	}
	else
		_vbo = ModelManager::getInstance().getVBO(model);

	setScale(Settings::Scale);
}

void Quad::InitializeVertices()
{
	_vertices.clear();
	Vertex vert;

	float size = float(_quadSize / 2);

	vert._position.x = -size;
	vert._position.y = size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	vert._position.x = size;
	vert._position.y = size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	vert._position.x = size;
	vert._position.y = -size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	vert._position.x = size;
	vert._position.y = -size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	vert._position.x = -size;
	vert._position.y = -size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	vert._position.x = -size;
	vert._position.y = size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	size = float(_quadSize / 2.666666);

	vert._position.x = -size;
	vert._position.y = size;
	vert._position.z = 0.0f;
	vert._color = Settings::MainColor;
	_vertices.push_back(vert);

	vert._position.x = size;
	vert._position.y = size;
	vert._position.z = 0.0f;
	vert._color = Settings::MainColor;
	_vertices.push_back(vert);

	vert._position.x = size;
	vert._position.y = -size;
	vert._position.z = 0.0f;
	vert._color = Settings::MainColor;
	_vertices.push_back(vert);

	vert._position.x = size;
	vert._position.y = -size;
	vert._position.z = 0.0f;
	vert._color = Settings::MainColor;
	_vertices.push_back(vert);

	vert._position.x = -size;
	vert._position.y = -size;
	vert._position.z = 0.0f;
	vert._color = Settings::MainColor;
	_vertices.push_back(vert);

	vert._position.x = -size;
	vert._position.y = size;
	vert._position.z = 0.0f;
	vert._color = Settings::MainColor;
	_vertices.push_back(vert);

	size = float(_quadSize / 4);

	vert._position.x = -size;
	vert._position.y = size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	vert._position.x = size;
	vert._position.y = size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	vert._position.x = size;
	vert._position.y = -size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	vert._position.x = size;
	vert._position.y = -size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	vert._position.x = -size;
	vert._position.y = -size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	vert._position.x = -size;
	vert._position.y = size;
	vert._position.z = 0.0f;
	vert._color = Settings::PlaygroundColor;
	_vertices.push_back(vert);

	if (_player == Settings::ModelSnake)
	{
		vert._position.x = -size;
		vert._position.y = size;
		vert._position.z = 0.0f;
		vert._color = Settings::MainColor;
		_vertices.push_back(vert);

		vert._position.x = size;
		vert._position.y = 0.0f;
		vert._position.z = 0.0f;
		vert._color = Settings::MainColor;
		_vertices.push_back(vert);

		vert._position.x = -size;
		vert._position.y = -size;
		vert._position.z = 0.0f;
		vert._color = Settings::MainColor;
		_vertices.push_back(vert);

		vert._position.x = -size;
		vert._position.y = size - (float)(0.1)*size;
		vert._position.z = 0.0f;
		vert._color = Settings::PlaygroundColor;
		_vertices.push_back(vert);

		vert._position.x = size - (float)(0.1)*size;
		vert._position.y = 0.0f;
		vert._position.z = 0.0f;
		vert._color = Settings::PlaygroundColor;
		_vertices.push_back(vert);

		vert._position.x = -size;
		vert._position.y = -size + (float)(0.1)*size;
		vert._position.z = 0.0f;
		vert._color = Settings::PlaygroundColor;
		_vertices.push_back(vert);
	}
}

void Quad::setColor(const glm::vec4& color)
{
	for (unsigned int i = 0; i < _vertices.size(); i++)
		if (_vertices[i]._color == Settings::PlaygroundColor)
			_vertices[i]._color = color;
	loadModelToVRAM();
}

void Quad::setQuadSize(float quadSize)
{
	_quadSize = quadSize;
	InitializeVertices();
	loadModelToVRAM();
}

const float Quad::getQuadSize() const
{
	return _quadSize;
}

Quad::~Quad()
{}