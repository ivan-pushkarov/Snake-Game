#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H

#include <SDL.h>
#include <glew.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <SDL_types.h>
#include <SDL_opengl.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <freetype\ftglyph.h>
#include <freetype\freetype.h>
#include <freetype\freetype.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Settings {
	
	static const double epsilion = 0.000001;
	
	static const unsigned short QuadSize = 1;
	static const unsigned short Unit = 1;

	static const unsigned short SnakeSpeed = 250; // ms
	static const unsigned short LevelCompletedDelay = 1000; // ms
	static const unsigned short NumberOfLevels = 10;
	static const unsigned short SnakeMagnitude = 10;
	static const unsigned short IncreaseSpeed = 20; //ms

	static const unsigned short ApplicationWidth = 400;
	static const unsigned short ApplicationHeight = 400;
	static const unsigned short PlaygroundHeight = 20;
	static const unsigned short PlaygroundWidth = 10;

	static const unsigned short DefaultFontSize = 12;
	static const unsigned short BigFontSize = 22;

	static const unsigned short DefaultLineWidth = 4;

	static const std::string ModelLine = "Line";
	static const std::string ModelSnake = "Snake";
	static const std::string ModelMouse = "Mouse";
	static const std::string ModelPlayground = "Playground";

	static const std::string HiScoreFilePath = "./HiScore/HiScore.txt";

	static const std::string RegularFont = "./Fonts/OpenSans-Regular.ttf";
	static const std::string BoldFont = "./Fonts/OpenSans-Bold.ttf";

	static const std::string BasicVertexShader = "./Shaders/BasicVertexShader.txt";
	static const std::string BasicFragmentShader = "./Shaders/BasicFragmentShader.txt";
	static const std::string BasicShader = BasicVertexShader + BasicFragmentShader;

	static const std::string TextureVertexShader = "./Shaders/TextureVertexShader.txt";
	static const std::string TextureFragmentShader = "./Shaders/TextureFragmentShader.txt";
	static const std::string TextureShader = TextureVertexShader + TextureFragmentShader;

	static const glm::vec3 UP = glm::vec3(0.0, Unit, 0.0);
	static const glm::vec3 RIGHT = glm::vec3(Unit, 0.0, 0.0);
	static const glm::vec3 DOWN = glm::vec3(0.0, -Unit, 0.0);
	static const glm::vec3 LEFT = glm::vec3(-Unit, 0.0, 0.0);

	static const double Rotation = 1.5707963268; // 90 degrees in Radians
	static const glm::vec3 Scale = glm::vec3(0.0775*(0.0025*ApplicationWidth), 0.0775*(0.0025*ApplicationWidth), 0.0775*(0.0025*ApplicationWidth));

	static const glm::vec3 Distance = glm::vec3(0.085, 0.0, 0.0);

	static const glm::vec3 TextPosition = glm::vec3(0.95, -0.85, 0.0); // Scoreboard - lower right angle position
	static const glm::vec3 FinalMessagePosition(-0.845, 0.9, 0.0);

	static const glm::vec3 LineOffset = glm::vec3(0.05, 0.0, 0.0);
	static const glm::vec3 ScoreboardOffset = glm::vec3(0.5, 0.5, 0.0);
	static const glm::vec3 PlaygroundOffset = glm::vec3(-0.375, -0.04, 0.0);
	static const glm::vec3 TopLeftSquare = glm::vec3(-0.085 * (0.0025*Settings::ApplicationWidth) * PlaygroundWidth / 2, 0.085 * (0.0025*Settings::ApplicationWidth) * PlaygroundHeight / 2, 0.0) + PlaygroundOffset;
	static const glm::vec3 BottomRightSquare = glm::vec3(0.085 * (0.0025*Settings::ApplicationWidth) * (PlaygroundWidth / 2 - 1), -0.085 * (0.0025*Settings::ApplicationWidth) * (PlaygroundHeight / 2 - 1), 0.0) + PlaygroundOffset;

	// Colors
	static const glm::vec4 PlaygroundColor = glm::vec4(0.568627, 0.607843, 0.588235, 1.0);
	static const glm::vec4 MainColor = glm::vec4(0.647058, 0.725490, 0.686274, 1.0);
	static const glm::vec4 TextColor = glm::vec4(0.0, 0.0, 0.0, 1.0);
	static const glm::vec4 LineColor = glm::vec4(0.0, 0.0, 0.0, 1.0);
	static const glm::vec4 MouseColor = glm::vec4(0.0, 0.0, 0.0, 1.0);
	static const glm::vec4 SnakeColor = glm::vec4(0.0, 0.0, 0.0, 1.0);

};

#endif // !SETTINGS_H