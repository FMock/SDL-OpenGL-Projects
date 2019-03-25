#include"Game.h"

/*
	Frank Mock
	3/24/2019
	This program draws an SDL2 window with an OpenGL context.
	A texture (sprite) is drawn in the window
*/

int main(int argc, char** argv) {

	Game game;
	bool success = game.Initialize();
	if (success)
	{
		game.RunLoop();
	}
	game.Shutdown();

	return 0;
}
