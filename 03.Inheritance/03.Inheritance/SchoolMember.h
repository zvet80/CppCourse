#pragma once
#include <string>
using namespace std;

class SchoolMember
{
private:
	unsigned short _id;
	string _name;
	string _currentCourse;

public:
	SchoolMember();

	SchoolMember(string, string);

	void setId(unsigned short i);
	unsigned short id() const;

	void setName(string);
	string name() const;

	void setCurrentCourse(string);
	string currentCourse() const;

	virtual string toString() const;

	virtual void getInput();

	~SchoolMember();
};

