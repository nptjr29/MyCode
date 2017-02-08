/*
	Nguyen, Thao
	CS A200
	Feb 4, 2015

	Exercise 3 - Array Stacks
*/

#include <iostream>
using namespace std;

// Declaration of function processStacks
void processStacks(int a[], int capacity, int& leftTop, int& rightTop);

// Declaration of function printSmallValues
void printSmallValues(int a[], int& leftTop);

// Declaration of function printLargeValues
void printLargeValues(int a[], int& rightTop, int capacity);

int main()
{
	int cap, leftTop, rightTop;

	cout << "Enter max number of integers: ";	
	cin >> cap;

	int *a = new int[cap] ;

	leftTop = 0;
	rightTop = (cap - 1);

	// call to function processStacks
	processStacks(a, cap, leftTop, rightTop);
	cout << endl;
	cout << endl;

	cout << "Stack with small values: ";
	// call to function printSmallValues
	printSmallValues(a, leftTop);

	cout << endl;

	cout << "Stack with large values: ";	
	// call to function printLargeValues
	printLargeValues(a, rightTop, cap);

	cout << endl;
	cout << endl;

	// what else?

	cout << endl;
	system("Pause");
	return 0;
}

// Definition of function processStacks
void processStacks(int a[], int capacity, int& leftTop, int& rightTop)
{
	int numOfElem = 0;
	cout << "Enter integers (-1 to quit): ";
	int num = 0;
	
	cin >> num;
	while ((num != -1) && (leftTop < capacity) && (rightTop > leftTop))
	{
		if (num < 1000 && num > -1)
		{
			a[leftTop] = num;
			++leftTop;
		}
		else
		{
			a[rightTop] = num;
			--rightTop;
		}

		cin >> num;
	}

	++rightTop;
	--leftTop;
}

// Definition of function printSmallValues
void printSmallValues(int a[], int& leftTop)
{
	while (leftTop >= 0)
	{
		cout << a[leftTop] << " " ;
		--leftTop;
	}
}

// Definition of function printLargeValues
void printLargeValues(int a[], int& rightTop, int capacity)
{
	while (rightTop < capacity)
	{
		cout << a[rightTop] << " ";
		++rightTop;
	}
}