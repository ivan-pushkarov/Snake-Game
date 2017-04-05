#pragma once

#include "model.h"
#include <string.h>
#include "managers/fontsmanager.h"

class TextureDrawableObject : public Model{

public:

	TextureDrawableObject();

	~TextureDrawableObject();

	void loadVertexArrays();

	virtual void loadModelToVRAM();

	virtual void InitializeVertices() = 0;
	
	void draw();

protected:

	GLuint _texture;

private:

};