#include"Game.h"

/*
	Frank Mock
	3/29/2019
	This program draws an SDL2 window with an OpenGL context.
	Textures (moveable sprites) are drawn in the window.
	When one texture overlaps with another, a collision is
	detected.
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
