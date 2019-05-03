#ifndef __DATE_H__
#define __DATE_H__

#define SLASH '/'
#include <string>
#include <iostream>
#include <cstdlib>
#define NOW "INDEFINITE_DATE"
#define LATER 1
#define EARLIER 2
#define EQUAL 3
class Date {
	private:
		int day;
		int month;
		int year;
	public:
		Date () {}
		Date (std::string dateString);
		void printDate() ;
		bool operator<(Date date);
		bool operator==(Date date);
};

#endif
