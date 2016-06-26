#pragma once
#ifndef FONTSMANAGER_H
#define FONTSMANAGER_H

#include <iostream>
#include "settings/settings.h"
#include <unordered_map>

class Fontsmanager {
public:

	static Fontsmanager& getInstance();

	bool init();

	const FT_Face getFace(const std::string);

	bool loadFont(const char*);

	~Fontsmanager();

private:

	Fontsmanager();

	static Fontsmanager* instance;

	bool readFontFile(const char*);

	FT_Library _ft;

	int _fontNumber;

	unsigned int _fontFileSize;

	std::vector<std::vector<char>> _font;

	std::unordered_map<std::string, FT_Face> _fonts;

};

#endif // !FONTSMANAGER_H
