#ifndef __JOBREQ_H__
#define __JOBREQ_H__

#include "user.hpp"
#include <string>
#include <map>
#include <iostream>
#include <vector>

#define NOAPPLICANT "no applicant found"
#define COMMA ','

class JobRequest {
private:
	std::string title;
	std::map <std::string, float> conditions;
	std::vector <User> applicants;
public:
	JobRequest (std::string newTitle, std::map <std::string, float> newConditions);
	void addApplicant (User applicant);
	std::string getTitle () { return title; }
	void hireBestApplicant ();
	void printJobReq (std::string companyID = "");
	bool isUserQualified(User applicant);
	std::string getBestApplicantID ();
	bool exists (std::string jobReqTitle);
};

#endif