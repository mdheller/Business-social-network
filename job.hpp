#ifndef __JOB_H__
#define __JOB_H__

#include <string>
#include <iostream>
#include "date.hpp"

#define SPACE ' '

class Job {
private:
	std::string fullName;
	std::string title;
	Date start;
	Date end;
public:
	Job(std::string Name, std::string newTitle, std::string startsAt, std::string endsAt = NOW);
	std::string getTitle () { return title; }
	void printJob ();
	bool operator< (Job job);
	bool exists (std::string jobTitle);
	
};

#endif