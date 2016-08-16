#include "stdafx.h"
#include "Date.h"


Date::Date()
{
}

Date::Date(int year, int month, int day)
{
	_month = month;
	_day = day;
	_year = year;
}

Date::Date(const Date & date)
{
	Date(date.getYear(), date.getMonth(), date.getDay());
}

Date Date::operator=(Date newDate)
{
	return Date(newDate.getYear(), newDate.getMonth(), newDate.getDay());
}

string Date::toString() const
{
	return to_string(_day) + "." + to_string(_month) + "." + to_string(_year);
}
