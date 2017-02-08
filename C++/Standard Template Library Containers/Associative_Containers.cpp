/*
	Nguyen, Thao
	CS A250
	October 26, 2014

	Exercise 12
*/

#include <iostream>
#include <string>
#include <set>		// also multiset
#include <map>		// also multimap
#include <iterator>	// to use ostream_iterator

using namespace std;

int main()
{

	/***************************************************************************
			MAPS
	***************************************************************************/
	cout << "  ***  STL MAP CLASS  ***  \n\n";

	// Use the default contructor to create a map myMap of integers and strings.
	
	map<int, string> myMap;

	// Create an iterator to use with the map.

	map<int, string>::iterator itMap;

	// Use the function insert (void function) and the function make_pair to 
	// insert the following items into the map:
	//	3,three
	//	4,four
	//  2,two
	//  5,five
	//  1,one

	myMap.insert(make_pair(3, "three"));
	myMap.insert(make_pair(4, "four"));
	myMap.insert(make_pair(2, "two"));
	myMap.insert(make_pair(5, "five"));
	myMap.insert(make_pair(1, "one"));
	
	// Use a FOR loop and the iterator to print each pair of elements in the map.
	cout << "myMap: " << endl;

	for (itMap = myMap.begin(); itMap != myMap.end(); ++itMap)
	{
		cout << itMap->first << " " << itMap->second << endl;
	}

	cout << endl;
	// Use function empty to check if the map is empty and output an appropriate 
	// message.

	if (myMap.empty())
	{
		cout << "Map is empty." << endl;
	}
	else
	{
		cout << "Map is not empty." << endl;
	}

	cout << endl;
	// Use function size to output the size of the map.

	cout << "Size: " << myMap.size() << endl;


	cout << endl;
	// Use function max_size to output the size of the map.

	cout << "Max size: " << myMap.max_size() << endl;


	// Use the default contructor to create a map otherMap of integers and strings.

	map<int, string> otherMap;

	// Use the function insert (void function) and the function make_pair to 
	// insert the following items into the map:
	//	30,thirty
	//	20,twenty
	//  10,ten

	otherMap.insert(make_pair(30, "thirty"));
	otherMap.insert(make_pair(20, "twenty"));
	otherMap.insert(make_pair(10, "ten"));

	cout << endl;
	// Use a FOR loop and the iterator to print each pair of elements in the map.
	cout << "otherMap: " << endl;

	for (itMap = otherMap.begin(); itMap != otherMap.end(); ++itMap)
	{
		cout << itMap->first << " " << itMap->second << endl;
	}

	cout << endl;
	// Use function swap to swap maps.
	cout << "Swap" << endl;

	myMap.swap(otherMap);

	cout << endl;
	// Use a FOR loop and the iterator to print each pair of elements in myMap.
	cout << "myMap: " << endl;

	for (itMap = myMap.begin(); itMap != myMap.end(); ++itMap)
	{
		cout << itMap->first << " " << itMap->second << endl;
	}

	cout << endl;
	// Use a FOR loop and the iterator to print each pair of elements in otherMap.
	cout << "otherMap: " << endl;

	for (itMap = otherMap.begin(); itMap != otherMap.end(); ++itMap)
	{
		cout << itMap->first << " " << itMap->second << endl;
	}

	cout << endl;
	// Use function insert (void function) to insert 111 and "ha" in myMap.

	myMap.insert(pair<int, string>(111, "ha"));


	// Use a FOR loop and the iterator to print each pair of elements in myMap.
	cout << "myMap: " << endl; 

	for (itMap = myMap.begin(); itMap != myMap.end(); ++itMap)
	{
		cout << itMap->first << " " << itMap->second << endl;
	}

	cout << "\n(Other functions...)\n";
	/*
		!=
		==
		clear
		erase
	*/

	cout << "\nOther functions output:\n" << endl;

	// !=
	// Use overloaded != to compare myMap and otherMap. Output the result.

	cout << ((myMap != otherMap) ? "Different." : "Same.") << endl;
	cout << "Expected output: Different." << endl;

	// ==
	// Use overloaded == to compare myMap and otherMap. Output the result.

	cout << ((myMap == otherMap) ? "Same." : "Different.") << endl;
	cout << "Expected output: Different." << endl;

	// clear
	// Remove all elements from myMap

	myMap.clear();

	// erase
	// Remove the third element of otherMap

	itMap = otherMap.begin();
	++itMap;
	++itMap;

	otherMap.erase(itMap);

	// Print out myMap and otherMap

	if (myMap.empty())
		cout << "myMap is empty." << endl;
	else
	{
		for (itMap = myMap.begin(); itMap != myMap.end(); ++itMap)
		{
			cout << itMap->first << " " << itMap->second << endl;
		}
	}

	cout << "Expected output: myMap is empty." << endl;

	if (otherMap.empty())
		cout << "otherMap is empty." << endl;
	else
	{
		for (itMap = otherMap.begin(); itMap != otherMap.end(); ++itMap)
		{
			cout << itMap->first << " " << itMap->second << endl;
		}
	}

	cout << "Expected output:\n1 one\n2 two\n4 four\n5 five" << endl;
	
	/***************************************************************************
			SETS
	***************************************************************************/

	ostream_iterator<int> screen(cout, " ");

	cout << "\n\n----------------------------------------------------";
	cout << "\n  ***  STL LIST CLASS  ***  \n\n";

	// Use the default constructor to create a set mySet of integers.

	set<int> mySet;

	// Use function insert (void function ) to insert 12, 10, and 11 in this order.
	
	mySet.insert(12);
	mySet.insert(10);
	mySet.insert(11);

	// Use the default constructor to create a multiset myMultiset of integers.

	multiset<int> myMultiSet;
	
	// Use function insert (void function ) to insert 12, 11, 12, and 11 in this order.

	myMultiSet.insert(12);
	myMultiSet.insert(11);
	myMultiSet.insert(12);
	myMultiSet.insert(11);

	// Create an iterator and make it point to the first element in the set mySet.

	set<int>::iterator itSet;

	// Create an iterator and make it point to the first element in the multiset myMultiset.

	multiset<int>::iterator itMultiSet;

	cout << "\nSet: ";
	copy(mySet.begin(), mySet.end(), screen);
	cout << endl;
	cout << "\nMultiset: ";
	copy(myMultiSet.begin(), myMultiSet.end(), screen);
	cout << endl;
	
	cout << "\n(Other functions...)\n";
	/*
		!=
		==
		clear
		erase
		swap
	*/

	cout << "\nOther functions output:\n" << endl;

	// !=

	// Create another set of integers named otherSet containing 10, 11, 12
	
	set<int> otherSet = { 10, 11, 12 };
		
	// Use overloaded != to compare mySet and otherSet. Output the result.
	
	cout << ((mySet != otherSet) ? "Different." : "Same.") << endl;
	cout << "Expected output: Same." << endl;

	// ==

	// Create another set of integers named otherSet containing 10, 11, 12, 12

	multiset<int> otherMultiSet = { 10, 11, 12, 12 };

	// Use overloaded == to compare myMultiSet and otherMultiSet. Output the result.

	cout << ((myMultiSet == otherMultiSet) ? "Same." : "Different.") << endl;
	cout << "Expected output: Different." << endl;

	// clear
	// Remove all elements from otherSet

	otherSet.clear();

	// swap
	// Swap elements from myMultiSet and otherMultiSet

	myMultiSet.swap(otherMultiSet);

	// Print out all sets and multisets

	// Print out mySet
	if (mySet.empty())
		cout << "mySet is empty.";
	else
	{
		cout << "mySet: ";
		for (itSet = mySet.begin(); itSet != mySet.end(); ++itSet)
		{
			cout << *itSet << " ";
		}
	}
	cout << endl;
	
	cout << "Expected output: mySet: 10 11 12" << endl;

	// Print out otherSet
	if (otherSet.empty())
		cout << "otherSet is empty.";
	else
	{
		cout << "otherSet: ";
		for (itSet = otherSet.begin(); itSet != otherSet.end(); ++itSet)
		{
			cout << *itSet << " ";
		}
	}
	cout << endl;

	cout << "Expected output: otherSet is empty." << endl;

	// Print out myMultiSet
	if (myMultiSet.empty())
		cout << "myMultiSet is empty.";
	else
	{
		cout << "myMultiSet: ";
		for (itMultiSet = myMultiSet.begin(); itMultiSet != myMultiSet.end(); ++itMultiSet)
		{
			cout << *itMultiSet << " ";
		}
	}
	cout << endl;

	cout << "Expected output: myMultiSet: 10 11 12 12" << endl;

	// Print out otherMultiSet
	if (otherMultiSet.empty())
		cout << "otherMultiSet is empty.";
	else
	{
		cout << "otherMultiSet: ";
		for (itMultiSet = otherMultiSet.begin(); itMultiSet != otherMultiSet.end(); ++itMultiSet)
		{
			cout << *itMultiSet << " ";
		}
	}
	cout << endl;

	cout << "Expected output: otherMultiSet: 11 11 12 12" << endl;

	cout << "\n\n----------------------------------------------------";

	cout  <<  endl;
	system("Pause");
	return 0;
}
