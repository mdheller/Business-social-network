#ifndef __USER_H__
#define __USER_H__

#include <iostream>
#include <string>
#include <vector>
#include "skill.hpp"
#include "experience.hpp"

#define SPACE " "
#define TAB '\t'
#define NOTFOUND -1
#define DOT '.'

class User {
	private:
		std::string firstName;
		std::string lastName;
		std::string emailAddress;
		std::string biography;
		std::vector <Experience> experiences;
		std::vector <Skill> skills;
		std::vector <std::string> followers;
	public:
		User(std::string userFirstName, std::string userLastName, std::string userEmailAddress, std::string userBiography);
		void addExperience (std::string companyId, std::string title, std::string startsAt , std::string endsAt = NOW);
		void assignSkill (std::string name);
		void addFollower (std::string ID);
		std::string getID () { return emailAddress; }
		bool isSkilledEnough (std::string skillName, float minimumSkillRate);
		void endorseSkill (std::string endorserID, float endorserScore, std::string skillName);
		int findSkill (std::string skillName);
		float calculateEndorseScore (std::string skillName);
		void printProfile ();
		std::string getFullName () { return (firstName + " " + lastName);}
		float sumNeededSkillRates (std::vector <std::string> neededSkills);
		void sortExperiencesByDate ();
};

#endif