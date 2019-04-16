#include "GameInfo.h"

GameInfo::GameInfo()
{
}

GameInfo::GameInfo(const std::string & file) : configFile(file)
{
	readConfigFile();
	printMapInfo();
}



void GameInfo::readConfigFile()
{
	std::string buff;
	std::string key;
	char delimiter = ',';

	try {
		//Open config file
		std::ifstream ifs(configFile, std::fstream::in);

		// Build gameInfoMap
		while (std::getline(ifs, buff)) {
			key = getFirstToken(buff, delimiter);
			gameInfoMap[key] = buff.substr(key.length() + 1);
		}
		ifs.close();
	}
	catch (std::fstream::failure &f){
		printf("Error %s. Could not open file %s ", configFile, f.what());
	}
}

void GameInfo::printMapInfo()
{
	for (auto& n : gameInfoMap) {
		std::cout << n.first << ":" << n.second << "\n";
	}
}


// Returns the first token given a string and a delimiter
std::string GameInfo::getFirstToken(std::string s, char delimiter)
{
	std::string token;
	std::stringstream ss;
	ss << s;
	std::getline(ss, token, delimiter);
	return token;
}
