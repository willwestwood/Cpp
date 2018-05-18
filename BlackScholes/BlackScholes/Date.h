#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <chrono>

struct Date
{
private: Date() {};

public:
	int dayOfMonth;
	int month;
	int year;

	Date(int dayOfMonth, int month, int year) : dayOfMonth(dayOfMonth), month(month), year(year) {}

	friend std::istream& operator >> (std::istream& s, Date& d)
	{
		s >> d.year >> d.month >> d.dayOfMonth;

		// return stream for chaining
		return s;
	}

	friend std::istream& operator >> (std::istream& s, Date ** d)
	{
		*d = new Date();
		s >> (*d)->year >> (*d)->month >> (*d)->dayOfMonth;

		// return stream for chaining
		return s;
	}

	friend std::ostream& operator << (std::ostream& s, Date& d)
	{
		s << d.dayOfMonth << "/" << d.month << "/" << d.year;

		return s;
	}

	int dayCount()
	{
		int count = 0;

		// calculate number of leap years.
		int leapyears = year / 4;
		if (year % 4 == 0 && month < 3)
		{
			// If this is a leap year
			// And we have not passed Feburary then it does
			// not count.....
			leapyears--;
		}
		// convert year/month/day into a day count
		count = year * 365;
		for(int i(0); i < month -1; ++i)
			count += month_days[i];
		count += dayOfMonth + leapyears;

		return count;
	}

	friend int operator-(Date& lhs, Date& rhs)
	{
		// subtraction gives you the difference between two Days objects.
		return lhs.dayCount() - rhs.dayCount();
	}

	static Date now()
	{
		struct tm time_info;
		time_t time_create = time(NULL);
		localtime_s(&time_info, &time_create);

		Date now(time_info.tm_mday, time_info.tm_mon + 1, time_info.tm_year + 1900);
		return now;
	}

	const int month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
};

//const int Date::month_days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };