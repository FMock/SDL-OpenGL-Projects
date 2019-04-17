#pragma once
#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include<GL/glew.h>
#include<sstream>
#include<memory> //std::shared_ptr<>
#include"Sprite.h"
#include"AnimationDef.h"
#include"SpritesheetInfo.h"
#include"DrawUtils.h"


/* AnimatedSprite.h
 * AnimatedSprite is a sprite that uses a list of animations to graphically represent it's
 * actions on screen. The AnimationDef member contains the list of animations that this
 * AnimatedSprite uses and animation centric information common to all the animations.
 * */

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(float, float, std::shared_ptr<SpritesheetInfo>, const std::string&);
	~AnimatedSprite();
	std::shared_ptr<SpritesheetInfo> ptrSpritesheetInfo;
	AnimationDef animationDef;
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
	enum facingDirections { LEFT, RIGHT, UP, DOWN };
	std::string name;
	std::string to_string() const;

private:
	std::string getFileInfo(const std::string&);

protected:
	float speed_x;
	float speed_y;
};
#endif