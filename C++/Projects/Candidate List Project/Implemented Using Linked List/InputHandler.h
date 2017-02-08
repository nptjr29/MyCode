#include "CandidateList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void createCandidateList(ifstream& infile, CandidateList& candidateList)
{
	int ssn;
	int allVotes[NUM_OF_DIVISIONS];
	string  fName, lName;

	infile >> ssn;

	while (ssn != -999)
	{
		CandidateType newCandidate;

		infile >> fName;
		infile >> lName;
		newCandidate.setPersonInfo(fName, lName, ssn);

		//for (int i = 0; i < NUM_OF_DIV; ++i)
		for (int i = 0; i < NUM_OF_DIVISIONS; ++i)
		{
			infile >> allVotes[i];
			newCandidate.updateVotesByDivision(i, allVotes[i]);
		}

		candidateList.addCandidate(newCandidate);


		infile >> ssn;
	}
}

void readCandidateData(CandidateList& candidateList)
{
	ifstream infile;

	infile.open("candidates_data.txt");

	if (!infile)
	{
		cerr << "Input file does not exist." << endl;
		exit(1);
	}

	createCandidateList(infile, candidateList);

	infile.close();
}
