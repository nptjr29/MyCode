#include "CircularQueue.h"

template<typename T>
CircularQueue<T>::CircularQueue()
{
	cirQueue = new T[CAPACITY];
	f = 0;
	r = f;

	////initialize all elements to 0
	//for (int i = f; i < r; ++i)
	//{
	//	cirQueue[i] = 0;
	//}

}

template<typename T>
CircularQueue<T>::CircularQueue(int newCapacity)
{
	cirQueue = new T[newCapacity];
	f = 0;
	r = f;

	////initialize all elements to 0
	//for (int i = f; i < r; ++i)
	//{
	//	cirQueue[i] = 0;
	//}
}

template<typename T>
bool CircularQueue<T>::empty() const
{
	return (f == r);
}

template<typename T>
void CircularQueue<T>::push(const T& item)
{
	//check if queue is full
	if (size() >= (CAPACITY - 1))
	{
		cerr << "Queue is full." << endl;
	}
	//insert
	else
	{
		cirQueue[r] = item;
		r = ((r + 1) % CAPACITY);
	}
}

template<typename T>
void CircularQueue<T>::pop()
{
	//check if queue is empty
	if (empty())
	{
		cerr << "Queue is empty." << endl;
	}
	//remove the front element
	else
	{
		//cirQueue[f] = 0; //only applicable for int a[]
		f = ((f + 1) % CAPACITY);
	}
}

template<typename T>
const T& CircularQueue<T>::front() const
{
	//check if empty
	if (empty())
	{
		cerr << "Queue is empty";
		return 0;
	}
	else
	{
		return cirQueue[f];
	}

}

template<typename T>
int CircularQueue<T>::size() const
{
	return ((CAPACITY - f + r) % CAPACITY);
}

//copy constructor goes here
//overloaded assignment operator goes here

template<typename T>
CircularQueue<T>::~CircularQueue()
{
	delete[] cirQueue;
	cirQueue = NULL;
	f = 0;
	r = f;
}