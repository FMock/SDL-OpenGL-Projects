#include"Game.h"

/*
	Frank Mock
	3/24/2019
	This program draws an SDL2 window with an OpenGL context
*/

int main(int argc, char** argv){

	Game game;
	bool success = game.Initialize();
	if (success)
	{
		game.RunLoop();
	}
	game.Shutdown();

	return 0;
}
