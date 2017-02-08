#include "DArray.h"
DArray::DArray( )
{
    capacity = 50;
	a = new int[capacity];	
	numOfElements = 0;
	root = 0;
}

DArray::DArray(int newCapacity) 
{
	capacity = newCapacity;
    a = new int[capacity];
	numOfElements = 0;
	root = 0;
}

int DArray::getNumOfElem() const
{
	return numOfElements;
}

void DArray::swap(int n1, int n2) const
{
	int temp = a[n1];
	a[n1] = a[n2];
	a[n2] = temp;
}

int DArray::getFirst() const
{
	return a[root];
}

void DArray::print() const
{
	if (numOfElements == 0)
		cerr << "Array is empty.";
	for (int i = root; i < (numOfElements + root); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void DArray::setRoot(int newRoot)
{
	root = newRoot;
}

int DArray::getRoot() const
{
	return root;
}

int DArray::getParent(int index) const
{
	return ((index + root - 1) / 2);
}

int DArray::getLeftChild(int index) const
{
	return ((index * 2) - root + 1);
}

void DArray::insertMin(int data)
{
	if (numOfElements < (capacity - root))
	{
		a[numOfElements + root] = data;
		++numOfElements;
		bubbleUpMin();
	}
	else
	{
		cerr << "Attempt to exceed capacity in DArray.\n";
	}
}
void DArray::removeMin()
{
	if (numOfElements > 0)
	{
		numOfElements--;
		a[root] = a[numOfElements + root];
		bubbleDownMin();
	}
	else
	{
		cerr << "Array is empty." << endl;
	}
}


void DArray::bubbleUpMin() const
{
	int index = numOfElements + root - 1;
	int parent = getParent(index);

	while (index > root && a[parent] > a[index])
	{
		//swap if parent is larger than child (out of min-heap order)
		swap(index, parent);
		//go up the tree
		index = parent;
		parent = getParent(index);
	}

}

void DArray::bubbleDownMin() const
{
	int index = root;
	int child = getLeftChild(index);
	bool done = false;

	while (!done && child < (numOfElements + root))
	{
		if ((child + 1) < (numOfElements + root))
		{
			//get the smaller child of the 2 children
			if (a[child + 1] < a[child])
				child++;
		}

		//swap if child is smaller than index
		if (a[child] < a[index])
		{
			swap(child, index);
			index = child;
			child = getLeftChild(index);
		}
		else
		{
			done = true;
		}
	}

}

void DArray::removeAllMin()
{
	if (numOfElements <= 0)
		cerr << "Array is empty.";
	else
	{
		cout << "Sorted array is: ";

		while (numOfElements > 0)
		{
			cout << a[root] << " ";
			//removeMin();
			--numOfElements;
			a[root] = a[numOfElements + root];
			bubbleDownMin();
		}
	}
		
	cout << endl;
}

void DArray::insertMax(int data)
{
	if (numOfElements < (capacity - root))
	{
		a[numOfElements + root] = data;
		++numOfElements;
		bubbleUpMax();
	}
	else
	{
		cerr << "Attempt to exceed capacity in DArray.\n";
	}
}

void DArray::removeMax()
{
	if (numOfElements > 0)
	{
		--numOfElements;
		a[root] = a[numOfElements + root];
		bubbleDownMax();
	}
	else
	{
		cerr << "Array is empty." << endl;
	}
}

void DArray::bubbleUpMax() const
{
	int index = numOfElements + root - 1;
	int parent = getParent(index);
	
	while (index > root && a[parent] < a[index])
	{
		swap(index, parent);
		index = parent;
		parent = getParent(index);
	}
}

void DArray::bubbleDownMax() const
{
	int index = root;
	int child = getLeftChild(index);
	bool done = false;

	while (!done && child < (numOfElements + root))
	{
		if ((child + 1) < (numOfElements + root))
		{
			if (a[child + 1] > a[child])
				++child;
		}

		if (a[child] > a[index])
		{
			swap(child, index);
			index = child;
			child = getLeftChild(index);
		}
		else
		{
			done = true;
		}
	}

}

void DArray::removeAllMax()
{
	if (numOfElements <= 0)
	{
		cerr << "Array is empty.";
	}
	else
	{
		cout << "Sorted array is: ";
		while (numOfElements > 0)
		{
			cout << a[root] << " ";
			--numOfElements;
			a[root] = a[numOfElements + root];
			bubbleDownMax();
		}
	}

	cout << endl;
}


DArray::~DArray( )
{
    delete [] a; //delete the array
	a = NULL;	 //null the pointer
}

