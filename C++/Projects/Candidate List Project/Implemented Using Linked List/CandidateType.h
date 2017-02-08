/*
	Nguyen, Thao
	CS A250
	Sep 16, 2014

	Project 1
*/

#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include "PersonType.h"

#include <iostream>
#include <string>

using namespace std;

const int NUM_OF_DIVISIONS = 4; 

class CandidateType : public PersonType
{
public:
	CandidateType();
	void updateVotesByDivision(int divisionNum, int numOfVotes);
	int getTotalVotes() const;
	int getVotesByDivision(int divisionNum) const;
	void printCandidateInfo() const;
	void printCandidateTotalVotes() const;
	void printCandidateDivisionVotes(int divisionNum) const;
	~CandidateType();
private:
	int totalNumOfVotes;
	int a[NUM_OF_DIVISIONS];
};

#endif