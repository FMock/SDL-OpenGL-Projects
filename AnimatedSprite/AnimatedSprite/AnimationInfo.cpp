#include "AnimationInfo.h"

AnimationInfo::AnimationInfo()
{
}

AnimationInfo::AnimationInfo(const std::string & f1, const std::string & f2) : configFile(f1), animationsFile(f2)
{
	buildSpritesheetMap();
	buildAnimationMap();
	//printMapInfo();
}

std::string AnimationInfo::getSpritesheetValues(const std::string key)
{
	return spritesheetMap[key];
}

std::vector<std::string> AnimationInfo::getAnimationValues(const std::string& key){

	auto vals = animationMap.equal_range(key);

	std::vector<std::string> values;

	for (std::multimap<std::string, std::string>::iterator it = vals.first; it != vals.second; it++) {

		values.push_back(it->second);
	}

	return values;
}



void AnimationInfo::buildSpritesheetMap()
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

void AnimationInfo::buildAnimationMap(){
	std::string buff;
	std::string key;
	char delimiter = ',';

	try {
		//Open config file
		std::ifstream ifs(animationsFile, std::fstream::in);

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

void AnimationInfo::printMapInfo() const
{
	for (auto& n : animationMap) {
		std::cout << n.first << ":" << n.second << "\n";
	}
}


// Returns the first token given a string and a delimiter
std::string AnimationInfo::getFirstToken(std::string s, char delimiter)
{
	std::string token;
	std::stringstream ss;
	ss << s;
	std::getline(ss, token, delimiter);
	return token;
}
