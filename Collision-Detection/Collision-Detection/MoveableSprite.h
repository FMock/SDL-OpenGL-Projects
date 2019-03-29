#ifndef MOVEABLESPRITE_H
#define MOVEABLESPRITE_H
#include "Sprite.h"
#include<string>
#include<sstream>

// The name of this class says it all - 
// MoveableSprite is a non-static sprite, that can be moved

class MoveableSprite : public Sprite {

public:
	MoveableSprite();
	MoveableSprite(GLuint, int, int, float, float);
	void update(float);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stop();
	std::string to_string() const;
protected:
	float change_x;
	float change_y;
	float speed_x;
	float speed_y;
};

#endif // !MOVEABLESPRITE_H
