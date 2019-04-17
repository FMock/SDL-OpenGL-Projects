#include "SpritesheetInfo.h"

SpritesheetInfo::SpritesheetInfo()
{
}

SpritesheetInfo::SpritesheetInfo(const std::string & file) : configFile(file)
{
	buildSpritesheetMap();
	//printMapInfo();
}

std::string SpritesheetInfo::getSpritesheetValues(const std::string key)
{
	return spritesheetMap[key];
}



void SpritesheetInfo::buildSpritesheetMap()
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
			spritesheetMap[key] = buff.substr(key.length() + 1);
		}
		ifs.close();
	}
	catch (std::fstream::failure &f) {
		printf("Error %s. Could not open file %s ", configFile.c_str(), f.what());
	}
}

void SpritesheetInfo::printMapInfo() const
{
	for (auto& n : spritesheetMap) {
		std::cout << n.first << ":" << n.second << "\n";
	}
}


// Returns the first token given a string and a delimiter
std::string SpritesheetInfo::getFirstToken(std::string s, char delimiter)
{
	std::string token;
	std::stringstream ss;
	ss << s;
	std::getline(ss, token, delimiter);
	return token;
}
