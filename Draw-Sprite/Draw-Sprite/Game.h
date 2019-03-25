#pragma once
#define SDL_MAIN_HANDLED
#include<SDL.h>
#include<GL/glew.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

// Vector2 struct just stores x/y coordinates
struct Vector2 {

	float x;
	float y;
};

// Game class
class Game {

public:
	Game();

	// Initialize the game
	bool Initialize();

	// Runs the game loop until the game is over
	void RunLoop();

	// Shutdown the game
	void Shutdown();

private:
	// Helper functions for the game loop
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	// Window created by SDL
	SDL_Window* window;

	//OpenGL context to draw in the window using OpenGL
	SDL_GLContext glContext;

	// Number of ticks since start of game
	Uint32 mTicksCount;

	// Game should continue to run
	bool mIsRunning;

	// Game Window Size
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

};
