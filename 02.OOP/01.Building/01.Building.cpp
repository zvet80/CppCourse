// 01.Building.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class Building
{
private:
	string _owner;
	int _floors;
	int _offices;
	int _employees;
	int _workingSeats;
public:
	Building(string owner, int floors, int offices, int employees, int workingSeats)
	{
		setOwner(owner);
		setFloors(floors);
		setOffices(offices);
		setEmployees(employees);
		setWorkingSeats(workingSeats);
	}
	Building()
		: Building("", 0, 0, 0, 0)
	{
	}

	~Building()
	{
		//cout << "~Building()" << endl;
	}

	inline string owner() const { return _owner; };
	inline void setOwner(string owner)
	{
		if (owner.length() == 0) return;
		_owner = owner;
	};

	inline int floors() const { return _floors; };
	inline void setFloors(int floors)
	{
		if (floors <= 0)
			return;
		_floors = floors;
	};

	inline int offices() const { return _offices; };
	inline void setOffices(int offices)
	{
		if (offices < 0) return;
		_offices = offices;
	};

	inline int employees() const { return _employees; };
	inline void setEmployees(int employees)
	{
		if (employees < 0) return;
		_employees = employees;
	};

	inline int workingSeats() const { return _workingSeats; };
	inline void setWorkingSeats(int workingSeats)
	{
		if (workingSeats < 0)
			return;
		_workingSeats = workingSeats;
	};

	double CalcOccupancy() const;
	double CalcPeoplePerFloor() const;
	double CalcOfficesPerFloor() const;
	double CalcPeoplePerOffice() const;
};

double Building::CalcOccupancy() const
{
	return employees() * 100 / (double)(employees() + workingSeats());
}

double Building::CalcPeoplePerFloor() const
{
	return employees() / (double)floors();
}

double Building::CalcOfficesPerFloor() const
{
	return offices() / (double)floors();
}

double Building::CalcPeoplePerOffice() const
{
	return employees() / (double)offices();
}

typedef vector<Building> BuildingVector;

void Sort(BuildingVector& bv, function<bool(const Building& a, const Building& b)> predicate)
{
	sort(bv.begin(), bv.end(), predicate);
}

enum RATIOS
{
	Employees, WorkSeats, Occupancy, PeoplePerFloor, OfficesPerFloor, PeoplePerOffice
};

struct Predicate {
	int property;
	Predicate(int p) : property(p) {}
	bool operator()(const Building& a, const Building& b) const {
		switch (property)
		{
			case 0: return a.employees() < b.employees(); break;
			case 1: return a.workingSeats() < b.workingSeats(); break;
			case 2: return a.CalcOccupancy() < b.CalcOccupancy(); break;
			case 3: return a.CalcPeoplePerFloor() < b.CalcPeoplePerFloor(); break;
			case 4: return a.CalcOfficesPerFloor() < b.CalcOfficesPerFloor(); break;
			case 5: return a.CalcPeoplePerOffice() < b.CalcPeoplePerOffice(); break;
		}
	}
};

int main()
{
	Building building1 = Building("XYZ industries", 6, 127, 600, 196);
	Building building2 = Building("Rapid Development Crew", 8, 210, 822, 85);
	Building building3 = Building("SoftUni", 11, 106, 200, 60);
	vector<Building> businessPark{ building1, building2, building3 };

	Sort(businessPark, Predicate(Employees));
	printf("Most employees: %s with %d employees \n", businessPark.back().owner().c_str(), businessPark.back().employees());

	Sort(businessPark, Predicate(WorkSeats));
	printf("Most free places: %s with %d free places \n", businessPark.back().owner().c_str(), businessPark.back().workingSeats());

	Sort(businessPark, Predicate(Occupancy));
	printf("Highest occupancy: %s with %0.2f %% occupancy ratio \n", businessPark.back().owner().c_str(), businessPark.back().CalcOccupancy());

	Sort(businessPark, Predicate(PeoplePerFloor));
	printf("Most people per floor: %s with %0.2f people per floor \n", businessPark.back().owner().c_str(), businessPark.back().CalcPeoplePerFloor());
	printf("Least people per floor: %s with %0.2f people per floor \n", businessPark.front().owner().c_str(), businessPark.front().CalcPeoplePerFloor());

	Sort(businessPark, Predicate(OfficesPerFloor));
	printf("Most offices per floor: %s with %0.2f offices per floor \n", businessPark.back().owner().c_str(), businessPark.back().CalcOfficesPerFloor());
	printf("Least offices per floor: %s with %0.2f offices per floor \n", businessPark.front().owner().c_str(), businessPark.front().CalcOfficesPerFloor());

	Sort(businessPark, Predicate(PeoplePerOffice));
	printf("Most people per office: %s with %0.2f people per office \n", businessPark.back().owner().c_str(), businessPark.back().CalcPeoplePerOffice());
	printf("Least people per office: %s with %0.2f people per office \n", businessPark.front().owner().c_str(), businessPark.front().CalcPeoplePerOffice());
	return 0;
}