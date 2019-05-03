#include"Sprite.h"


Sprite::Sprite() {
}

Sprite::Sprite(GLuint tex, int w, int h, float xPos, float yPos) : 
	texture(tex), 
	width(w), 
	height(h), 
	x(xPos), 
	y(yPos), 
	box(x, y, w, h), 
	position(Vector2D(xPos, yPos)), 
	hasCollided(true) 
{
	change_x = 0.0;
	change_y = 0.0;
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

void Sprite::setX(float x) {

	this->x = x;
}
void Sprite::setY(float y) {
	this->y = y;
}

std::string Sprite::to_string() const {
	std::ostringstream oss;
	oss << "has collided=" << hasCollided << "\n"
		<< "box x=" << box.x << "\n"
		<< "box y=" << box.y << "\n"
		<< "box w=" << box.w << "\n"
		<< "box h=" << box.h << "\n";
	return oss.str();
}

void Sprite::setWidth(int w){
	if (w > 0) { width = w; }
}

void Sprite::setHeight(int h){
	if (h > 0) { height = h; }
}
