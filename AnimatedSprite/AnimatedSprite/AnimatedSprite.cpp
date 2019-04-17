#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::AnimatedSprite(float x, float y, std::shared_ptr<SpritesheetInfo> ptrSSInfo, const std::string& name) 
	: ptrSpritesheetInfo(ptrSSInfo),
	  name(name),
	  Sprite(glTexImageTGAFile(this->getFileInfo(ptrSSInfo->getSpritesheetValues(name)).c_str()), 0, 0, x, y)
{
	/*w=40, h=50 get values from spritesheetInfo*/
	setWidth(100);
	setHeight(100);
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
	glDrawSprite(texture, int(x), int(y), width, height);
}

void AnimatedSprite::changeAnimation(int x)
{
}

int AnimatedSprite::getCurrentAnimation() const
{
	return 0;
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

std::string AnimatedSprite::to_string() const
{
	return std::string();
}
