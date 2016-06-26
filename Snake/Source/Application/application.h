#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include "models/line.h"
#include "containers/playground.h"
#include "managers/shadersmanager.h"
#include "containers/scoreboard.h"

class Application
{
public:
	Application();

	void close();

	void run();

	~Application();

protected:

private:

	void render();

	// Initializes SDL and OpenGL window
	bool initialize();

	unsigned int _width;
	unsigned int _height;

	char* _name = "Snake game";

	SDL_Window* _mainWindow;

	Playground* _playground;

	Line* _line;
};

#endif // !APPLICATION_H