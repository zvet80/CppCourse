#include "stdafx.h"
#include "Teacher.h"

unsigned short Teacher::nextId = 0;

Teacher::Teacher()
	:Teacher("", "", 0.00, 0)
{
}

Teacher::Teacher(string name, string currentCourse, float salary, unsigned short days)
	: GuestTeacher(name, currentCourse, salary)
{
	++nextId;
	setId(nextId);
	setDaysInUni(days);
}

void Teacher::setDaysInUni(unsigned short days)
{
	if (days < 0) return;
	_daysInUni = days;
}

unsigned short Teacher::daysInUni() const
{
	return _daysInUni;
}

string Teacher::toString() const
{
	string allData;
	allData.append(GuestTeacher::toString());
	allData.append("\nDays in Uni: " + to_string(daysInUni()));
	return allData;
}

Teacher Teacher::getInput()
{
	string name;
	string course;
	float salary;
	int days;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter course: ";
	cin >> course;
	cout << "Enter salary: ";
	cin >> salary;
	cout << "Enter days in uni: ";
	cin >> days;
	Teacher t = Teacher(name, course, salary, days);
	cout << t.toString();
	return t;
}

Teacher::~Teacher()
{
}
