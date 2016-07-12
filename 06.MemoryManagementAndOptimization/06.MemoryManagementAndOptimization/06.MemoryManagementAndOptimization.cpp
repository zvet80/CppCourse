// 06.MemoryManagementAndOptimization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Voter.h"
#include "VoteProcessor.h"

#include "PrintType.h"
#include "FilterItem.h"
#include "Gender.h"



int main()
{
	//unsigned int searchAge(25);
	Voter* v1 = new Voter("pesho", 25, Gender::Male, "english", "London", true);
	Voter* v2 = new Voter("Jane", 36, Gender::Female, "Irish", "London", false);
	//Voter* vptr = &v;
	VoteProcessor vp = VoteProcessor();
	vp.addVote(v1);
	vp.addVote(v2);
	vp.getVotes("1", FilterItem::gender, PrintType::numbersPrint);
	/*cout << v1->toString();
	cout << v2->toString();*/

    return 0;
}

