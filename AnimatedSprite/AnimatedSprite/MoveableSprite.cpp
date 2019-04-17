#include"MoveableSprite.h"

MoveableSprite::MoveableSprite() {}

MoveableSprite::MoveableSprite(GLuint tex, int w, int h, float x, float y, std::string name) 
	: change_x(0.0), 
	  change_y(0.0), 
	  speed_x(5.0), 
	  speed_y(5.0),
	  name(name),
	  Sprite(tex, w, h, x, y){}

MoveableSprite::MoveableSprite(int w, int h, float x, float y, SpritesheetInfo* sptInfo, std::string name) 
	: spritesheetInfo(sptInfo), 
	  change_x(0.0), 
	  change_y(0.0), 
	  speed_x(5.0), 
	  speed_y(5.0),
	  name(name),
	  Sprite(glTexImageTGAFile(this->getFileInfo(sptInfo->getSpritesheetValues(name)).c_str()), w, h, x, y)
{}

void MoveableSprite::update(float deltaTime) {
	x += change_x * deltaTime;
	y += change_y * deltaTime;
	box.x = x;
	box.y = y;
}

void MoveableSprite::moveLeft() {
	change_y = 0;
	change_x += -speed_x;
}

void MoveableSprite::moveRight() {
	change_y = 0;
	change_x += speed_x;
}

void MoveableSprite::moveUp() {
	change_x = 0;
	change_y -= speed_y;
}

void MoveableSprite::moveDown() {
	change_x = 0;
	change_y += speed_y;
}

void MoveableSprite::stop() {
	change_x = 0;
	change_y = 0;
}

std::string MoveableSprite::getName() const
{
	return this->name;
}

std::string MoveableSprite::getFileInfo(const std::string& key)
{
	std::string fileInfo;
	std::stringstream ss;
	ss << key;
	getline(ss, fileInfo, ',');
	return fileInfo;
}

std::string MoveableSprite::to_string() const{
	std::ostringstream oss;
	oss << "name " << getName() << "\n"
		<< "has collided=" << hasCollided << "\n"
		<< "box x=" << box.x << "\n"
		<< "box y=" << box.y << "\n"
		<< "box w=" << box.w << "\n"
		<< "box h=" << box.h << "\n"
	    << "change_x=" << change_x << "\n"
		<< "change_y=" << change_y << "\n";
	
	return oss.str();
}
