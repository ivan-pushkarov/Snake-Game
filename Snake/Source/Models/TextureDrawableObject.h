#pragma once
#ifndef TEXTUREDRAWABLEOBJECT_H
#define TEXTUREDRAWABLEOBJECT_H

#include "model.h"
#include <string.h>
#include "managers/fontsmanager.h"

class TextureDrawableObject : public Model{

public:

	TextureDrawableObject();

	void loadVertexArrays();

	virtual void loadModelToVRAM();

	virtual void InitializeVertices() = 0;
	
	void draw();

	~TextureDrawableObject();

protected:

	GLuint _texture;

private:

};

#endif // !TEXTUREDRAWABLEOBJECT_H
