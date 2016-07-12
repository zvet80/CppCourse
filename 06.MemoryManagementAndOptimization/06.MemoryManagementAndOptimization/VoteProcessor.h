#pragma once
#include "Voter.h"
#include "PrintType.h"
#include "FilterItem.h"
#include "Gender.h"

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

using namespace std;

typedef shared_ptr<Voter> VoterPtr;
typedef vector<VoterPtr> VoterPtrVector;
//typedef map<string, VoterPtrVector> String2VotersMap;
template<typename T>
using MyMap = map<T, VoterPtrVector>;

class VoteProcessor
{
	VoterPtrVector votes;
	MyMap<string> votesByName;
	MyMap<unsigned int> votesByAge;
	MyMap<Gender> votesByGender;
	MyMap<string> votesByEthnos;
	MyMap<string> votesByCity;

public:
	VoteProcessor();
	//template<typename T>
	void getVotes(string, FilterItem, PrintType);

	//template <typename T>
	VoterPtrVector& filterVotes(FilterItem item, string searched);
	void addVote(Voter*);
	void printResult(VoterPtrVector& db, PrintType printType);

	~VoteProcessor();
};

//template<typename T>
inline VoterPtrVector& VoteProcessor::filterVotes(FilterItem item, string searched)
{
	
	/*T *voidPtr = &searched;
	unsigned int value = static_cast<unsigned int>(voidPtr);*/
	Gender g = (Gender)(atoi(searched.c_str()));
	switch (item)
	{
	case age:
		return this->votesByAge[atoi(searched.c_str())];
	case name:
		return this->votesByName[searched];
	case ethnos:
		return this->votesByEthnos[searched];
	case city:
		return this->votesByCity[searched];
	case gender:
		return this->votesByGender[(Gender)atoi(searched.c_str())];
	}

	//return map[searched];
}

inline void VoteProcessor::printResult(VoterPtrVector& db, PrintType printType)
{
	int all = db.size();
	int stay = count_if(db.begin(), db.end(), [](VoterPtr v) { return v->vote() == 1; });
	float stayPercent = (stay / (float)all * 100);
	float leavePercent = ((all - stay) / (float)all * 100);

	switch (printType)
	{
	case percentPrint:
		printf("Stay: %.2f%%; Leave: %.2f%%\n", stayPercent, leavePercent);
		break;
	case numbersPrint:
		printf("Stay: %d; Leave: %d\n", stay, all - stay);
		break;
	}
}
//template<typename T>
inline void VoteProcessor::getVotes(string searched, FilterItem item, PrintType printType)
{
	//Map<T> map = factory<T>(item);
	VoterPtrVector vec = this->filterVotes(item, searched);
	this->printResult(vec, printType);
}
//template<typename T>
//Map<T>& VoteProcessor::factory(FilterItem item)
//{
//	//map<const T, VoterPtrVector> map;
//	switch (item)
//	{
//	case age:
//		return votesByAge;
//	case name:
//		return votesByName;
//	case ethnos:
//		return votesByEthnos;
//	case city:
//		return votesByCity;	
//	case gender:
//		return votesByGender;
//	}
//}

