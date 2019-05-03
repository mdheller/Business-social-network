#include "database.hpp"

Database::Database () {

}

void Database::addUser (std::string firstName, std::string lastName, std::string emailAddress, std::string biography) {
	if (findUser(emailAddress) == NOTFOUND) {
		User newUser(firstName,lastName,emailAddress,biography);
		userList.push_back(newUser);
	}
}

void Database::addCompany (std::string name, std::string address, std::string description) {
	if (findCompany(name) == NOTFOUND) {
		Company newCompany(name,address,description);
		companyList.push_back(newCompany);
	}
}

void Database::addExperience(std::string userId, std::string companyId, std::string title, std::string startAt , std::string endsAt) {
	if (findCompany(companyId) != NOTFOUND && companyList[findCompany(companyId)].isJobRepeated(title) == false && findUser(userId) != NOTFOUND) {
		userList[findUser(userId)].addExperience(companyId, title, startAt, endsAt);
		companyList[findCompany(companyId)].addJob(userList[findUser(userId)].getFullName(), title, startAt, endsAt);
	}
}

void Database::addExperienceByBestApp(std::string userId, std::string companyId, std::string title, std::string startAt , std::string endsAt) {
		userList[findUser(userId)].addExperience(companyId, title, startAt, endsAt);
		companyList[findCompany(companyId)].addJob(userList[findUser(userId)].getFullName(), title, startAt, endsAt);
}

void Database::addJobRequest(std::string companyName, std::string title, std::map<std::string, float> conditions) {
	if (findCompany(companyName) != NOTFOUND) {
		companyList[findCompany(companyName)].addJobRequest (title, conditions);
	}
}

void Database::assignSkill(std::string userId, std::string skillName) {
	if (findUser(userId) != NOTFOUND)
		userList[findUser(userId)].assignSkill(skillName);
}

void Database::endorseSkill(std::string endorserUserId, std::string skilledUserId, std::string skillName) {
	if (findUser(endorserUserId) != NOTFOUND && findUser(skilledUserId) != NOTFOUND) {
		userList[findUser(skilledUserId)].endorseSkill(userList[findUser(endorserUserId)].getID(),userList[findUser(endorserUserId)].calculateEndorseScore(skillName) , skillName);
	}
}

void Database::follow(std::string followerId, std::string followingId) {
	if (findUser(followingId) != NOTFOUND && findUser(followerId) != NOTFOUND && followingId != followerId) {
		userList[findUser(followingId)].addFollower(followerId);
		userList[findUser(followerId)].addFollower(followingId);
	}
}

void Database::applyForJob(std::string userId, std::string companyId, std::string jobTitle) {
	if (findUser(userId) != NOTFOUND && findCompany(companyId) != NOTFOUND) {
		companyList[findCompany(companyId)].addApplicant(userList[findUser(userId)], jobTitle);
	}
}

void Database::hireBestApplicant(std::string companyId, std::string jobTitle, std::string startsAt) {
	if (findCompany(companyId) != NOTFOUND) {
		std::string bestApplicantID = companyList[findCompany(companyId)].hireBestApplicant(jobTitle);
		if (bestApplicantID != NOJOBREQ && bestApplicantID != NOAPPLICANT) {
			addExperienceByBestApp(bestApplicantID, companyId, jobTitle, startsAt);
		}
	}
}

void Database::printUserProfile(std::string userId) {
	if (findUser(userId) != NOTFOUND) {
		userList[findUser(userId)].printProfile();
		std::cout << std::endl;
	}
}

void Database::printCompanyProfile(std::string companyName) {
	if (findCompany(companyName) != NOTFOUND) {
		companyList[findCompany(companyName)].printCompanyProfile();
		std::cout << std::endl;
	}
	
}

void Database::printSuggestedJobs(std::string userId) {
	int counter = 1;
	User user = userList[findUser(userId)];
	for (int i = 0 ; i < companyList.size() ; i++){
		std::vector<JobRequest> suggestedJobs = companyList[i].getSuggestedJobs(user);
		for (int j = 0 ; j < suggestedJobs.size() ; j++) {
			std::cout << counter << DOT << SPACE;
			suggestedJobs[j].printJobReq(companyList[i].getID());
			counter++;
		}
	}
}

void Database::printSuggestedUsers(std::string companyName, std::string jobTitle) {
	int counter = 1;
	for (int i = 0 ; i < userList.size() ; i++)
		if (companyList[findCompany(companyName)].isUserQualified (userList[i], jobTitle)) {
			std::cout << counter << DOT << std::endl;
			userList[i].printProfile();
			std::cout << std::endl;
			counter++;
		}
}

int Database::findCompany (std::string ID) {
	for (int i = 0 ; i < companyList.size() ; i++)
		if (companyList[i].getID() == ID)
			return i;
	return NOTFOUND;
}

int Database::findUser (std::string ID) {
	for (int i = 0 ; i < userList.size() ; i++)
		if (userList[i].getID() == ID)
			return i;
	return NOTFOUND;
}

