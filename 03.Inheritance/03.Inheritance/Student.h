#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "SchoolMember.h"

using namespace std;

class Student : public SchoolMember
{
private:
	static unsigned short nextId;
	vector<int> _currentPoints;
	double _avgPoint;

public:
	Student();

	Student(string, string, double);

	void addMark(int);
	double getAverageMark();

	void setAvgPoint(double);
	double avgPoint() const;

	string toString() const;

	static Student getInput();

	~Student();
};

