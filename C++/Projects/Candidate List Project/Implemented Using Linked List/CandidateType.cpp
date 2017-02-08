#include "CandidateType.h"

CandidateType::CandidateType()
{
	totalNumOfVotes = 0;
	for (int i = 0; i < NUM_OF_DIVISIONS; ++i)
		a[i] = 0;
}

void CandidateType::updateVotesByDivision(int divisionNum, int numOfVotes)
{
	totalNumOfVotes += numOfVotes;
	a[divisionNum] += numOfVotes;
}

int CandidateType::getTotalVotes() const
{
	return totalNumOfVotes;
}

int CandidateType::getVotesByDivision(int divisionNum) const
{
	return a[divisionNum];
}

void CandidateType::printCandidateInfo() const
{
	printSSN();
	cout << " - ";
	printName();
	cout << endl;

}

void CandidateType::printCandidateTotalVotes() const
{
	printName();
	cout << "\n    Total Votes (all divisions): " 
		 << getTotalVotes();
}

void CandidateType::printCandidateDivisionVotes(int divisionNum) const
{
	printName();
	cout << "\n    Division " << divisionNum << " total votes: "
 		 << getVotesByDivision(divisionNum);
}

CandidateType::~CandidateType()
{}
