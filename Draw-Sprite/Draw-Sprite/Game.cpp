#include "Game.h"

Game::Game()
	:window(nullptr)
	, glContext(nullptr)
	, mTicksCount(0)
	, mIsRunning(true)
{}

// Initialize the game
bool Game::Initialize() {

	//Use OpenGL 3.1 core
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// Initialize SDL.
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Could not initialize SDL. ErrorCode=%s\n", SDL_GetError());
		return 1;
	}

	// Create the window and OpenGL context.
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	//...
	//SDL_WINDOW_OPENGL);

	window = SDL_CreateWindow(
		"Draw sprite using OpenGL Demo",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if (!window) {
		fprintf(stderr, "Could not create window. ErrorCode=%s\n", SDL_GetError());
		SDL_Quit();
		return 1; //return false
	}

	// create openGL context
	glContext = SDL_GL_CreateContext(window);

	if (glContext == NULL) {
		// Display error message
		printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	// Initialize glew and make sure we have a recent version of OpenGL.
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK) {
		fprintf(stderr, "Could not initialize glew. ErrorCode=%s\n", glewGetErrorString(glewError));
		SDL_Quit();
		return 1;
	}
	if (GLEW_VERSION_2_0) {
		fprintf(stderr, "OpenGL 2.0 or greater supported: Version=%s\n",
			glGetString(GL_VERSION));
	}
	else {
		fprintf(stderr, "OpenGL max supported version is too low.\n");
		SDL_Quit();
		return 1;
	}

	// Setup OpenGL state.
	glViewport(0, 0, 800, 600);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 800, 600, 0, 0, 100);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Create the Sprite
	spriteSize[0] = 44;
	spriteSize[1] = 55;
	sprite = Sprite(glTexImageTGAFile("images/magikarp.tga", &spriteSize[0], &spriteSize[1]), 44, 55, 100.0f, 100.0f);

	return true;
}

// Runs the game loop until the game is over
void Game::RunLoop() {

	while (mIsRunning) {

		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}


// Below are helper functions for the game loop
void Game::ProcessInput() {

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
			// If we get an SDL_QUIT event, end loop
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}

	// Get state of keyboard
	const Uint8* state = SDL_GetKeyboardState(NULL);
	// If escape is pressed, also end loop
	if (state[SDL_SCANCODE_ESCAPE]) {
		mIsRunning = false;
	}

}

void Game::UpdateGame() {

}

void Game::GenerateOutput() {

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Game drawing goes here.
	sprite.draw();

	// Present the most recent frame.
	SDL_GL_SwapWindow(window);
}

// Shutdown the game
void Game::Shutdown() {

	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();

}