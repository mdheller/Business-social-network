#include "company.hpp"


Company::Company (std::string companyName, std::string companyAddress, std::string companyDescription) {
	name = companyName;
	address = companyAddress;
	description = companyDescription;
}

void Company::addJob(std::string fullName, std::string title, std::string startsAt, std::string endsAt) {
	Job newJob (fullName,title,startsAt,endsAt);
	jobs.push_back(newJob);
}

void Company::addJobRequest(std::string title, std::map <std::string, float> conditions) {
	if (!isJobReqRepeated(title)) {
		JobRequest newJobReq (title, conditions);
		jobReqs.push_back(newJobReq);
	}
}

bool Company::isJobReqRepeated(std::string jobReqTitle) {
	for (int i = 0 ; i < jobReqs.size() ; i++)
		if (jobReqs[i].exists(jobReqTitle))
			return true;
		return false;
}

void Company::addApplicant (User applicant, std::string title) {
	for (int i = 0 ; i < jobReqs.size() ; i++)
		if (jobReqs[i].exists(title))
			jobReqs[i].addApplicant(applicant);
}

bool Company::isJobRepeated (std::string jobName) {
	for (int i = 0 ; i < jobs.size() ; i++)
		if (jobs[i].exists(jobName))
			return true;
	return false;
}

std::string Company::hireBestApplicant (std::string jobTitle) {
	for (int i = 0 ; i < jobReqs.size() ; i++)
		if (jobReqs[i].exists(jobTitle)) {
			std::string bestApplicantID = jobReqs[i].getBestApplicantID();
			if (bestApplicantID != NOAPPLICANT)
				jobReqs.erase(jobReqs.begin() + i);
			return bestApplicantID;
		}
	return NOJOBREQ;
}

void Company::printCompanyProfile() {
	std::cout << "Name:" << SPACE << name << std::endl;
	std::cout << "Address:" << SPACE << address << std::endl;
	std::cout << "Description:" << SPACE << description << std::endl;
	std::cout << "Jobs:" << std::endl;
	sortJobsByDate();
	for (int i = 0 ; i < jobs.size() ; i++) {
		std::cout << TAB << (i+1) << DOT << SPACE;
		jobs[i].printJob();
	}
	std::cout << "Requests:" << std::endl;
	for (int i = 0 ; i < jobReqs.size() ; i++) {
		std::cout << TAB << (i+1) << DOT << SPACE;
		jobReqs[i].printJobReq();
	}
}

std::vector <JobRequest> Company::getSuggestedJobs (User user) { 
	std::vector <JobRequest> suggestedJobs;
	for (int i = 0 ; i < jobReqs.size() ; i++) {
		if (jobReqs[i].isUserQualified(user))
			suggestedJobs.push_back(jobReqs[i]);
	}
	return suggestedJobs;
}

bool Company::isUserQualified (User user, std::string jobTitle) { 
	for (int i = 0 ; i < jobReqs.size() ; i++)
		if (jobReqs[i].exists(jobTitle))
			return jobReqs[i].isUserQualified (user);
}

void Company::sortJobsByDate () {
	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		for (int i = 1 ; i < jobs.size() ; i++)
			if (jobs[i] < jobs[i-1]) {
				std::swap (jobs[i-1],jobs[i]);
				isSorted = false;
			}
	}
}