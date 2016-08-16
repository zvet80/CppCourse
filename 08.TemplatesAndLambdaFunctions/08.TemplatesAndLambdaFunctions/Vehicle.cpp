#include "stdafx.h"
#include "Vehicle.h"


Vehicle::Vehicle(): _weight(0), _numberOfSeats(0)
{
}

Vehicle::Vehicle(string registrationNumber, float weight, short int numberOfSeats, string chassisNumber, string engineNumber, string owner, Date firstRegistration, Date currentRegistration): _registrationNumber(registrationNumber), _weight(weight), _numberOfSeats(numberOfSeats), _chassisNumber(chassisNumber), _engineNumber(engineNumber), _owner(owner), _firstRegistration(firstRegistration), _currentRegistration(currentRegistration)
{
}

void Vehicle::Print() const
{
	cout << getRegistrationNumber() << endl;
	cout << "Weight: " << getWeight() << " t" << endl;
	cout << "Number of seats: " << getNumberOfSeats() << endl;
	cout << "Chassis number: " << getChassisNumber() << endl;
	cout << "Engine number: " << getEngineNumber() << endl;
	cout << "Owner: " << getOwner() << endl;
	cout << "Date of first registration: " << getFirstRegistration().toString() << endl;
	cout << "Date of registration in country: " << getCurrentRegistration().toString() << endl;
}


Vehicle::~Vehicle()
{
}
