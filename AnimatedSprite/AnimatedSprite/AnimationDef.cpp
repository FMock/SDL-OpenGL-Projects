#include "AnimationDef.h"

AnimationDef::AnimationDef()
{
}


AnimationDef::AnimationDef(int rows, int cols, const std::string& name, std::shared_ptr<AnimationInfo> ptrAnimInfo)
	: numberOfRows(rows),
	  numberOfColumns(cols),
	  name(name),
	  ptrAnimationInfo(ptrAnimInfo),
	  frameTime(0.0f), // the amount of time the current frame has been displayed
	  animFPS(6.0f)   // default is 24.0f
{

	rowDivision = 1.0f / float(numberOfRows);
	colDivision = 1.0f / float(numberOfColumns);
	currentAnimation = 0;

	// Get animation info and build Animation objects
	std::vector<std::string> animInfo = ptrAnimationInfo->getAnimationValues(this->name);
	
	for (auto n : animInfo) {
	
		std::string a = getAnimationParamInfoAtPos(n, ',', animationParamPosition::NUMBER_OF_COLUMNS);
		std::string b = getAnimationParamInfoAtPos(n, ',', animationParamPosition::NUMBER_OF_ROWS);
		std::string c = getAnimationParamInfoAtPos(n, ',', animationParamPosition::STARTING_ROW);
		std::string d = getAnimationParamInfoAtPos(n, ',', animationParamPosition::NAME);
		std::string e = getAnimationParamInfoAtPos(n, ',', animationParamPosition::FACING_DIR);

		                  // Animation(columns, # rows animation consists of, starting row, name, rowDiv, colDiv, facing enum #)
		animations.push_back(Animation(stringToInt(a), stringToInt(b), stringToInt(c), d, rowDivision, colDivision, stringToInt(e)));
	}
}

AnimationDef::~AnimationDef(){
	ptrAnimationInfo.reset();
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

std::string AnimationDef::getAnimationParamInfoAtPos(const std::string & line, char delimiter, int pos){
	std::string buff;
	std::stringstream ss;
	ss << line;
	for (auto i = 0; i < pos; i++) {
		std::getline(ss, buff, delimiter);
	}
	return buff;
}

int AnimationDef::stringToInt(std::string& s) {
	std::stringstream ss(s);
	int n;
	ss >> n;
	return n;
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

