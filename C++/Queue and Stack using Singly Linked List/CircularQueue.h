#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <iostream>
using namespace std;

const int CAPACITY = 11;

template<typename T>
class CircularQueue
{
public:
	CircularQueue();
	CircularQueue(int newCapacity);
	bool empty() const;
	void push(const T& item);
	void pop();
	const T& front() const;
	int size() const;
	//copy constructor goes here
	//overloaded assignment operator goes here

	~CircularQueue();

private:
	T *cirQueue;
	int f;
	int r;

};


#endif