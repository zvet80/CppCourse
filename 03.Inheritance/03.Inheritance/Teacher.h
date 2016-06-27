#pragma once
#include "GuestTeacher.h"
#include <iostream>

class Teacher : public GuestTeacher
{
private:
	static unsigned short nextId;
	unsigned short int _daysInUni;

public:
	Teacher();
	Teacher(string, string, float, unsigned short);

	void setDaysInUni(unsigned short);
	unsigned short daysInUni() const;

	string toString() const;

	static Teacher getInput();

	~Teacher();
};

