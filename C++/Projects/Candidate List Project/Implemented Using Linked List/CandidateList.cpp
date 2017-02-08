#include "CandidateList.h"

CandidateList::CandidateList()
{
	first = NULL;
	last = NULL;
	count = 0;
}

void CandidateList::addCandidate(const CandidateType& newCandidate)
{
	Node* newNode = new Node(newCandidate, NULL);
	
	if (first == NULL)
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		last->setLink(newNode);
		last = newNode;
	}
}

int CandidateList::getWinner() const
{
	if (first == NULL)
	{
		cerr << "List is empty." << endl;
		return 0;
	}
	else
	{
		Node * current;
		current = first;

		Node * winner;
		winner = first;

		int winnerVotes = current->getCandidate().getTotalVotes();

		while (current != NULL)
		{
			if (current->getCandidate().getTotalVotes() > winnerVotes)
			{
				winnerVotes = current->getCandidate().getTotalVotes();
				winner = current;
			}
			current = current->getLink();
		}

		return winner->getCandidate().getSSN();
	}
}

void CandidateList::printCandidateName(int searchSSN) const
{
	if (first == NULL)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		Node * current;
		current = first;
		bool found = false;

		while (!found && current != NULL)
		{
			if (current->getCandidate().getSSN() == searchSSN)
			{
				current->getCandidate().printName();
				found = true;
			}
			else
				current = current->getLink();
		}

		if (!found)
		{
			cerr << "SSN not in the list." << endl;
		}
	}
}

void CandidateList::printAllCandidates() const
{
	if (first == NULL)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		Node * current;
		current = first;

		while (current != NULL)
		{
			current->getCandidate().printCandidateInfo();
			current = current->getLink();
		}
	}
}

void CandidateList::printCandidateDivisionVotes(int searchSSN, int searchDivisionNum) const
{
	if (first == NULL)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		Node * current;
		current = first;
		bool found = false;

		while (!found && current != NULL)
		{
			if (current->getCandidate().getSSN() == searchSSN)
			{
				cout << "Division " << searchDivisionNum << ": " <<
				current->getCandidate().getVotesByDivision(searchDivisionNum) << endl;
				found = true;
			}
			else
				current = current->getLink();
		}
	}
}

void CandidateList::printCandidateTotalVotes(int searchSSN) const
{
	if (first == NULL)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		Node * current;
		current = first;
		bool found = false;

		while (!found && current != NULL)
		{
			if (current->getCandidate().getSSN() == searchSSN)
			{
				cout << "Total Votes: " << current->getCandidate().getTotalVotes() << endl;
				found = true;
			}
			else
				current = current->getLink();
		}
	}
}

void CandidateList::destroyList()
{
	if (first != NULL && last != NULL)
	{
		Node * current;
		current = first;

		while (current != NULL)
		{	
			current = first;
			first = first->getLink();
			delete current;
			current = NULL;
		}

		first = NULL;
		last = NULL;
		count = 0;
	}
}

CandidateList::~CandidateList()
{
	destroyList();
}
