#include"GLDrawFrameTester.h"

GlDrawFrameTester::GlDrawFrameTester() {}

GlDrawFrameTester::GlDrawFrameTester(GLuint image, float x, float y, int nRows, int nCols, int fWidth, int fHeight)
	: image(image),
	x(x),
	y(y),
	numberOfRows(nRows),
	numberOfColumns(nCols),
	colDivision(1.0f / numberOfColumns),
	rowDivision(1.0f / numberOfRows),
	frameWidth(fWidth),
	frameHeight(fHeight),
	frameTime(0.0f), // the amount of time the current frame has been displayed
	animFPS(24.0f)   // default is 24.0f
{
	// These initializations were necessary since above initializations didn't work
	rowDivision = 1.0f / float(numberOfRows);
	colDivision = 1.0f / float(numberOfColumns);
	change_x = 0.0f;
	change_y = 0.0f;
	currentAnimation = 0;

	//animations.push_back(Animation(6, 5, 0, "explosion", rowDivision, colDivision, 0));
	
	animations.push_back(Animation(8, 1, 0, "star", rowDivision, colDivision, 0));
	animations.push_back(Animation(8, 1, 1, "lightning", rowDivision, colDivision, 0));
	animations.push_back(Animation(8, 1, 2, "numbers", rowDivision, colDivision, 0));
	animations.push_back(Animation(8, 1, 3, "cogwheel", rowDivision, colDivision, 0));
	animations.push_back(Animation(8, 1, 4, "triangle", rowDivision, colDivision, 0));
	animations.push_back(Animation(8, 1, 5, "greendot", rowDivision, colDivision, 0));
	
}

void GlDrawFrameTester::draw() {

	//glDrawFrame(image, x, y, 100, 100, currentFrame.s1, currentFrame.s2, currentFrame.t1, currentFrame.t2);
	glDrawFrame(image,
		x,
		y,
		frameWidth,
		frameHeight,
		animations.at(currentAnimation).currentFrame.s1,
		animations.at(currentAnimation).currentFrame.s2,
		animations.at(currentAnimation).currentFrame.t1,
		animations.at(currentAnimation).currentFrame.t2);
}

void GlDrawFrameTester::update(float deltaTime) {
	x += change_x * deltaTime;
	y += change_y * deltaTime;

	// update how long the current frame has been displayed
	frameTime += deltaTime;

	// time to switch to the next frame?
	if (frameTime > (1.0f / animFPS)) {
		animations.at(currentAnimation).nextFrame(frameTime, animFPS);
		frameTime = fmod(frameTime, 1.0f / animFPS);
	}
}

void GlDrawFrameTester::setRowDivision(float rowDiv) {
	this->rowDivision = rowDiv;
}

void GlDrawFrameTester::setColDivision(float colDiv) {
	this->colDivision = colDiv;
}

int GlDrawFrameTester::getCurrentAnimation() const {
	return currentAnimation;
}

void GlDrawFrameTester::setCurrentAnimation(unsigned int a) {
	if (a >= 0 && a < animations.size())
		currentAnimation = a;
}

void GlDrawFrameTester::setAnimFPS(float fps) {
	if (fps > 0 && fps != this->animFPS) {
		animFPS = fps;
	}
}

float GlDrawFrameTester::getAnimFPS() const
{
	return this->animFPS;
}

std::string GlDrawFrameTester::to_string() const {
	std::ostringstream oss;

	oss << "Current animation " << currentAnimation << "\n"
		<< "animations.size() " << animations.size() << "\n"
		<< "rowDivision " << rowDivision << "\n"
		<< "colDivision " << colDivision << "\n"
		<< "Frame s1 " << animations.at(currentAnimation).currentFrame.s1 << "\n"
		<< "Frame s2 " << animations.at(currentAnimation).currentFrame.s2 << "\n"
		<< "Frame t1 " << animations.at(currentAnimation).currentFrame.t1 << "\n"
		<< "Frame t2 " << animations.at(currentAnimation).currentFrame.s2 << "\n"
		<< "frameWidth " << frameWidth << "\n"
		<< "frameHeigjht " << frameHeight << "\n"
		<< "total animation frame count " << animations.at(currentAnimation).getTotalFrameCount() << "\n"
		<< "animation frame counter " << animations.at(currentAnimation).getframeCount() << "\n"
		<< "animation name " << animations.at(currentAnimation).getName() << "\n"
		<< "X " << x << "\n"
		<< "y " << y << "\n";

	return oss.str();
}
