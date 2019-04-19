#pragma once
#ifndef ANIMATIONDEF_H
#define ANIMATIONDEF_H

#include<vector>
#include<map>
#include"DrawUtils.h"
#include"Animation.h"

class AnimationDef {
public:
	AnimationDef();

	/* AnimationDef.h
	 * param rows - integer - total rows on the spritesheet
	 * param cols - integer - total columns on the spritesheet
	 * param fWidth - integer - frame width on spritesheet (assumed all frames are same size)
	 * param fHeight - integer - frame height on spritesheet (assumed all frames are same size)
	 */
	AnimationDef(int rows, int cols);
	void update(float);
	int getCurrentAnimation()const;
	void setCurrentAnimation(unsigned int);
	void setAnimFPS(float fps);
	float getAnimFPS() const;
	std::string to_string() const;
	std::vector<Animation> animations;

private:
	float frameTime; // the amount of time the current frame has been displayed
	float animFPS;   // default is 24.0f
	int currentAnimation;
	float colDivision;
	float rowDivision;
	int numberOfRows; // total number of rows on spritesheet
	int numberOfColumns; // total number of columns on spritesheet
	int frameWidth;
	int frameHeight;
};

#endif