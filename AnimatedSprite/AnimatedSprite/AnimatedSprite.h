#pragma once
#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include<GL/glew.h>
#include<sstream>
#include<memory> //std::shared_ptr<>
#include"Sprite.h"
#include"AnimationDef.h"
#include"AnimationInfo.h"
#include"DrawUtils.h"


/* AnimatedSprite.h
 * AnimatedSprite is a sprite that uses a list of animations to graphically represent it's
 * actions on screen. The AnimationDef member contains the list of animations that this
 * AnimatedSprite uses and animation centric information common to all the animations.
 * */

const float MAX_CHANGE_X = 150.0f;
const float MAX_CHANGE_Y = 150.0f;

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(float, float, std::shared_ptr<AnimationInfo>, const std::string&);
	~AnimatedSprite();
	std::shared_ptr<AnimationInfo> ptrAnimationInfo;
	virtual void update(float deltaTime);
	virtual void draw();
	void changeAnimation(int x); // tells animationDef to change to animation x
	int getCurrentAnimation() const;
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stop();
	void setFacingDirection(int);
	int getFacingDirection() const;
	int facingDirection;
	enum SPRITESHEET_INFO { IMAGE = 1, ROWS, COLUMNS, WIDTH, HEIGHT };
	enum FACING_DIRECTIONS { LEFT, RIGHT, UP, DOWN };
	std::string name;
	std::string to_string() const;

private:
	AnimationDef animationDef;
	std::string getFileInfo(const std::string&);
	std::string getSpritesheetInfoAtPos(const std::string& line, char delimiter, int pos);
	int stringToInt(std::string& s);

protected:
	float change_x;
	float change_y;
	float speed_x;
	float speed_y;
};
#endif