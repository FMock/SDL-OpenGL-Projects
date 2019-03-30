#include"Sprite.h"


Sprite::Sprite() {
}

Sprite::Sprite(GLuint tex, int w, int h, float xPos, float yPos) : 
	texture(tex), width(w), height(h), x(xPos), y(yPos), box(x, y, w, h), hasCollided(true) {
}

void Sprite::draw() {
	glDrawSprite(texture, int(x), int(y), width, height);
}

void Sprite::sethasCollided(bool b) {
	hasCollided = b;
}

AABB& Sprite::getBox(){
	return this->box;
}

