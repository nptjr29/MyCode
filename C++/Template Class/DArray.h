/*
Nguyen, Thao
CS A150
October 14, 2014

Exercise 10
*/

#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

template<typename T>
class DArray
{
public:
    DArray( );
    //Default constructor -	initializes array 
	//						with a capacity of 50.

    DArray(int);
	//Constructor - initializes array with a given capacity.
	//@param int - capacity of the array.

	void addElement(const T&);
    //addElement - adds an element to the array.
	//@param int - the element to add to the array.

	bool full() const;
	int getCapacity() const;
	int getNumberUsed() const;
	void emptyArray();
	T getElementAt(int index) const;
	void printArray() const;

	~DArray( ); 
	//Destructor

private:
    T *a;			//will point to an int (it will be an array)
    int capacity;	//capacity of the array
    int used;		//total number of elements in the array

};

#endif