#ifndef __COMPANY_H__
#define __COMPANY_H__

#define NOJOBREQ "no job req found"
#define NOAPPLICANT "no applicant found"
#define NOW "INDEFINITE_DATE"
#include <string>
#include <vector>
#include <iostream>
#include "job.hpp"
#include "JobReq.hpp"
#include "user.hpp"

class Company {
	private:
		std::string name;
		std::string address;
		std::string description;
		std::vector <Job> jobs;
		std::vector <JobRequest> jobReqs;
	public:
		Company (std::string companyName, std::string companyAddress, std::string companyDescription);
		void addJob (std::string fullName, std::string title, std::string startsAt, std::string endsAt = NOW);
		void addJobRequest (std::string title, std::map <std::string, float> conditions);
		void addApplicant (User applicant, std::string title);
		std::string getID () { return name; }
		bool isJobRepeated (std::string jobName);
		std::string hireBestApplicant (std::string jobTitle);
		void printCompanyProfile();
		std::vector <JobRequest> getSuggestedJobs (User user);
		bool isUserQualified (User user, std::string jobTitle);
		bool isJobReqRepeated(std::string jobReqTitle);
		void sortJobsByDate ();
};

#endif