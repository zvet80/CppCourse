// 03.Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Teacher.h"
#include "Student.h"

using namespace std;

template<typename T>
string findById(const vector<T>& vec, int id)
{
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].id() == id)
		{
			return vec[i].toString();
		}
	}
	return "Member with id: " + to_string(id) + " not found\n";
}

int main()
{
	Teacher t1 = Teacher("Pesho", "Java", 1500.50, 40);
	Teacher t2 = Teacher("Gosho", "C++", 2000, 40);
	Student s1 = Student("Pesho", "Java", 4.5);
	Teacher t3 = Teacher("Petrov", "C", 800, 200);
	GuestTeacher gt1 = GuestTeacher("Ivanov", "History", 800);
	Teacher t4 = Teacher("Dimitrov", "Math", 800, 200);
	GuestTeacher gt2 = GuestTeacher("John", "C", 800);
	vector<Teacher> teachers{ t1,t2,t3,t4 };
	vector<GuestTeacher> guestTeachers{ gt1,gt2 };
	vector<Student> students{ s1 };

	cout << "\nChoose number of operation to make: " << endl;
	cout << "1.Get data for student with ID \n2.Get data for teacher with ID\n3.Get data for guest teacher with ID\n4.Add data for new student\n5.Add data for new teacher\n6.Add data for new guest teacher" << endl;

	int choice;
	cin >> choice;	

	while (choice != 0)
	{
		int searchedId;
		if (choice >= 1 && choice <= 3)
		{
			cout << "Enter id to search" << endl;
			cin >> searchedId;
		}

		switch (choice)
		{
			case 1: cout << findById(students, searchedId); break;
			case 2: cout << findById(teachers, searchedId); break;
			case 3: cout << findById(guestTeachers, searchedId); break;
			case 4: students.push_back(Student::getInput()); break;
			case 5: teachers.push_back(Teacher::getInput()); break;
			case 6: guestTeachers.push_back(GuestTeacher::getInput()); break;
			default: cout << "Sorry, no such operation"; break;
		}

		cout << "\nChoose another operation or enter 0" << endl;
		cin >> choice;
	}
	

	return 0;
}

