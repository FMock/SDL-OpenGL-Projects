#ifndef MOVEABLESPRITE_H
#define MOVEABLESPRITE_H
#include "Sprite.h"
#include<string>
#include<sstream>
#include<memory>
#include"DrawUtils.h"
#include"AnimationInfo.h"


// The name of this class says it all - 
// MoveableSprite is a non-static sprite, that can be moved

class MoveableSprite : public Sprite {

public:
	MoveableSprite();
	MoveableSprite(GLuint, int, int, float, float, std::string);

	// Gets image file info from AnimationInfo using string parameter
	//MoveableSprite(int, int, float, float, AnimationInfo*, std::string);
	MoveableSprite(int, int, float, float, std::shared_ptr<AnimationInfo>, std::string);

	~MoveableSprite();

	void update(float);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stop();
	std::string getName() const;
	std::string to_string() const;

private:
	std::string name;
	std::string getFileInfo(const std::string&);
	//SpritesheetInfo* spritesheetInfo;
	std::shared_ptr<AnimationInfo> ptrAnimationInfo;

protected:
	float change_x;
	float change_y;
	float speed_x;
	float speed_y;
};

#endif // !MOVEABLESPRITE_H
