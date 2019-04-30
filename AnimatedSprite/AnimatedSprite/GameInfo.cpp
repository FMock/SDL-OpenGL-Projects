#include "GameInfo.h"

GameInfo::GameInfo()
{
}

GameInfo::GameInfo(const std::string & f1, const std::string & f2) : configFile(f1), animationsFile(f2)
{
	buildGameInfoMap();
	//printMapInfo();
}

std::string GameInfo::getGameInfoValue(const std::string key)
{
	return gameInfoMap[key];
}


void GameInfo::buildGameInfoMap()
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
		printf("Error %s. Could not open file %s ", configFile.c_str(), f.what());
	}
}

void GameInfo::buildAnimationMap(){
	std::string buff;
	std::string key;
	char delimiter = ',';

	try {
		//Open config file
		std::ifstream ifs(configFile, std::fstream::in);

		// Build gameInfoMap
		while (std::getline(ifs, buff)) {
			key = getFirstToken(buff, delimiter);
			animationMap.insert(std::make_pair(key, buff.substr(key.length() + 1)));
		}
		ifs.close();
	}
	catch (std::fstream::failure &f) {
		printf("Error %s. Could not open file %s ", configFile.c_str(), f.what());
	}
}

void GameInfo::printMapInfo()
{
	for (auto& n : animationMap) {
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
