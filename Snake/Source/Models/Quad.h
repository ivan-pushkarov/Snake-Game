#pragma once

#include "managers/modelmanager.h"
#include "models/basicdrawableobject.h"

class Quad : public BasicDrawableObject
{
public:

	Quad(const std::string& model);

	const float getQuadSize() const;

	void setQuadSize(float);

	void setColor(const glm::vec4&);

	virtual void InitializeVertices();

protected:

private:

	std::string _player;

	float _quadSize;
};