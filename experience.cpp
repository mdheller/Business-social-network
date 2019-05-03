#include "experience.hpp"

Experience::Experience (std::string newCompanyId, std::string newTitle, std::string startAt , std::string endsAt) {
	companyId = newCompanyId;
	title = newTitle;
	start = Date(startAt);
	end = Date(endsAt);
}

void Experience::printExperience ()  {
	start.printDate();
	std::cout << SPACE << '-' << SPACE;
	end.printDate();
	std::cout << SPACE << title << SPACE << "at" << SPACE << companyId << std::endl;
}

bool Experience::operator< (Experience exp) {
	if (this->start < exp.start)
		return true;
	else if (this->start == exp.start)
		if (this->end < exp.end)
			return true;
		else
			return false;
	else 
		return false;
}