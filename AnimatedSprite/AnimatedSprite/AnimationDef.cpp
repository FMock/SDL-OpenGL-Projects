#include "AnimationDef.h"

AnimationDef::AnimationDef()
{
}



AnimationDef::AnimationDef(int rows, int cols) 
	: numberOfRows(rows),
	  numberOfColumns(cols),
	  frameTime(0.0f), // the amount of time the current frame has been displayed
	  animFPS(24.0f)   // default is 24.0f
{

	rowDivision = 1.0f / float(numberOfRows);
	colDivision = 1.0f / float(numberOfColumns);
	currentAnimation = 0;

	// Create animations for vector by reading animation file
	/*FOR NOW WE WILL TEST WITH THIS*/
	animations.push_back(Animation(6, 5, 0, "explosion", rowDivision, colDivision, 0));
}

void AnimationDef::update(float deltaTime) {

	// update how long the current frame has been displayed
	frameTime += deltaTime;

	// time to switch to the next frame?
	if (frameTime > (1.0f / animFPS)) {
		animations.at(currentAnimation).nextFrame(frameTime, animFPS);
		frameTime = fmod(frameTime, 1.0f / animFPS);
	}
}

std::string AnimationDef::to_string() const {
	return std::string();
}

int AnimationDef::getCurrentAnimation() const {
	return currentAnimation;
}


void AnimationDef::setCurrentAnimation(unsigned int a){
	if (a >= 0 && a < animations.size())
		currentAnimation = a;
}

void AnimationDef::setAnimFPS(float fps) {
	if (fps > 0 && fps != this->animFPS) {
		animFPS = fps;
	}
}

float AnimationDef::getAnimFPS() const
{
	return this->animFPS;
}

