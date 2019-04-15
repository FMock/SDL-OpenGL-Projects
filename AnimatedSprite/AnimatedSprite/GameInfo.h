#pragma once
#ifndef GAMEINFO_H
#define GAMEINFO_H
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

class GameInfo {
public:
	GameInfo();
	GameInfo(const std::string &file);
	std::string fileInfo;
	std::vector<std::string> fileLines;
private:
	const std::string configFile;
	void readConfigFile();
	void printFileInfo();
	void parseLines(std::string&);
};

#endif // !GAMEINFO_H
