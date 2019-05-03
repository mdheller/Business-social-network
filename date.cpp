#include "date.hpp"



Date::Date (std::string dateString) {
	if (dateString == NOW) {
		day = 99;
		month = 99;
		year = 9999;
	}
	else {
		day = atoi(dateString.substr(0,dateString.find(SLASH)).c_str());
		dateString = dateString.substr(dateString.find(SLASH) + 1);
		month = atoi(dateString.substr(0,dateString.find(SLASH)).c_str());
		dateString = dateString.substr(dateString.find(SLASH) + 1);
		year = atoi(dateString.substr(0,dateString.find(SLASH)).c_str());
	}
}

void Date::printDate() {
	if (*this == Date(NOW)) {
		std::cout << "NOW";
		return;
	}
	std::cout << day << SLASH << month << SLASH << year;
}

bool Date::operator<(Date date) {
	if (year < date.year)
		return true;
	else if (year > date.year)
		return false;
	if (month < date.month)
		return true;
	else if (month > date.month)
		return false;
	if (day < date.day)
		return true;
	else if (day > date.day)
		return false;
}

bool Date::operator==(Date date) {
	if (year == date.year && month == date.month && day == date.day)
		return true;
	return false;
}