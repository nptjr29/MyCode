/*	
	Nguyen, Thao
	CS A200
	March 1, 2015

	Exercise 10
*/

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>
using namespace std;

class Node
{
public:
	Node() : data(0), next(NULL) {}
	Node(int theData, Node *newNext) : data(theData), next(newNext){}
	Node* getNext() const { return next; }
	int getData() const { return data; }
	void setData(int theData) { data = theData; }
	void setNext(Node *newNext) { next = newNext; }
	~Node(){}
private:
	int data;
	Node *next;	//pointer that points to next node
};

class LinkedStack
{
public:
	LinkedStack();
	bool empty() const;
	void pop();
	void push(int item);
	int size() const;
	int top() const;
	//copy constructor goes here
	//overloaded assignment operator goes here
	~LinkedStack();

private:
	Node *linkTop;
	int count;
};


#endif