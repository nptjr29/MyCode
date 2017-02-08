#include "CandidateList.h"

CandidateList::CandidateList()
{
	candidates = new vector<CandidateType>;
}

void CandidateList::addCandidate(const CandidateType& newCandidate) const
{
	candidates->push_back(newCandidate);
}

int CandidateList::getWinner() const
{
	if (candidates->size() == 0)
	{
		cerr << "List is empty." << endl;
		return 0;
	}
	else
	{
		vector<CandidateType>::const_iterator current = candidates->begin();

		vector<CandidateType>::const_iterator winner = candidates->begin();

		int winnerVotes = current->getTotalVotes();

		while (current != candidates->end())
		{
			if (current->getTotalVotes() > winnerVotes)
			{
				winnerVotes = current->getTotalVotes();
				winner = current;
			}
			current++;
		}

		return winner->getSSN();
	}
}

void CandidateList::printCandidateName(int searchSSN) const
{
	if (candidates->empty())
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		vector<CandidateType>::const_iterator it;
		if (searchCandidateLocation(searchSSN, it))
		{
			it->printName();
		}
		else
		{
			cerr << "SSN is not in the list." << endl;
		}
	}
}

void CandidateList::printAllCandidates() const
{
	if (candidates->empty())
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		vector<CandidateType>::const_iterator current = candidates->begin();

		while (current != candidates->end())
		{
			current->printCandidateInfo();
			current++;
		}
	}
}

void CandidateList::printCandidateDivisionVotes(int searchSSN, int searchDivisionNum) const
{
	if (candidates->empty())
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		vector<CandidateType>::const_iterator it;
		if (searchCandidateLocation(searchSSN, it))
		{
			cout << "Division " << searchDivisionNum << ": " <<
				 it->getVotesByDivision(searchDivisionNum) << endl;
		}
		else
		{
			cerr << "SSN is not in the list." << endl;
		}
	}
}

void CandidateList::printCandidateTotalVotes(int searchSSN) const
{
	if (candidates->empty())
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		vector<CandidateType>::const_iterator it;
		if (searchCandidateLocation(searchSSN, it))
		{
			cout << "Total Votes: " << it->getTotalVotes() << endl;
		}
		else
		{
			cerr << "SSN is not in the list." << endl;
		}
	}
}

bool CandidateList::searchCandidate(int searchSSN) const
{
	bool found = false;
	vector<CandidateType>::const_iterator current = candidates->begin();

	while (!found && current != candidates->end())
	{
		if (current->getSSN() == searchSSN)
			found = true;
		else
			current++;
	}
	return found;
}

bool CandidateList::searchCandidateLocation(int searchSSN, vector<CandidateType>::const_iterator& location) const
{
	bool found = false;

	location = candidates->begin();

	while (!found && location != candidates->end())
	{
		if (location->getSSN() == searchSSN)
			found = true;
		else
			location++;
	}
	return found;
}

void CandidateList::printHighestToLowestVotes() const
{
	if (candidates->empty())
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		map<int, string> candidatesMap;
		map<int, string>::reverse_iterator itMap;
		string name;
		vector<CandidateType>::const_iterator current = candidates->begin();

		while (current != candidates->end())
		{
			name = current->getFirstName() + " " + current->getLastName();
			candidatesMap.insert(make_pair(current->getTotalVotes(), name));
			current++;
		}

		int order = 1;
		for (itMap = candidatesMap.rbegin(); itMap != candidatesMap.rend(); ++itMap)
		{
			cout << "   " << setw(2) << order << " | " << setw(3) << itMap->first 
				 << " | " << itMap->second << endl;
			++order;
		}
	}
}

CandidateList::CandidateList(const CandidateList& otherCandidateList)
{
	candidates = new vector<CandidateType>;
	int size = otherCandidateList.candidates->size();
	for (int i = 0; i < size; ++i)
	{
		candidates->push_back(otherCandidateList.candidates->at(i));
	}
}

CandidateList& CandidateList::operator=(const CandidateList& rightSide)
{
	candidates = new vector<CandidateType>;
	candidates->resize(rightSide.candidates->size());
	
	int size = candidates->size();
	for (int i = 0; i < size; ++i)
	{
		candidates->at(i) = rightSide.candidates->at(i);
	}

	return *this;
}

CandidateList::~CandidateList()
{
	delete candidates;
	candidates = NULL;
}
