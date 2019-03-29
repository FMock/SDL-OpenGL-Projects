#include"MoveableSprite.h"

MoveableSprite::MoveableSprite() {}

MoveableSprite::MoveableSprite(GLuint tex, int w, int h, float x, float y) 
	: change_x(0.0), change_y(0.0), speed_x(5.0), speed_y(5.0), Sprite(tex, w, h, x, y){}

void MoveableSprite::update(float deltaTime) {
	x += change_x * deltaTime;
	y += change_y * deltaTime;
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

std::string MoveableSprite::to_string() const{
	std::ostringstream oss;
	oss << "change_x=" << change_x << "\n"
		<< "change_y=" << change_y << "\n";
	return oss.str();
}