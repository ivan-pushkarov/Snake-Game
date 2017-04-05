#include "Letter.h"
#include <string>

Letter::Letter(char letter) :
	_size(Settings::DefaultFontSize),
	_letter(letter),
	_font(Settings::RegularFont)
{
	InitializeVertices();

	if (!ModelManager::getInstance().findVBO(std::string(&_letter) + _font + std::to_string(_size)))
	{
		_vbo = ModelManager::getInstance().getVBO(std::string(&_letter) + _font + std::to_string(_size));
		loadModelToVRAM();
	}
	else
		_vbo = ModelManager::getInstance().getVBO(std::string(&_letter) + _font + std::to_string(_size));
}

const float Letter::getWidth() const
{
	return _width;
}

const float Letter::getHeight() const
{
	return _height;
}

void Letter::draw()
{
	/* Enable blending, necessary for our alpha texture */
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBindTexture(GL_TEXTURE_2D, _texture);

	/* We require 1 byte alignment when uploading texture data */
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	/* Clamping to edges is important to prevent artifacts when scaling */
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	/* Linear filtering usually looks best for text */
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	/* Try to load and render the character */
	if (!FT_Load_Char(Fontsmanager::getInstance().getFace(_font), _letter, FT_LOAD_RENDER)) 
	{
		//continue;

		/* Upload the "bitmap", which contains an 8-bit grayscale image, as an alpha texture */
		glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, Fontsmanager::getInstance().getFace(_font)->glyph->bitmap.width, Fontsmanager::getInstance().getFace(_font)->glyph->bitmap.rows, 0, GL_ALPHA, GL_UNSIGNED_BYTE, Fontsmanager::getInstance().getFace(_font)->glyph->bitmap.buffer);

		TextureDrawableObject::draw();
	}
}

void Letter::setFontSize(unsigned short size)
{
	_size = size;
	//FT_Set_Pixel_Sizes(Fontsmanager::getInstance().getFace(_font), 0, _size);

	InitializeVertices();

	if (!ModelManager::getInstance().findVBO(std::string(&_letter) + _font + std::to_string(_size)))
	{
		_vbo = ModelManager::getInstance().getVBO(std::string(&_letter) + _font + std::to_string(_size));
		loadModelToVRAM();
	}
	else
		_vbo = ModelManager::getInstance().getVBO(std::string(&_letter) + _font + std::to_string(_size));
}

void Letter::setFont(const std::string& font)
{
	if (font == Settings::RegularFont || font == Settings::BoldFont)
	{
		_font = font;

		InitializeVertices();

		if (!ModelManager::getInstance().findVBO(std::string(&_letter) + _font + std::to_string(_size)))
		{
			_vbo = ModelManager::getInstance().getVBO(std::string(&_letter) + _font + std::to_string(_size));
			loadModelToVRAM();
		}
		else
			_vbo = ModelManager::getInstance().getVBO(std::string(&_letter) + _font + std::to_string(_size));
	}
}

void Letter::InitializeVertices()
{
	FT_Set_Pixel_Sizes(Fontsmanager::getInstance().getFace(_font), 0, _size);

	_vertices.clear();
	
	/* Try to load and render the character */
	if (!FT_Load_Char(Fontsmanager::getInstance().getFace(_font), _letter, FT_LOAD_RENDER)) 
	{
		//continue;

		/* Calculate the vertex and texture coordinates */
		float x = Fontsmanager::getInstance().getFace(_font)->glyph->bitmap_left * float (2.0 / Settings::ApplicationWidth);
		float y = - Fontsmanager::getInstance().getFace(_font)->glyph->bitmap_top * float(2.0 / Settings::ApplicationHeight);
		_width = Fontsmanager::getInstance().getFace(_font)->glyph->bitmap.width * float(2.0 / Settings::ApplicationWidth);
		_height = Fontsmanager::getInstance().getFace(_font)->glyph->bitmap.rows * float(2.0 / Settings::ApplicationHeight);

		Vertex vert;
		vert._position.x = x;
		vert._position.y = -y;
		vert._position.z = 0;
		vert._textureCoordinate.x = 0;
		vert._textureCoordinate.y = 0;
		_vertices.push_back(vert);

		vert._position.x = x + _width;
		vert._position.y = -y;
		vert._position.z = 0;
		vert._textureCoordinate.x = 1;
		vert._textureCoordinate.y = 0;
		_vertices.push_back(vert);

		vert._position.x = x;
		vert._position.y = -y - _height;
		vert._position.z = 0;
		vert._textureCoordinate.x = 0;
		vert._textureCoordinate.y = 1;
		_vertices.push_back(vert);

		vert._position.x = x + _width;
		vert._position.y = -y - _height;
		vert._position.z = 0;
		vert._textureCoordinate.x = 1;
		vert._textureCoordinate.y = 1;
		_vertices.push_back(vert);
	}
}