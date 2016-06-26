#pragma once
#ifndef QUAD_H
#define QUAD_H

#include "managers/modelmanager.h"
#include "models/basicdrawableobject.h"

class Quad : public BasicDrawableObject
{
public:

	Quad(std::string model);

	const float getQuadSize() const;

	void setQuadSize(float);

	void setColor(const glm::vec4&);

	virtual void InitializeVertices();

	~Quad();

protected:

private:

	std::string _player;

	float _quadSize;
};

#endif // !QUAD_H