#include "user.hpp"

User::User(std::string userFirstName, std::string userLastName, std::string userEmailAddress, std::string userBiography) {
	firstName = userFirstName;
	lastName = userLastName;
	emailAddress = userEmailAddress;
	biography = userBiography;
}

void User::addExperience (std::string companyId, std::string title, std::string startsAt , std::string endsAt) {
	Experience newExperience (companyId, title, startsAt, endsAt);
	experiences.push_back(newExperience);
}

void User::assignSkill (std::string name) {
	Skill newSkill (name);
	skills.push_back(newSkill);
}

void User::addFollower (std::string ID) {
	for (int i = 0 ; i < followers.size() ; i++)
		if (followers[i] == ID)
			return;
	followers.push_back(ID);
}

bool User::isSkilledEnough (std::string skillName, float minimumSkillRate) {
	for (int i = 0 ; i < skills.size() ; i++)
		if (skills[i].getSkillName() == skillName)
			if (skills[i].getSkillRate() >= minimumSkillRate)
				return true;
			else
				return false;
	return false;
}

void User::endorseSkill (std::string endorserID, float endorserScore, std::string skillName) {
	if (findSkill(skillName) != NOTFOUND) {
		skills[findSkill(skillName)].endorse(endorserID, endorserScore);
	}
}

float User::calculateEndorseScore (std::string skillName) {
	if(findSkill(skillName) != NOTFOUND)
		return skills[findSkill(skillName)].calculateEndorseScore();
	return 1;
}

int User::findSkill (std::string skillName) {
	for (int i = 0 ; i < skills.size() ; i++)
		if (skills[i].getSkillName() == skillName)
			return i;
	return NOTFOUND;
}

void User::printProfile () {
	std::cout << "Name:" << SPACE << firstName << SPACE << lastName << std::endl;
	std::cout << "Email:" << SPACE << emailAddress << std::endl;
	std::cout << "Biography:" << SPACE << biography << std::endl;
	std::cout << "Network:" << SPACE << followers.size() << SPACE << "connections" << std::endl;
	std::cout << "Experiences:" << std::endl;
	sortExperiencesByDate();
	for (int i = 0 ; i < experiences.size() ; i++) {
		std::cout << TAB << (i+1) << DOT << SPACE;
		experiences[i].printExperience();
	}
	std::cout << "Skills:" << std::endl;
	for (int i = 0 ; i < skills.size() ; i++) {
		std::cout << TAB << (i+1) << DOT << SPACE;
		skills[i].printSkill();
	}
}

float User::sumNeededSkillRates (std::vector <std::string> neededSkills) {
	float sum = 0;
	for (int i = 0 ; i < neededSkills.size() ; i++) 
		for (int j = 0 ; j < skills.size() ; j++)
			if(skills[j].getSkillName() == neededSkills[i]) {
				sum += skills[j].getSkillRate();
				break;
			}
	return sum;
}

void User::sortExperiencesByDate () {
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (int i = 1 ; i < experiences.size() ; i++)
			if (experiences[i] < experiences[i-1]) {
				std::swap (experiences[i-1],experiences[i]);
				isSorted = false;
			}
	}
}