#pragma once

#include "models/basicdrawableobject.h"

class Line : public BasicDrawableObject {
public:

	Line();

	virtual void InitializeVertices();

private:

	unsigned int _width;
};
