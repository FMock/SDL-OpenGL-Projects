#include "Game.h"

Game::Game()
	:window(nullptr)
	, glContext(nullptr)
	, ticksCount(0)
	, mIsRunning(true)
{}

Game::~Game()
{
	ptrAnimationInfo.reset();
}

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
		"AnimatedSprite Demo",
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


	//Create AnimationInfo object MoveableSprites or AnimatedSprites can reference
	ptrAnimationInfo = std::make_shared<AnimationInfo>("config/.anim_config", "config/.animations");

	/* Each level of game will create various amount and variety of sprites (game objects)*/
	//sprite = MoveableSprite(glTexImageTGAFile("images/magikarp.tga"), 44, 55, 100.0f, 100.0f, "fish");
	sprite = MoveableSprite(44, 55, 100.0f, 100.0f, ptrAnimationInfo, "fish");
	//sprite3 = AnimatedSprite(40.0f, 400.0f, ptrAnimationInfo, "explosion");
	//sprite3 = AnimatedSprite(40.0f, 400.0f, ptrAnimationInfo, "dwarf");
	sprite3 = AnimatedSprite(100.0f, 10.0f, ptrAnimationInfo, "girl");

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
		switch (event.type){
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
	else if (state[SDL_SCANCODE_LEFT]) {
		sprite.moveLeft();
	}
	else if (state[SDL_SCANCODE_RIGHT]) {
		sprite.moveRight();
	}
	else if (state[SDL_SCANCODE_UP]) {
		sprite.moveUp();
	}
	else if (state[SDL_SCANCODE_DOWN]) {
		sprite.moveDown();
	}
	else if (state[SDL_SCANCODE_D]) {
		sprite3.changeAnimation(5);
		sprite3.moveRight();
	}
	else if (state[SDL_SCANCODE_A]) {
		sprite3.changeAnimation(4);
		sprite3.moveLeft();
	}
	else if (state[SDL_SCANCODE_W]) {
		sprite3.changeAnimation(3);
		sprite3.moveUp();
	}
	else if (state[SDL_SCANCODE_S]) {
		sprite3.changeAnimation(2);
		sprite3.moveDown();
	}
	else {
		sprite.stop();
		sprite3.stop();
		sprite3.changeAnimation(1);
	}
}

void Game::UpdateGame() {

	// Compute delta time
	// Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + 16))
		;

	float deltaTime = (SDL_GetTicks() - ticksCount) / 1000.0f;
	if (deltaTime > 0.05f) {

		deltaTime = 0.05f;
	}
	ticksCount = SDL_GetTicks();

	// Update the sprite
	sprite.update(deltaTime);

	// Continuously move sprite3 across the screen (and loop back around)
	sprite3.moveRight();
	if (sprite3.box.x > 800)
		sprite3.setX(-200);
	sprite3.update(deltaTime);

	// Check for sprite to sprite intersections
	if (sprite.box.boxesIntersect(sprite3.box)) {
		sprite.sethasCollided(true);
		sprite3.sethasCollided(true);
	}
	else {
		sprite.sethasCollided(false);
		sprite3.sethasCollided(false);
	}
}

void Game::GenerateOutput() {

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Game drawing goes here.
	sprite.draw();
	//printf(sprite.to_string().c_str());

	sprite3.draw();
	printf(sprite3.to_string().c_str());

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