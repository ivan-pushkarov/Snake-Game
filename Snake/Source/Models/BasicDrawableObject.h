#pragma once
#ifndef BASICDRAWABLEOBJECT_H
#define BASICDRAWABLEOBJECT_H

#include "model.h"
#include <string.h>
#include "managers/shadersmanager.h"

class BasicDrawableObject : public Model {

public:

	BasicDrawableObject();

	void loadVertexArrays();

	virtual void loadModelToVRAM();

	virtual void InitializeVertices() = 0;

	void draw();

	~BasicDrawableObject();

private:

};

#endif // !BASICDRAWABLEOBJECT_H
