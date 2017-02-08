/*
	Nguyen, Thao
	CS A200
	February 27, 2015

	Exercise 10
*/

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

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

class LinkedQueue
{
public:
	LinkedQueue();
	//no overloaded constructor
	bool empty() const;
	void push(int item);
	void pop();
	int front() const;
	int size() const;
	//copy constructor goes here
	//overloaded assignment operator goes here
	~LinkedQueue();

private:
	Node *first; //pointer to front of queue
	Node *rear; //pointer to rear of queue 
	int count;
};


#endif