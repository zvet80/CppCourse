#pragma once
#include <string>
#include <iostream>
#include "Gender.h"

using namespace std;

class Voter
{
	string _name;
	unsigned int _age;
	Gender _gender;
	string _city;
	string _ethnos;
	bool _vote;

public:
	Voter(string name, unsigned int age, Gender gender, string city, string ethnos, bool vote);
	string name() const;
	unsigned int age() const;
	Gender gender() const;
	string city() const;
	string ethnos() const;
	bool vote() const;

	static Voter getInput();
	string toString() const;
	~Voter();
};

