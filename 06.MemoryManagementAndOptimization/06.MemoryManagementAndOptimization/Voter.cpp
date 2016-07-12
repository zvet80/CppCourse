#include "stdafx.h"
#include "Voter.h"


Voter::Voter(string name, unsigned int age, Gender gender, string ethnos, string city, bool vote) :_name(name), _age(age), _gender(gender), _ethnos(ethnos), _city(city), _vote(vote)
{
}

string Voter::name() const
{
	return _name;
}

unsigned int Voter::age() const
{
	return _age;
}

Gender Voter::gender() const
{
	return _gender;
}

string Voter::city() const
{
	return _city;
}

string Voter::ethnos() const
{
	return _ethnos;
}

bool Voter::vote() const
{
	return _vote;
}

Voter Voter::getInput()
{
	string name;
	string ethnos;
	string city;
	unsigned int age;
	char gender;
	bool vote;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Enter your gender(M, F, U): ";
	cin >> gender;
	cout << "Enter your ethnos: ";
	cin >> ethnos;
	cout << "Enter your city: ";
	cin >> city;
	cout << "Enter your vote (0 - Stay, 1 - Leave): ";
	cin >> vote;

	Voter v = Voter(name, age, (Gender)gender, ethnos, city, vote);
	cout << v.toString();
	return v;
}

string Voter::toString() const
{
	string allData;
	allData.append("\nName: " + _name);
	allData.append("\nAge: " + to_string(_age));
	allData.append("\nGender: " + to_string(_gender));
	allData.append("\nEthnos: " + _ethnos);
	allData.append("\nCity: " + _city);
	allData.append("\nVote: " + to_string(_vote));// == 0 ? "Stay" : "Leave"));
	return allData;
}

Voter::~Voter()
{
}
