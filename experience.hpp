#ifndef __EXPERIENCE_H__
#define __EXPERIENCE_H__

#include <string>
#include <iostream>
#include "date.hpp"
#define SPACE " "
#define NOW "INDEFINITE_DATE"


class Experience {
	private:
		std::string companyId;
		std::string title;
		Date start;
		Date end;
	public:
		Experience( std::string newCompanyId, std::string newTitle, std::string startAt , std::string endsAt = NOW);
		void printExperience () ;
		bool operator< (Experience exp);
};

#endif