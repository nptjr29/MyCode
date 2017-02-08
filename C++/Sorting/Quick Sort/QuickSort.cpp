/*
	Nguyen, Thao
	CS A200
	April 22, 2014

	Exercise 23
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Declaration function quickSort
// Running time: O(n log n)
void quickSort(int a[], int first, int last);

// Declaration function partition
int partition(int a[], int& first, int& last);

// Declaration of function swap
void swap(int& n1, int& n2);

// Declaration function print
void print(const int a[], int numOfElements);

////////////////////////////////////////////////////////////////////////

// Definition function quickSort
void quickSort(int a[], int first, int last)
{
	if (first < last)
	{
		int pivot;
		pivot = partition(a, first, last);
		quickSort(a, first, pivot - 1);
		quickSort(a, pivot + 1, last);
	}
	
}

// Definition function partition
int partition(int a[], int& first, int& last)
{
	int pivot = ((first + last) / 2);
	int temp = a[pivot];
	swap(a[first], a[pivot]);

	int h = first + 1;
	int k = last;

	while (h <= k)
	{
		if (a[h] <= temp)
			++h;
		else
		{
			if (a[k] >= temp)
				--k;
			else
				swap(a[h], a[k]);
		}
	}
	swap(a[k], a[first]);

	return k;
}

// Definition function swap
void swap(int& n1, int& n2)
{
	int	temp = n1;
	n1 = n2;
	n2 = temp;
}

// Definition function print
void print(const int a[], int numOfElements)
{
	if (numOfElements == 0)
		cerr << "Array is empty." << endl;
	else
	{
		for (int i = 0; i < numOfElements; ++i)
			cout << a[i] << " ";
	}
	cout << endl;
}

////////////////////////////////////////////////////////////////////////

const int SMALL_CAP = 6;
const int BIG_CAP = 1000;

int main()
{
	int aSmall[] = { 1, 7, 4, 3, 6, 0 };

	int aBig[BIG_CAP];

	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < SMALL_CAP; ++i)
		aBig[i] = 1 + rand() % (SMALL_CAP * 10);

	cout << "Small array is : ";
	print(aSmall, SMALL_CAP);

	quickSort(aSmall, 0, (SMALL_CAP - 1));

	cout << "Sorted small array is: ";
	print(aSmall, SMALL_CAP);
	cout << endl;

	cout << "Big array is : ";
	print(aBig, BIG_CAP);

	quickSort(aBig, 0, (BIG_CAP - 1));

	cout << endl;
	cout << "Sorted big array is: ";
	print(aBig, BIG_CAP);
	cout << endl;

	cout << endl;
	system("Pause");
	return 0;
}