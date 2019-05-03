#include "job.hpp"

Job::Job (std::string Name, std::string newTitle, std::string startsAt, std::string endsAt) {
	fullName = Name;
	title = newTitle;
	start = Date(startsAt);
	end = Date(endsAt);
}

void Job::printJob () {
	start.printDate();
	std::cout << SPACE << '-' << SPACE;
	end.printDate();
	std::cout << SPACE << title << SPACE << "by" << SPACE << fullName << std::endl;
}

bool Job::operator< (Job job) {
	if (this->start < job.start)
		return true;
	else if (this->start == job.start)
		if (this->end < job.end)
			return true;
		else
			return false;
	else 
		return false;
}

bool Job::exists (std::string jobTitle) {
	if (title == jobTitle)
		return true;
	return false;
}

