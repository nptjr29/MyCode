#include "LinkedStack.h"

LinkedStack::LinkedStack()
{
	linkTop = NULL;
	count = 0;
}

bool LinkedStack::empty() const
{
	return (linkTop == NULL);
}

void LinkedStack::pop()
{
	//if stack is empty
	if (empty())
	{
		cerr << "Stack is empty." << endl;
	}
	//if stack is not empty
	else
	{
		Node *temp = linkTop->getNext();

		delete linkTop;
		linkTop = temp;
		--count;
	}
}

void LinkedStack::push(int item)
{
	Node *newNode = new Node(item, NULL);
	//if stack is empty
	if (empty())
	{
		linkTop = newNode;
	}
	//if stack is not empty
	else
	{
		newNode->setNext(linkTop);
		linkTop = newNode;
	}

	++count;
}

int LinkedStack::size() const
{
	return count;
}

int LinkedStack::top() const
{
	return (linkTop->getData());
}

//copy constructor goes here

//overloaded assignment operator goes here

LinkedStack::~LinkedStack()
{
	while (count != 0)
	{
		Node *temp = linkTop;
		linkTop = linkTop->getNext();
		delete temp;
		temp = NULL;
		--count;
	}
	linkTop = NULL;
}