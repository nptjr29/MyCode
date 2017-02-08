#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

class DArray
{
public:
    DArray( );
    DArray(int);
	
	int getNumOfElem() const;
	int getFirst() const;
	void swap(int n1, int n2) const;
	void print() const;
	void setRoot(int);
	int getRoot() const;

	int getParent(int index) const;			
	int getLeftChild(int index) const;		

	void insertMin(int data);	
	void removeMin();			
	void bubbleUpMin() const;	
	void bubbleDownMin() const;	
	void removeAllMin();		

	void insertMax(int data);	
	void removeMax();			
	void bubbleUpMax() const;	
	void bubbleDownMax() const;	
	void removeAllMax();		

	~DArray( ); 

private:
    int *a;			
    int capacity;	
    int numOfElements;
	int root;

};

#endif