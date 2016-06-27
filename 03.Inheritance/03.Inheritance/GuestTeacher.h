#pragma once
#include "SchoolMember.h"
#include <iostream>

class GuestTeacher : public SchoolMember
{
private:
	static unsigned short gtNextId;
	float _salary;

public:
	GuestTeacher(string, string, float);

	void setSalary(float);
	float salary() const;

	virtual string toString() const;

	static GuestTeacher getInput();

	~GuestTeacher();
};

