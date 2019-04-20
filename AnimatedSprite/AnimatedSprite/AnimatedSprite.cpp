#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::AnimatedSprite(float x, float y, std::shared_ptr<SpritesheetInfo> ptrSSInfo, const std::string& name) 
	: ptrSpritesheetInfo(ptrSSInfo),
	  name(name),
	  Sprite(glTexImageTGAFile(this->getFileInfo(ptrSSInfo->getSpritesheetValues(name)).c_str()), 0, 0, x, y)
{
	// Set Sprite Width
	const std::string playerInfo = ptrSSInfo->getSpritesheetValues(name);
	std::string w = getSpritesheetInfoAtPos(playerInfo, ',', WIDTH);
	setWidth(stringToInt(w));
	box.w = stringToInt(w);

	// Set Sprite Height
	std::string h = getSpritesheetInfoAtPos(playerInfo, ',', HEIGHT);
	setHeight(stringToInt(h));
	box.h = stringToInt(h);

	// Create an AnimatedDef that creates and manages the animations for sprite
	std::string r = getSpritesheetInfoAtPos(playerInfo, ',', ROWS);
	std::string c = getSpritesheetInfoAtPos(playerInfo, ',', COLUMNS);
	animationDef = AnimationDef(stringToInt(r), stringToInt(c));
}

AnimatedSprite::~AnimatedSprite()
{
	ptrSpritesheetInfo.reset();
}

void AnimatedSprite::update(float deltaTime)
{
	x += change_x * deltaTime;
	y += change_y * deltaTime;

	position.setX(x);
	box.setX(abs(x));
	position.setY(y);
	box.setY(abs(y));
	animationDef.update(deltaTime);
}

void AnimatedSprite::draw(){
	//glDrawSprite(texture, int(x), int(y), width, height);

	//glDrawFrame(image, x, y, 100, 100, currentFrame.s1, currentFrame.s2, currentFrame.t1, currentFrame.t2);
	glDrawFrame(texture,
		x,
		y,
		width,
		height,
		animationDef.animations.at(getCurrentAnimation()).currentFrame.s1,
		animationDef.animations.at(getCurrentAnimation()).currentFrame.s2,
		animationDef.animations.at(getCurrentAnimation()).currentFrame.t1,
		animationDef.animations.at(getCurrentAnimation()).currentFrame.t2);
}

void AnimatedSprite::changeAnimation(int x)
{
	animationDef.setCurrentAnimation(x);
}

void AnimatedSprite::moveLeft()
{
	change_x += -speed_x;
	change_y = 0;
}

void AnimatedSprite::moveRight(){
	change_x += speed_x;
	change_y = 0;
}

void AnimatedSprite::moveUp(){
	change_x = 0;
	change_y -= speed_y;
}

void AnimatedSprite::moveDown(){
	change_x = 0;
	change_y += speed_y;
}

void AnimatedSprite::stop(){
	change_x = 0;
	change_y = 0;
}

void AnimatedSprite::setFacingDirection(int){
}

int AnimatedSprite::getFacingDirection() const{
	return 0;
}

std::string AnimatedSprite::getFileInfo(const std::string& key){

	std::string fileInfo;
	std::stringstream ss;
	ss << key;
	getline(ss, fileInfo, ',');
	return fileInfo;
}

std::string AnimatedSprite::getSpritesheetInfoAtPos(const std::string & line, char delimiter, int pos)
{
	std::string buff;
	std::stringstream ss;
	ss << line;
	for (auto i = 0; i < pos; i++) {
		std::getline(ss, buff, delimiter);
	}
	return buff;
}

int AnimatedSprite::stringToInt(std::string& s){
	std::stringstream ss(s);
	int n;
	ss >> n;
	return n;
}

int AnimatedSprite::getCurrentAnimation() const
{
	return animationDef.getCurrentAnimation();
}

std::string AnimatedSprite::to_string() const
{
	std::ostringstream oss;
	oss << "name " << name << "\n"
		<< "width " << width << "\n"
		<< "height " << height << "\n"
		<< "hasCollided " << hasCollided << "\n"
		<< "box x=" << box.x << "\n"
		<< "box y=" << box.y << "\n"
		<< "box w=" << box.w << "\n"
		<< "box h=" << box.h << "\n";
	return oss.str();
}
