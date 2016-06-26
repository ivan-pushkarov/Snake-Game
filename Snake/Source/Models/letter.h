#pragma once
#ifndef LETTER_H
#define LETTER_H

#include "model.h"
#include "settings/settings.h"
#include "managers/fontsmanager.h"
#include "managers/shadersmanager.h"
#include "texturedrawableobject.h"

class Letter : public TextureDrawableObject {
public:

	explicit Letter(char);

	const float getWidth() const;

	const float getHeight() const;

	virtual void InitializeVertices();

	//virtual void loadModelToVRAM() {};

	void setFontSize(unsigned short);

	void setFont(std::string);

	void draw();

	~Letter();

private:

	char _letter;

	float _width;

	float _height;

	unsigned short _size;

	std::string _font;
};

#endif // !LETTER_H
