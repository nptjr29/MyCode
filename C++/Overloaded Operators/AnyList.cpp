/*
	Thao Nguyen
	CS A250
	September 30, 2014

	Exercise 6
*/

#include "AnyList.h"


//constructor
AnyList::AnyList()
{
	first = NULL;
	count = 0;
}

//insertFront
void AnyList::insertFront(const int a[], int numOfElem)
{	
	for (int i = 0; i < numOfElem; ++i)
	{
		Node *temp = new Node(a[i], first);
		first = temp;
	}

	count = numOfElem;
}

//getNumOfElem
int AnyList::getNumOfElem() const
{
	return count;
}

//destroyList
void AnyList::destroyList()
{ 
    Node  *temp; //pointer to delete the node
	
	while (first != NULL)
    {
		temp = first;
		first = first->getNext();
        delete temp;
		temp = NULL;
    }

	count = 0;
}

//destructor
AnyList::~AnyList()
{
	destroyList();
}

// Definition of overloaded insertion stream operator as a friend functionn
ostream& operator<<(ostream& out, const AnyList& myList)
{
	if (myList.first == NULL)
	{
		cerr << "List is empty.";
	}
	else
	{
		Node * temp;
		temp = myList.first;

		while (temp != NULL)
		{
			out << temp->getData() << " ";
			temp = temp->getNext();
		}

		temp = NULL;
	}
	return out;
}

// Definition of overloaded comparison operator == as a member function
bool AnyList::operator==(const AnyList& myList) const
{
	if (count != myList.count)
	{
		return false;
	}
	else
	{
		Node * temp1;
		Node * temp2;

		temp1 = first;
		temp2 = myList.first;

		while ((temp1 != NULL) && (temp1->getData() == temp2->getData()) )
		{
			temp1 = temp1->getNext();
			temp2 = temp2->getNext();
		}

		if (temp1 == NULL)
			return true;
		else
			return false;
	}
}



