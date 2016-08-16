#pragma once
#include <string>
#include <iostream>
#include "Date.h"
using namespace std;

class Vehicle
{
	string _registrationNumber;
	float _weight;
	short int _numberOfSeats;
	string _chassisNumber;
	string _engineNumber;
	string _owner;
	Date _firstRegistration;
	Date _currentRegistration;
public:
	Vehicle();
	Vehicle(string registrationNumber, float weight, short int numberOfSeats, 
		string chassisNumber, string engineNumber, string owner, 
		Date firstRegistration, Date currentRegistration);

	string getRegistrationNumber() const { return _registrationNumber; }
	float getWeight() const {return _weight;}
	short int getNumberOfSeats() const { return _numberOfSeats; }
	string getChassisNumber() const { return _chassisNumber; }
	string getEngineNumber() const { return _engineNumber; }
	string getOwner() const { return _owner; }
	Date getFirstRegistration() const { return _firstRegistration; }
	Date getCurrentRegistration() const { return _currentRegistration; }

	void Print() const;
	~Vehicle();
};

