#include "stdafx.h"
#include "Student.h"
#include <sstream>

unsigned short Student::nextId = 0;

Student::Student()
	:SchoolMember()
{
}

Student::Student(string name, string currentCourse, double point)
	: SchoolMember(name, currentCourse)
{
	++nextId;
	setId(nextId);
	setAvgPoint(point);
}

void Student::addMark(int mark)
{
	_currentPoints.push_back(mark);
}

double Student::getAverageMark()
{
	int sum = 0;
	int averageMark = 0;

	for (int i = 0; i < sizeof(&_currentPoints); i++)
	{
		sum += _currentPoints[i];
	}

	if (sizeof(&_currentPoints) > 0)
	{
		averageMark = sum / (double)sizeof(&_currentPoints);
	}

	return averageMark;
}

void Student::setAvgPoint(double point)
{
	if (point < 0) return;
	_avgPoint = point;
}

double Student::avgPoint() const
{
	return _avgPoint;
}

string Student::toString() const
{
	string allData;
	allData.append(SchoolMember::toString());
	allData.append("\nAverage mark: " + to_string(avgPoint()) + "\n");
	return allData;
}

Student Student::getInput()
{
	string name;
	string course;
	double avgMark;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter course: ";
	cin >> course;
	cout << "Enter average mark: ";
	cin >> avgMark;
	Student s = Student(name, course, avgMark);
	cout << s.toString();
	return s;
}

Student::~Student()
{
}
