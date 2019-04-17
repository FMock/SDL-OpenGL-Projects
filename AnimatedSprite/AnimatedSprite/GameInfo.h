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
	GameInfo(const std::string &file);
	std::string getGameInfoValue(const std::string);
	std::map<std::string, std::string> gameInfoMap;
private:
	const std::string configFile;
	void buildGameInfoMap();
	void printMapInfo();
	std::string getFirstToken(std::string, char);
};

#endif // !GAMEINFO_H
