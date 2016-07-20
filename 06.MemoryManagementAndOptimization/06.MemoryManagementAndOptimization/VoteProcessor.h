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
template<typename T>
using VotesMap = map<T, VoterPtrVector>;

class VoteProcessor
{
	VoterPtrVector votes;
	VotesMap<string> votesByName;
	VotesMap<unsigned int> votesByAge;
	VotesMap<Gender> votesByGender;
	VotesMap<string> votesByEthnos;
	VotesMap<string> votesByCity;

public:
	VoteProcessor();
	void getVotes(string, FilterItem, PrintType);
	VoterPtrVector& filterVotes(FilterItem item, string searched);
	void addVote(Voter*);
	void printResult(VoterPtrVector& db, PrintType printType);

	~VoteProcessor();
};
