#pragma once
#ifndef GAMEINFO_H
#define GAMEINFO_H
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<map>

class GameInfo {
public:
	GameInfo();
	GameInfo(const std::string &file, const std::string & file2);
	std::string getGameInfoValue(const std::string);
	std::map<std::string, std::string> gameInfoMap;
	std::map<std::string, std::string> animationMap;
private:
	const std::string configFile;
	const std::string animationsFile;
	void buildGameInfoMap();
	void buildAnimationMap();
	void printMapInfo();
	std::string getFirstToken(std::string, char);
};

#endif // !GAMEINFO_H
