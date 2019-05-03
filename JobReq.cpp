#include "JobReq.hpp"

JobRequest::JobRequest (std::string newTitle, std::map <std::string, float> newConditions) {
	title = newTitle;
	conditions = newConditions;
}

void JobRequest::addApplicant (User applicant) {
	if (isUserQualified(applicant))
		applicants.push_back(applicant);
}

bool JobRequest::isUserQualified (User applicant) {
	std::map <std::string , float> :: iterator currentCondition;
	for (currentCondition = conditions.begin() ; currentCondition != conditions.end() ; currentCondition++) {
		if (!(applicant.isSkilledEnough(currentCondition->first, currentCondition->second)))
			return false;
	}
	return true;
}

void JobRequest::printJobReq(std::string companyID) {
	std::cout << title << SPACE;
	if (companyID != "")
		std::cout << "in" << SPACE << companyID;
	std::cout << SPACE << '-' << SPACE << "needed skills:" << SPACE;
	std::map <std::string, float> :: iterator currentSkill;
	for (currentSkill = conditions.begin() ; currentSkill != conditions.end() ; currentSkill++) {
		std::cout << currentSkill->first << '(' << SPACE << currentSkill->second << SPACE << ')';
		std::cout << SPACE << COMMA << SPACE;
	}
	std::cout << std::endl;
}

std::string JobRequest::getBestApplicantID () {
	std::string bestApplicantID;
	if (applicants.size() == 0)
		return NOAPPLICANT;
	std::vector <std::string> neededSkills;
	std::map <std::string, float> :: iterator currentSkill;
	for (currentSkill = conditions.begin() ; currentSkill != conditions.end() ; currentSkill++) {
		neededSkills.push_back(currentSkill->first);
	}
	float maxSkillRate;
	
	for (int i = 0 ; i < applicants.size() ; i++) {
		if (applicants[i].sumNeededSkillRates(neededSkills) > maxSkillRate) {
			maxSkillRate = applicants[i].sumNeededSkillRates(neededSkills);
			bestApplicantID = applicants[i].getID();
		}
	}
	return bestApplicantID;
}

bool JobRequest::exists (std::string jobReqTitle) {
	if (title == jobReqTitle)
		return true;
	return false;
}