// 06.MemoryManagementAndOptimization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Voter.h"
#include "VoteProcessor.h"

#include "PrintType.h"
#include "FilterItem.h"
#include "Gender.h"


void collectorMenu(VoteProcessor* vp)
{
	cout << "\n1.Results in percent\n2.Results in numbers\n3.Results based on Age\n4.Results based on name\n5.Results based on Ethnos\n6.Results based on Living city/village\n" << endl;
	int choice;
	cin >> choice;

	while (choice != 0)
	{
		string input;
		switch (choice)
		{
		case 1:vp->printResult(vp->filterVotes(FilterItem::all, ""), PrintType::percentPrint); break;
		case 2:vp->printResult(vp->filterVotes(FilterItem::all, ""), PrintType::numbersPrint); break;
		case 3:cout << "Enter age:";
			cin >> input;
			vp->getVotes(input, FilterItem::age, PrintType::numbersPrint);
			break;
		case 4: cout << "Enter name:";
			cin >> input;
			vp->getVotes(input, FilterItem::name, PrintType::numbersPrint);
			break;
		case 5: cout << "Enter ethnos:";
			cin >> input;
			vp->getVotes(input, FilterItem::ethnos, PrintType::numbersPrint);
			break;
		case 6: cout << "Enter city:";
			cin >> input;
			vp->getVotes(input, FilterItem::city, PrintType::numbersPrint);
			break;
		default: cout << "Sorry, no such operation"; break;
		}

		cout << "\nChoose another operation or enter 0" << endl;
		cin >> choice;
	}
}

int main()
{
	Voter* v1 = new Voter("Pesho", 25, Gender::Male, "English", "London", true);
	Voter* v2 = new Voter("Jane", 36, Gender::Female, "Irish", "London", false);
	Voter* v3 = new Voter("John", 25, Gender::Male, "Irish", "Manchester", false);
	VoteProcessor vp = VoteProcessor();
	vp.addVote(v1);
	vp.addVote(v2);
	vp.addVote(v3);
	Voter* newVoter = new Voter();

	cout << "1.Vote or\nEnter password" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 12344321: collectorMenu(&vp); break;
	case 1: newVoter = &Voter::getInput();
		vp.addVote(newVoter);
		cout << "Your vote is recorded!" << endl; break;
	default:cout << "Wrong choice" << endl; break;
	}

	return 0;
}


