#pragma once
#include <string>
using namespace std;

class Date
{
private:
	int _year;
	int _month;
	int _day;

public:
	Date();
	Date(int year, int month, int day);
	Date(const Date &date);
	int getYear() const { return _year; }
	int getMonth() const { return _month; }
	int getDay() const { return _day; }

	Date operator =(Date);

	string toString() const;
};

