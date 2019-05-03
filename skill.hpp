#ifndef __SKILL_H__
#define __SKILL_H__

#include <iomanip>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

#define SPACE ' '
class Skill {
private:
	std::string name;
	float skillRate;
	std::vector <std::string> endorsers;
public:
	Skill(std::string skillName);
	float getSkillRate() { return skillRate; }
	std::string getSkillName() { return name; }
	void endorse (std::string endorserID, float endorserScore);
	void printSkill();
	float calculateEndorseScore () {return sqrt (endorsers.size() + 1);}
};

#endif