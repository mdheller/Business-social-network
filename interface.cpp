#include "interface.hpp"


Interface::Interface() {

}

void Interface::addUser(std::string firstName, std::string lastName, std::string emailAddress, std::string biography) {
	database.addUser(firstName, lastName, emailAddress, biography);
}

void Interface::addCompany(std::string name, std::string address, std::string description) {
	database.addCompany(name,address,description);
}

void Interface::addExperience(std::string userId, std::string companyId, std::string title, std::string startAt , std::string endsAt) {
	database.addExperience (userId, companyId, title, startAt, endsAt);
}

void Interface::addJobRequest(std::string companyName, std::string title, std::map<std::string, float> conditions) {
	database.addJobRequest(companyName, title, conditions);
}

void Interface::assignSkill(std::string userId, std::string skillName) {
	database.assignSkill(userId, skillName);
}

void Interface::endorseSkill(std::string endorserUserId, std::string skilledUserId, std::string skillName) {
	database.endorseSkill(endorserUserId, skilledUserId, skillName);
}

void Interface::follow(std::string followerId, std::string followingId) {
	database.follow (followerId, followingId);
}

void Interface::applyForJob(std::string userId, std::string companyId, std::string jobTitle) {
	database.applyForJob(userId, companyId, jobTitle);
}

void Interface::hireBestApplicant(std::string companyId, std::string jobTitle, std::string startsAt) {
	database.hireBestApplicant(companyId, jobTitle, startsAt);
}

void Interface::printUserProfile(std::string userId) {
	database.printUserProfile(userId);
}

void Interface::printCompanyProfile(std::string companyName) {
	database.printCompanyProfile(companyName);
}

void Interface::printSuggestedJobs(std::string userId) {
	database.printSuggestedJobs(userId);
}

void Interface::printSuggestedUsers(std::string companyName, std::string jobTitle) {
	database.printSuggestedUsers(companyName, jobTitle);
}

void Interface::printNetwork(std::string userId, int level)
{

}
