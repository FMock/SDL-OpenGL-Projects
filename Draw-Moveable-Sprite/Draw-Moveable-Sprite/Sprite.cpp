#include"Sprite.h"


Sprite::Sprite() {
}

Sprite::Sprite(GLuint tex, int w, int h, float xPos, float yPos) : texture(tex), width(w), height(h), x(xPos), y(yPos) {
}

void Sprite::draw() {
	glDrawSprite(texture, int(x), int(y), width, height);
}

void Sprite::update(float) {

}