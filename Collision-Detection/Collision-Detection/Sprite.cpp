#include"Sprite.h"


Sprite::Sprite() {
}

Sprite::Sprite(GLuint tex, int w, int h, float xPos, float yPos) : 
	texture(tex), width(w), height(h), x(xPos), y(yPos), box(x, y, w, h), hasCollided(true) {
}

void Sprite::draw() {
	glDrawSprite(texture, int(x), int(y), width, height);
}

// Sprite is static and x does not change as a function of change of x and delta time
void Sprite::update(float dt) {
	x = x;
	y = y;
	box.x = x;
	box.y = y;
}

void Sprite::sethasCollided(bool b) {
	hasCollided = b;
}

AABB& Sprite::getBox(){
	return this->box;
}

std::string Sprite::to_string() const {
	std::ostringstream oss;
	oss << "has collided=" << hasCollided << "\n"
		<< "box x=" << box.x << "\n"
		<< "box y=" << box.y << "\n"
		<< "box w=" << box.w << "\n"
		<< "box h=" << box.h << "\n";
	/*
	oss << "change_x=" << change_x << "\n"
		<< "change_y=" << change_y << "\n";
	*/
	return oss.str();
}
