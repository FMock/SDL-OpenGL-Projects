#include "GameInfo.h"

GameInfo::GameInfo()
{
}

GameInfo::GameInfo(const std::string & file) : configFile(file)
{
	readConfigFile();
	printFileInfo();
}



void GameInfo::readConfigFile()
{

	try {
		std::ifstream ifs(configFile, std::fstream::in);
		while (std::getline(ifs, fileInfo)) {
			parseLines(fileInfo);
		}
		ifs.close();
	}
	catch (std::fstream::failure &f){
		printf("Error %s. Could not open file %s ", configFile, f.what());
	}
}

void GameInfo::printFileInfo()
{
	for (std::string n : fileLines){
		printf("%s\n", n.c_str());
	}
}

/*
	extracts first token and places in vector
*/
void GameInfo::parseLines(std::string& str)
{
	char delim = ',';
	std::string token;
	std::stringstream ss(str);
	while (std::getline(ss, token, delim)) {
		fileLines.push_back(token);
		break;
	}
}
