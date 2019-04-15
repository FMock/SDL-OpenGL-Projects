#pragma once
#ifndef GAMEINFO_H
#define GAMEINFO_H
#include<string>
#include<fstream>

class GameInfo {
public:
	GameInfo();
	GameInfo(const std::string &file);
	std::string fileInfo;
private:
	const std::string configFile;
	void readConfigFile();
	void printFileInfo();
};

#endif // !GAMEINFO_H
