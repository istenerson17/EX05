#include <iostream>
#include "Date.h"
#include <ctime>
using namespace std;

Date::Date()
{
	time_t t = time(0);
	struct tm * now = localtime(&t);
	year = (now->tm_year + 1900);
	month = (now->tm_mon + 1);
	day = now->tm_mday;
}

Date::Date(int elapsedtimeSec)
{
	time_t t = elapsedtimeSec;
	struct tm * now = localtime(&t);
	year = (now->tm_year + 1900);
	month = (now->tm_mon + 1);
	day = now->tm_mday;
}

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

int Date::setDate(int elapsetime)
{
	year = 1970 + ((1 / 31536000)*elapsetime);
	month = 1 + ((1 / 2628000)*elapsetime);
	do
	{
		month = month - 12;
	} while (month > 12);
	day = 1 + ((1 / 86400)*elapsetime);
	do
	{
		day = day - 30; 
	} while (day > 30);
	return year;
}
