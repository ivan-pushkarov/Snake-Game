//#include <vld.h>
#include <iostream>
#include "Application/Application.h"

int main(int argc, char* argv[])
{
	srand((unsigned int)(time(NULL)));

	Application game;

	game.run();

	return 0;
}