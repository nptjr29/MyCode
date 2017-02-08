/*
 *	Nguyen, Thao
 *	CS A262
 *	February 15, 2015
 *
 *	Exercise 6 - Hash Table
 */

#include "HashTable.h"

#include <iostream>
using namespace std;

int main()
{
	int a1[] = {45,32,65,24,91,67,82,46,73,12,58};
	int numOfElem1 = 11;

	HashTable ht1;
	
	cout << "Insert half of the array into the hash table...\n";
	for (int i = 0; i < (numOfElem1 / 2); ++i)
		ht1.insert(a1[i]);

	cout << ht1;
	cout << endl;

	cout << "\nInsert the rest of the array into the hash table...\n";
	for (int i = (numOfElem1 / 2); i < numOfElem1; ++i)
		ht1.insert(a1[i]);

	cout << ht1;
	cout << endl;

	cout << "\nStart searching...\n";
	for (int i = numOfElem1 - 1; i >= 0; --i)
	{
		if (ht1.search(a1[i]))
			cout << a1[i] << " found." << endl;
		else
			cout << a1[i] << " not found." << endl;
	}

	(ht1.search(999))? cout << "999 found.\n" : cout << "999 not found.\n";
	cout << endl;

	cout << "\nTry inserting another item => Expected: Error message\n";
	ht1.insert(35);
	cout << endl;

	cout << "\nTest copy constructor...\n";
	HashTable ht2 (ht1);
	cout << ht2;
	cout << endl;

	cout << "\nCheck if different addresses (should be different)...\n";
	cout << "Address ht1: " << &ht1 << endl;
	cout << "Address ht2: " << &ht2 << endl;
	cout << endl;

	cout << "\nTest overloaded assignment operator...\n";
	HashTable ht3;
	ht3 = ht1;
	cout << ht3;
	cout << endl;
	
	cout << "\nCheck if different addresses (should be different)...\n";
	cout << "Address ht1: " << &ht1 << endl;
	cout << "Address ht3: " << &ht3 << endl;
	cout << endl;

	cout << endl;
	system("Pause");
	return 0;
}