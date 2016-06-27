#include "stdafx.h"
#include "GuestTeacher.h"

unsigned short  GuestTeacher::gtNextId = 0;

GuestTeacher::GuestTeacher(string name, string currentCourse, float salary)
	:SchoolMember(name, currentCourse)
{
	++gtNextId;
	setId(gtNextId);
	setSalary(salary);
}

void GuestTeacher::setSalary(float salary)
{
	if (salary < 0) return;
	_salary = salary;
}

float GuestTeacher::salary() const
{
	return _salary;
}

string GuestTeacher::toString() const
{
	string allData;
	allData.append(SchoolMember::toString());
	allData.append("\nSalary: " + to_string(salary()));
	return allData;
}

GuestTeacher GuestTeacher::getInput()
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
	GuestTeacher gt = GuestTeacher(name, course, salary);
	cout << gt.toString();
	return gt;
}

GuestTeacher::~GuestTeacher()
{
}
