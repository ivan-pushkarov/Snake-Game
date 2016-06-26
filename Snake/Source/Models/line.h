#pragma once
#ifndef LINE_H
#define LINE_H

#include "models/basicdrawableobject.h"

class Line : public BasicDrawableObject {
public:

	Line();

	virtual void InitializeVertices();

	~Line();

private:

	unsigned int _width;
};

#endif // !LINE_H
