#pragma once
#ifndef ANIMATIONINFO_H
#define ANIMATIONINFO_H

#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<vector>

/*
  AnimationInfo provides spritesheet and animation info that other MoveableSprites or
  AnimatedSprites can use for initialization.
  AnimationInfo gets the information by reading the configuration files named
  .anim_config and .animations

  Sample contents of .anim_config
	fish,images/magikarp.tga,8,8,100,100
	player,images/dwarf.tga,9,9,50,50
	skeleton,images/skeleton.tga,6,6,50,50

	Each line contains comma separated string tokens
	The first token is the name and is used as a key to the generated map
	The second token is the path and file name of associated spritesheet
	The third token is the number of rows in the spritesheet
	The third token is the number of columns in the spritesheet
	The fourth token is the width of a frame in pixels
	The fifth token is the height of a frame in pixels
*/

class AnimationInfo {
public:
	AnimationInfo();
	AnimationInfo(const std::string &file, const std::string &file2);
	std::string getSpritesheetValues(const std::string);
	std::vector<std::string> getAnimationValues(const std::string&);

private:
	std::map<std::string, std::string> spritesheetMap;
	std::multimap<std::string, std::string> animationMap;
	const std::string configFile;
	const std::string animationsFile;
	void buildSpritesheetMap();
	void buildAnimationMap();
	void printMapInfo() const;
	std::string getFirstToken(std::string, char);
};

#endif // !ANIMATIONINFO_H
