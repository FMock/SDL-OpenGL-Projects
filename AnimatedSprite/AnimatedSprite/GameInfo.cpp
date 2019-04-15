#include "GameInfo.h"

GameInfo::GameInfo()
{
}

GameInfo::GameInfo(const std::string & file) : configFile(file)
{
	readConfigFile();
	//printFileInfo();
}



void GameInfo::readConfigFile()
{
	//std::ifstream readFile = std::ifstream();

	try {
		std::ifstream ifs(configFile, std::fstream::in);
		ifs >> fileInfo;
		ifs.close();
	}
	catch (std::fstream::failure &f){
		printf("Error %s. Could not open file %s ", configFile, f.what());
	}

	/*
	while (readFile >> fileInfo) {
	}
	*/
}

void GameInfo::printFileInfo()
{
	printf(fileInfo.c_str());
}
