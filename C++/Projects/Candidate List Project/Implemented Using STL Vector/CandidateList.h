/*
	Nguyen, Thao
	CS A250
	October 26, 2014

	Project 2
*/

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class CandidateList
{
public:
	//Default constructor
	CandidateList();

	void addCandidate(const CandidateType& newCandidate) const;
	int getWinner() const;
	void printCandidateName(int searchSSN) const;
	void printAllCandidates() const;
	void printCandidateDivisionVotes(int searchSSN, int searchDivisionNum) const;
	void printCandidateTotalVotes(int searchSSN) const;
	bool searchCandidate(int searchSSN) const;
	void printHighestToLowestVotes() const;
	CandidateList(const CandidateList& otherCandidateList);         //copy constructor
	CandidateList& CandidateList::operator=(const CandidateList& rightSide);  //overloaded assignment operator

	//Destructor
	~CandidateList();

private:
	vector<CandidateType>* candidates;
	bool searchCandidateLocation(int searchSSN, vector<CandidateType>::const_iterator& location) const;
};

#endif
