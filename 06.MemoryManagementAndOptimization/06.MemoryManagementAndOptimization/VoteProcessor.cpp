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

VoteProcessor::~VoteProcessor()
{
}