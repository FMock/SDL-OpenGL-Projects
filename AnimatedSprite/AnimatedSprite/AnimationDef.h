#pragma once
#ifndef ANIMATIONDEF_H
#define ANIMATIONDEF_H

#include<vector>
#include<map>
#include<sstream>
#include<memory> //std::shared_ptr<>
#include"DrawUtils.h"
#include"Animation.h"
#include"AnimationInfo.h"

class AnimationDef {
public:
	AnimationDef();

	/* AnimationDef.h
	 * param rows - integer - total rows on the spritesheet
	 * param cols - integer - total columns on the spritesheet
	 * param fWidth - integer - frame width on spritesheet (assumed all frames are same size)
	 * param fHeight - integer - frame height on spritesheet (assumed all frames are same size)
	 */
	AnimationDef(int rows, int cols, const std::string& name, std::shared_ptr<AnimationInfo>);
	~AnimationDef();
	std::shared_ptr<AnimationInfo> ptrAnimationInfo;
	void update(float);
	int getCurrentAnimation()const;
	void setCurrentAnimation(unsigned int);
	void setAnimFPS(float fps);
	float getAnimFPS() const;
	std::string to_string() const;
	std::vector<Animation> animations;

private:

	// this enum depends on the structure of the file .animations. //TO DO: remove this dependancy
	// this enum is used in this constructor when creating Animation objects
	enum animationParamPosition{NUMBER_OF_COLUMNS=1, NUMBER_OF_ROWS, STARTING_ROW, NAME, FACING_DIR};

	std::string getAnimationParamInfoAtPos(const std::string & line, char delimiter, int pos);
	int stringToInt(std::string& s);
	float frameTime; // the amount of time the current frame has been displayed
	float animFPS;   // default is 24.0f
	int currentAnimation;
	float colDivision;
	float rowDivision;
	int numberOfRows; // total number of rows on spritesheet
	int numberOfColumns; // total number of columns on spritesheet
	int frameWidth;
	int frameHeight;
	std::string name;
};

#endif