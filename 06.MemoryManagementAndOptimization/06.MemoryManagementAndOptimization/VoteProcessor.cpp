#include "stdafx.h"
#include "VoteProcessor.h"


VoteProcessor::VoteProcessor()
{
}

void VoteProcessor::addVote(Voter* voter)
{
	shared_ptr<Voter> voterPtr = shared_ptr<Voter>(voter);
	this->votes.push_back(voterPtr);
	this->votesByName[voter->name()].push_back(voterPtr);
	this->votesByAge[voter->age()].push_back(voterPtr);
	this->votesByGender[voter->gender()].push_back(voterPtr);
	this->votesByEthnos[voter->ethnos()].push_back(voterPtr);
	this->votesByCity[voter->city()].push_back(voterPtr);
}

VoterPtrVector& VoteProcessor::filterVotes(FilterItem item, string searched)
{
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
	case all:
		return this->votes;
	}
}

void VoteProcessor::printResult(VoterPtrVector& db, PrintType printType)
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

void VoteProcessor::getVotes(string searched, FilterItem item, PrintType printType)
{
	VoterPtrVector vec = this->filterVotes(item, searched);
	this->printResult(vec, printType);
}

VoteProcessor::~VoteProcessor()
{
}