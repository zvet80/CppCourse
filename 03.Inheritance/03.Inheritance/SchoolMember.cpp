#include "stdafx.h"
#include "SchoolMember.h"
#include <iostream>

SchoolMember::SchoolMember()
	:SchoolMember("", "")
{
}

SchoolMember::SchoolMember(string name, string currentCourse)
	: _id(0)
{	
	setName(name);
	setCurrentCourse(currentCourse);
}

unsigned short SchoolMember::id() const
{
	return _id;
}

void SchoolMember::setId(unsigned short i)
{
	_id = i;
}

void SchoolMember::setName(string name)
{
	if (name.length() == 0) return;
	_name = name;
}

string SchoolMember::name() const
{
	return _name;
}

void SchoolMember::setCurrentCourse(string currentCourse)
{
	if (currentCourse.length() == 0) return;
	_currentCourse = currentCourse;
}

string SchoolMember::currentCourse() const
{
	return 	_currentCourse;
}

string SchoolMember::toString() const
{
	string allData;	
	allData.append("\n");
	allData.append(typeid(*this).name());
	allData.append("\nID: " + to_string((*this).id()));
	allData.append("\nName: " + name());
	allData.append("\nCurrent course: " + currentCourse());
	return allData;
}

void SchoolMember::getInput()
{
}

SchoolMember::~SchoolMember()
{
}
