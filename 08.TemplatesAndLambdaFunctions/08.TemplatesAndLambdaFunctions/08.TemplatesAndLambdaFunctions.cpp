// 08.TemplatesAndLambdaFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <thread>

#include "Date.h"
#include "Vehicle.h"

using namespace std;
void searchForACarWithRegistrationNumber(string)
{

}
int main()
{
	thread threadCars = thread(searchForACarWithRegistrationNumber, "");
	thread threadTrucks = thread(searchForACarWithRegistrationNumber, "");
	thread threadMotorcycles = thread(searchForACarWithRegistrationNumber, "");
	threadCars.join();
	threadTrucks.join();
	threadMotorcycles.join();

    return 0;
}

