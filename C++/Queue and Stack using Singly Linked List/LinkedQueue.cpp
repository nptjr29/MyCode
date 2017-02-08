#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
{
	first = NULL;
	rear = first;
	count = 0;
}

//no overloaded constructor

bool LinkedQueue::empty() const
{
	return(first == rear);
}

void LinkedQueue::push(int item)
{
	Node *newNode = new Node(item, NULL);
	
	//insert into empty queue
	if (empty())
	{
		first = newNode;
		rear = newNode;
	}
	//insert into occupied queue
	else
	{
		//insert into rear
		rear->setNext(newNode);
		//set a new rear
		rear = newNode;
	}

	++count;
}

void LinkedQueue::pop()
{
	//queue is empty
	if (empty())
	{
		cerr << "Queue is empty." << endl;
	}
	//queue is not empty
	else
	{
		Node *temp = first->getNext();

		delete first;
		first = temp;

		--count;
	}

	if (count == 0)
		rear = NULL;
}

int LinkedQueue::front() const
{
	//queue is empty
	if (empty())
	{
		cerr << "Queue is empty." << endl;
		return 0;
	}
	//queue is not empty
	else
	{
		return (first->getData());
	}
}

int LinkedQueue::size() const
{
	return count;
}

//copy constructor goes here

//overloaded assignment operator goes here

LinkedQueue::~LinkedQueue()
{
	while (!empty())
	{
		Node *temp = first;
		first = first->getNext();
		delete temp;
		temp = NULL;
		--count;
	}
	rear = NULL;
}