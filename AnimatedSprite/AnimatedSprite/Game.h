#pragma once
#define SDL_MAIN_HANDLED
#include<SDL.h>
#include<GL/glew.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<memory> //std::shared_ptr<>
#include"MoveableSprite.h"
#include"AnimatedSprite.h"
#include"DrawUtils.h"
#include"GLDrawFrameTester.h"
#include"SpritesheetInfo.h"

// Vector2 struct just stores x/y coordinates
struct Vector2 {

	float x;
	float y;
};

// Game class
class Game {

public:
	Game();
	~Game();

	// Initialize the game
	bool Initialize();

	// Runs the game loop until the game is over
	void RunLoop();

	// Shutdown the game
	void Shutdown();

	//Shared with other game objects
	std::shared_ptr<SpritesheetInfo> ptrSpritesheetInfo;

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
	Uint32 ticksCount;

	// Game should continue to run
	bool mIsRunning;

	// Sprite
	MoveableSprite sprite;
	Sprite sprite2; //static non-moveable sprite
	AnimatedSprite sprite3;
	int spriteSize[2];

	GlDrawFrameTester drawFrameTester;
	int spriteSheetSizes[2];


	// Game Window Size
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

};
