/*
	Nguyen, Thao
	CS A200
	February 25, 2015

	Exercise 10
*/

#include "CircularQueue.h"
#include "LinkedStack.h"
//#include "LinkedQueue.h"
#include "CircularQueue.cpp"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a1[] = { 45, 32, 65, 24, 91, 67, 82, 46, 73, 12 };

	cout << "****TESTING LINKED STACK****\n\n" << endl;

	LinkedStack ls1;

	cout << "Insert half of the array into the stack..." << endl;
	for (int i = 0; i < 5; ++i)
	{
		ls1.push(a1[i]);
	}

	cout << "Size of the stack is: " << ls1.size() << endl;
	cout << "\nStack is: ";

	if (ls1.empty())
		cout << "Stack is empty." << endl;
	else
	{
		for (int i = 0; i < 5; ++i)
		{
			cout << ls1.top() << " ";
			ls1.pop();
		}
	}

	cout << "\nExpected output: 91 24 65 32 45" << endl;

	LinkedStack ls2;

	cout << "\n\nInsert all of the array into the stack..." << endl;
	for (int i = 0; i < 10; ++i)
	{
		ls2.push(a1[i]);
	}

	cout << "Size of the stack is: " << ls2.size() << endl;

	cout << "\nStack is: ";
	if (ls2.empty())
		cout << "Queue is empty." << endl;
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << ls2.top() << " ";
			ls2.pop();
		}
	}

	cout << "\nExpected output: 12 73 46 82 67 91 24 65 32 45" << endl;

	LinkedStack ls3;

	cout << "\nCreating an empty stack..." << endl;
	cout << "\nSize of the stack is: " << ls3.size() << endl;

	if (ls3.empty())
		cout << "Stack is empty." << endl;
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << ls3.top() << " ";
			ls3.pop();
		}
	}

	cout << "\nExpected output: Stack is empty." << endl;

	/////////////////////////////////////////////////////////////////////////////////////
	/*cout << "\n*************************************************\n";
	cout << "\n****TESTING LINKED QUEUE****\n\n" << endl;

	LinkedQueue lq1;

	cout << "Insert half of the array into the queue..." << endl;
	for (int i = 0; i < 5; ++i)
	{
		lq1.push(a1[i]);
	}

	cout << "Size of the queue is: " << lq1.size() << endl;
	cout << "Queue is: ";

	if (lq1.empty())
		cout << "Queue is empty." << endl;
	else
	{
		for (int i = 0; i < 5; ++i)
		{
			cout << lq1.front() << " ";
			lq1.pop();
		}
	}

	cout << "\nExpected output: 45 32 65 24 91" << endl;

	LinkedQueue lq2;

	cout << "\n\nInsert all of the array into the queue..." << endl;
	for (int i = 0; i < 10; ++i)
	{
		lq2.push(a1[i]);
	}

	cout << "Size of the queue is: " << lq2.size() << endl;

	cout << "\nQueue is: ";
	if (lq2.empty())
		cout << "Queue is empty." << endl;
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << lq2.front() << " ";
			lq2.pop();
		}
	}

	cout << "\nExpected output: 45 32 65 24 91 67 82 46 73 12" << endl;

	LinkedQueue lq3;

	cout << "\nCreating an empty queue..." << endl;
	cout << "\nSize of the queue is: " << lq3.size() << endl;

	if (lq3.empty())
		cout << "Queue is empty." << endl;
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << lq3.front() << " ";
			lq3.pop();
		}
	}

	cout << "\nExpected output: Queue is empty." << endl;
*/


	/////////////////////////////////////////////////////////////////////////////////////
	cout << "\n*************************************************\n";
	cout << "\n****TESTING CIRCULAR QUEUE****\n\n" << endl;
	cout << "\nTesting int array........................" << endl;

	CircularQueue<int> cq1;

	cout << "\nInsert half of the array into the queue..." << endl;
	for (int i = 0; i < 5; ++i)
	{
		cq1.push(a1[i]);
	}

	cout << "Size of the queue is: " << cq1.size() << endl;
	cout << "Queue is: ";

	if (cq1.empty())
		cout << "Queue is empty." << endl;
	else
	{
		for (int i = 0; i < 5; ++i)
		{
			cout << cq1.front() << " ";
			cq1.pop();
		}
	}

	cout << "\nExpected output: 45 32 65 24 91" << endl;

	CircularQueue<int> cq2;

	cout << "\n\nInsert all of the array into the queue..." << endl;
	for (int i = 0; i < 10; ++i)
	{
		cq2.push(a1[i]);
	}

	cout << "Size of the queue is: " << cq2.size() << endl;

	cout << "\nAttempt to insert into a full queue... Expected error message." << endl;

	cq2.push(999);
	cout << "\nQueue is: ";
	if (cq2.empty())
		cout << "Queue is empty." << endl;
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << cq2.front() << " ";
			cq2.pop();
		}
	}

	cout << "\nExpected output: 45 32 65 24 91 67 82 46 73 12" << endl;

	CircularQueue<int> cq3;
	
	cout << "\nCreating an empty queue..." << endl;
	cout << "\nSize of the queue is: " << cq3.size() << endl;

	if (cq3.empty())
		cout << "Queue is empty." << endl;
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << cq3.front() << " ";
			cq3.pop();
		}
	}

	cout << "\nExpected output: Queue is empty." << endl;

	cout << "\nTest string array....................\n" << endl;

	string a2[] = { "45", "32", "65", "24", "91", "67", "82", "46", "73", "12" };

	CircularQueue<string> cq4;

	cout << "Insert half of the array into the queue..." << endl;
	for (int i = 0; i < 5; ++i)
	{
		cq4.push(a2[i]);
	}

	cout << "Size of the queue is: " << cq4.size() << endl;
	cout << "Queue is: ";

	if (cq4.empty())
		cout << "Queue is empty." << endl;
	else
	{
		for (int i = 0; i < 5; ++i)
		{
			cout << cq4.front() << " ";
			cq4.pop();
		}
	}

	cout << "\nExpected output: 45 32 65 24 91" << endl;

	CircularQueue<string> cq5;

	cout << "\n\nInsert all of the array into the queue..." << endl;
	for (int i = 0; i < 10; ++i)
	{
		cq5.push(a2[i]);
	}

	cout << "Size of the queue is: " << cq5.size() << endl;

	cout << "\nAttempt to insert into a full queue... Expected error message." << endl;

	cq5.push("999");
	cout << "\nQueue is: ";
	if (cq5.empty())
		cout << "Queue is empty." << endl;
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << cq5.front() << " ";
			cq5.pop();
		}
	}

	cout << "\nExpected output: 45 32 65 24 91 67 82 46 73 12" << endl;

	CircularQueue<string> cq6;

	cout << "\nCreating an empty queue..." << endl;
	cout << "\nSize of the queue is: " << cq6.size() << endl;

	if (cq6.empty())
		cout << "Queue is empty." << endl;
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << cq6.front() << " ";
			cq6.pop();
		}
	}

	cout << "\nExpected output: Queue is empty." << endl;

	cout << endl;
	system("Pause");
	return 0;
}