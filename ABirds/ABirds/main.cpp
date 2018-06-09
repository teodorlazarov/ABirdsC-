#include "Game.h"
#include <iostream>

int main(int argc, const char * argv[])
{
	Game* game = new Game(1600, 900);
	
	game->GameLoop();

	delete game;

	return 0;
}