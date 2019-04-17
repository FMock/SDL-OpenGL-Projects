#pragma once
#ifndef SPRITESHEETINFO_H
#define SPRITESHEETINFO_H
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<map>

/*
  SpritesheetInfo provides spritesheet information that other MoveableSprites or
  AnimatedSprites can use for initialization.
  SpritesheetInfo gets the information by reading a configuration file named
  .anim_config
  
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

class SpritesheetInfo {
public:
	SpritesheetInfo();
	SpritesheetInfo(const std::string &file);
	std::string getSpritesheetValues(const std::string);

private:
	std::map<std::string, std::string> spritesheetMap;
	const std::string configFile;
	void buildSpritesheetMap();
	void printMapInfo() const;
	std::string getFirstToken(std::string, char);
};
#endif // !SPRITESHEETINFO_H
