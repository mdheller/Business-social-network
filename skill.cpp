#include "skill.hpp"

Skill::Skill(std::string skillName) {
	name = skillName;
	skillRate = 0;
}

void Skill::endorse (std::string endorserID, float endorserScore) {
	for (int i = 0 ; i < endorsers.size() ; i++) {
		if (endorsers[i] == endorserID)
			return;
	}
	skillRate += endorserScore;
	endorsers.push_back(endorserID);
}

void Skill::printSkill() {
	std::cout << name << SPACE << '-' << SPACE << std::setprecision(3) << skillRate << std::endl;
}