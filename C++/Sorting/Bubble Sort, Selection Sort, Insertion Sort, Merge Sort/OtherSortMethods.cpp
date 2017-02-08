/*
	Thao Nguyen
	CS A200
	Exercise 22
	April 22, 2015
*/

/********************************************************************
	Program tests number of comparisons performed 
	by Bubble sort (flagged version), Selection sort, 
	Insertion sort, and Merge Sort.

	Testing can be performed on either a 6-length
	array or a 1000-length random-numbers array.
********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Declaration function bubbleSort
// Running time = O(n^2)
// Uses function swap
void bubbleSort(int a[], int& compBubble, int numOfElements);

// Declaration function selectionSort
// Running time = O(n^2)
// Uses function swap
// Uses function minLocation
void selectionSort(int a[], int& compSelection, int numOfElements);

// Declaration function minLocation
// Running time = O(n)
int minLocation(const int a[], int& i, int numOfElements, int& compSelection);

// Declaration function insertionSort
// Running time: O(n^2) 
void insertionSort(int a[], int& compInsertion, int numOfElements);

// Declaration function mergeSort
// Running time: O(n log n) => this includes the call to function merge
// Uses function merge
void mergeSort(int a[], int& compMergeSort, int numOfElements);

// Declaration function merge
// Running time: O(n)
void merge(int *A, int *L, int leftCount, int *R, int rightCount, int& compare);

// Already implemented
void print(const int a[], int numOfElements);
void swap(int& n1, int& n2);
void testSmallArray(int a[], int numOfElements);  // testing cases
void testAllSmallArrays();
void testBigArray();

const int SMALL_CAP = 6;
const int BIG_CAP = 1000;

int main()
{
	testAllSmallArrays();

	testBigArray();
	
	cout << endl;
	system("Pause");
	return 0;
}

// Definition function bubbleSort
void bubbleSort(int a[], int& compBubble, int numOfElements)
{
	int j = 0;
	bool swapDone = true;
	while (swapDone && j < numOfElements - 1)
	{
		swapDone = false;
		for (int i = 0; i < (numOfElements - 1 - j); ++i)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				swapDone = true;
			}
			++compBubble;
		}
		++j;
	}
}

// Definition function selectionSort
void selectionSort(int a[], int& compSelection, int numOfElements)
{
	int minIndex;

	int comp = 0;
	for (int i = 0; i < numOfElements - 1; ++i)
	{
		minIndex = minLocation(a, i, numOfElements, compSelection);
		swap(a[i], a[minIndex]);
	}

}

// Definition function minLocation
int minLocation(const int a[], int& i, int numOfElements, int& compSelection)
{
	int loc, minIndex;
	minIndex = i;

	for (loc = i + 1; loc <= numOfElements - 1; ++loc)
	{
		if (a[loc] < a[minIndex])
		{
			minIndex = loc;

		}

		++compSelection;
	}

	return minIndex;
}

// Definition function insertionSort
void insertionSort(int a[], int& compInsertion, int numOfElements)
{
	int j, temp;
	for (int i = 1; i < numOfElements; i++)
	{
		j = i;

		while (j > 0 && a[j - 1] > a[j])
		{
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
			++compInsertion;
		}
		++compInsertion;
	}
}

// Definition function mergeSort
void mergeSort(int a[], int& comp, int numOfElements)
{
	if (numOfElements > 1)
	{
		int* firstHalf = new int[numOfElements / 2];
		int firstHalfLength = numOfElements / 2;
		for (int i = 0; i < firstHalfLength; i++)
		{
			firstHalf[i] = a[i];
		}

		int* secondHalf = new int[numOfElements - firstHalfLength];
		int secondHalfLength = numOfElements - firstHalfLength;
		for (int i = 0; i < secondHalfLength; i++) \
		{
			secondHalf[i] = a[firstHalfLength + i];
		}

		mergeSort(firstHalf, comp, firstHalfLength);
		mergeSort(secondHalf, comp, secondHalfLength);
		/*merge(a, numOfElements, firstHalf, secondHalf, firstHalfLength, secondHalfLength, comp);*/

		merge(a, firstHalf, firstHalfLength, secondHalf, secondHalfLength, comp);
		// Merging L and R into A as sorted list. 
	}
}

// Definition function merge
void merge(int *A, int *L, int leftCount, int *R, int rightCount, int& compare)
{
	int i, j, k;

	// i - to mark the index of left aubarray (L) 
	// j - to mark the index of right sub-raay (R) 
	// k - to mark the index of merged subarray (A) 
	i = 0;
	j = 0;
	k = 0;

	while (i<leftCount && j< rightCount)
	{
		if (L[i] < R[j])
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
		compare++;
	}

	while (i < leftCount)
		A[k++] = L[i++];

	while (j < rightCount)
		A[k++] = R[j++];
}


void print(const int a[], int numOfElements)
{
	for (int i = 0; i < numOfElements; ++i)
		cout << a[i] << " ";
}

void swap(int& n1, int& n2)
{
	int	temp = n1;
	n1 = n2;
	n2 = temp;
}

void testAllSmallArrays()
{
	int numOfElements = 6;

	int a1[] = { 5, 4, 3, 2, 1, 0 }; 
	testSmallArray(a1, numOfElements);

	int a2[] = { 0, 1, 2, 3, 4, 5 };	
	testSmallArray(a2, numOfElements);

	int a3[] = { 3, 4, 5, 0, 1, 2 };
	testSmallArray(a3, numOfElements);

	int a4[] = { 2, 1, 0, 3, 4, 5 };	
	testSmallArray(a4, numOfElements);

	int a5[] = { 0, 1, 2, 5, 4, 3 };	
	testSmallArray(a5, numOfElements);
}

void testSmallArray(int a[], int numOfElements)
{
	cout << "Array is:\n\n";
	print(a,numOfElements);
	cout << endl;

	//TESTING BUBBLE SORT
	int compBubble = 0;
	bubbleSort(a, compBubble, numOfElements);
	cout << "\nBubble sort:       ";
	print(a, numOfElements);

	//TESTING SELECTION SORT
	int compSelection = 0;
	selectionSort(a, compSelection, numOfElements);
	cout << "\nSelection sort is: ";
	print(a, numOfElements);

	//TESTING INSERTION SORT
	int compInsertion = 0;
	insertionSort(a, compInsertion, numOfElements);
	cout << "\nInsertion Sort is: ";
	print(a, numOfElements);

	//TESTING MERGE SORT
	int compMergeSort = 0;
	mergeSort(a, compMergeSort, numOfElements);
	cout << "\nMerge Sort is:     ";
	print(a, numOfElements);

	cout << "\n\nResults: " << endl
		<< "    BUBBLE SORT    NUMBER OF COMPARISONS:   " << compBubble
		<< "\n    SELECTION SORT NUMBER OF COMPARISONS:   " << compSelection
		<< "\n    INSERTION SORT NUMBER OF COMPARISONS:   " << compInsertion
		<< "\n    MERGE SORT     NUMBER OF COMPARISONS:   " << compMergeSort
		<< endl;
	cout << "\n\n--------------------------------------------\n";
}

void bigArray(int a[], int& numOfElements)
{
	numOfElements = BIG_CAP;

	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < numOfElements; ++i)
		a[i] = 1 + rand() % (numOfElements * 10);
}

void testBigArray()
{
	int numOfElements = BIG_CAP;

	int a[BIG_CAP];

	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < numOfElements; ++i)
		a[i] = 1 + rand() % (numOfElements * 10);

	cout << "BIG ARRAY\n";
	//print(a, numOfElements);
	//cout << endl;

	//copy arrays to use with all functions
	int aBubble[BIG_CAP];
	int aSelection[BIG_CAP];
	int aInsertion[BIG_CAP];
	int aMerge[BIG_CAP];
	//int aQuick[BIG_CAP];

	for (int i = 0; i < numOfElements; ++i)
	{
		aBubble[i] = a[i];
		aSelection[i] = a[i];
		aInsertion[i] = a[i];
		aMerge[i] = a[i];
		//aQuick[i] = a[i];
	}

	////TESTING BUBBLE SORT
	int compBubble = 0;
	bubbleSort(aBubble, compBubble, numOfElements);
	//cout << "\nBubble sort:\n";
	//print(aBubble, numOfElements);

	//TESTING SELECTION SORT
	int compSelection = 0;
	selectionSort(aSelection, compSelection, numOfElements);
	//cout << "\nSelection sort is:\n";
	//print(aSelection, numOfElements);

	////TESTING INSERTION SORT
	int compInsertion = 0;
	insertionSort(aInsertion, compInsertion, numOfElements);
	//cout << "\nInsertion Sort is:\n";
	//print(aInsertion, numOfElements);

	////TESTING MERGE SORT
	int compMergeSort = 0;
	mergeSort(aMerge, compMergeSort, numOfElements);
	////cout << "\nMerge Sort is:\n";
	////print(aMerge, numOfElements);

	cout << "\nResults: " << endl
		<< "    BUBBLE SORT    NUMBER OF COMPARISONS:   " << compBubble
		<< "\n    SELECTION SORT NUMBER OF COMPARISONS:   " << compSelection
		<< "\n    INSERTION SORT NUMBER OF COMPARISONS:   " << compInsertion
		<< "\n    MERGE SORT     NUMBER OF COMPARISONS:   " << compMergeSort
		<< endl;
}

