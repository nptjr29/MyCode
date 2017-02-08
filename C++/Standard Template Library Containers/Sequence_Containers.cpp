/*  
	Nguyen, Thao
	CS A250
	November 6, 2014

	Exercise 11
*/
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;

// Declaration function printVector.
// The function passes a vector and prints all
// the elements on one line, separated by a space.
// Use an iterator and a FOR loop.
void printVector(const vector<int>& v);

// Declaration function printList.
// The function passes a list and prints all
// the elements on one line, separated by a space.
// Use an iterator and a FOR loop.
void printList(const list<int>& l);


// Declaration function printDeque.
// The function passes a deque and prints all
// the elements on one line, separated by a space.
// Use an iterator and a FOR loop.
void printDeque(const deque<int>& dq);

int main()
{

	/***************************************************************************
			VECTORS
	***************************************************************************/
	cout << "  ***  STL VECTOR CLASS  ***  \n\n";

	// Use the default constructor to declare an integer vector v1.

	vector<int> v1;

	// Use function push_back to insert the following values in v1: 12, 73, 41,
	// 38, 25, 56, an 63 in this order.

	v1.push_back(12);
	v1.push_back(73);
	v1.push_back(41);
	v1.push_back(38);
	v1.push_back(25);
	v1.push_back(56);
	v1.push_back(63);

	// Create a variable of type int named sizeV1 and store the size of the vector.
	// Use function size to retrieve the size of the vector. 
	// Make sure you cast the return value of the function size to the appropriate type.

	int sizeV1 = static_cast<int>(v1.size());

	// Use a FOR loop to print out the vector.
	// Do NOT use an iterator.

	for (int i = 0; i < sizeV1; ++i)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	// Call the function clear on vector v1.

	v1.clear();

	// Call function size to print the size of v1.

	cout << v1.size() << endl;

	// Call function capacity to output the capacity of v1.

	cout << v1.capacity() << endl;

	// Create an array of integers containing: 10,11,12,13,14,15,16,17,18,19

	int a[] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

	// Use the default constructor to declare an integer vector v2.

	vector<int> v2;

	// Use function assign to copy elements 12, 13, 14, 15, and 16 in v2.
	// One statement only.

	v2.assign(a + 2, a + 7);

	// Call the function printVector to print v2.

	printVector(v2);

	// Use the function back output the last element in the vector

	cout << v2.back() << endl;

	// Use the default constructor to declare an integer vector v3.
	vector<int> v3;

	// Use function assign to insert the values 7, 7, 7, 7, and 7.
	// One statement only.

	v3.assign(5, 7);

	// Call the function printVector  to print v3.

	printVector(v3);

	// Use function at to replace the middle element with 100.

	v3.at(2) = 100;

	// Call the function printVector to print v3.

	printVector(v3);

	// Use the copy constructor to create a new vector v4 with the 
	// same elements of v3.

	vector<int> v4(v3);

	// Call the function printVector to print v4.

	printVector(v4);

	// Create an iterator iterVector4 to point to the first element of v4.

	vector<int>::iterator iterVector4 = v4.begin();

	// Create an iterator iterVector2 to point to the second element of v2.

	vector<int>::iterator iterVector2 = v2.begin() + 1;

	// Use function insert to insert the second, third, and fourth element
	// of v2 as the first, second, and third element of v4.

	v4.insert(v4.begin(), v2[1]);
	v4.insert((v4.begin() + 1), v2[2]);
	v4.insert((v4.begin() + 2), v2[3]);
	
	//why doesn't this work?
	//v4.insert(iterVector4, *iterVector2);
	//v4.insert(iterVector4 + 1, *(iterVector2 + 1));  
	//v4.insert(iterVector4 + 1, *(iterVector2 + 2));  

	// Call the function printVector to print v4.
	
	printVector(v4);

	// Use the function insert to insert three 0s at the end of v4.

	v4.insert(v4.end(), 3, 0);

	// Call the function printVector to print v4.

	printVector(v4);

	// Use a WHILE loop to remove and output each element of v2 backwards.
	// Use function empty for the loop condition, function back to output 
	// the last element, and function pop_back to remove elements.

	while (!v2.empty())
	{
		cout << v2.back() << " ";
		v2.pop_back();
	}
	cout << endl;

	// Use function resize to insert three times number 4 in v2.

	v2.resize(3, 4);

	// Call the function printVector to print v2.

	printVector(v2);

	// Use function front to output the first element in v4.

	cout << v4.front() << endl;

	// Use function swap to swap v2 with v4.

	v2.swap(v4);

	// Call the function printVector to print v2.

	printVector(v2);

	// Create a new vector v5;

	vector<int> v5;

	// Use the assignment operator to copy all the elements of v2
	// into v5.

	v5 = v2;

	// Call the function printVector to print v5.

	printVector(v5);

	/*
		Keep on practicing with these functions:
			overloaded comparison operator !=
			overloaded comparison operator ==
			erase(begin, end)
			erase(iter)
			resize(n)
			resize(n, elem)
	*/
			
	cout << "\nExtra practice output: " << endl;

	// overloaded comparison operator ==
	// Use the overloaded comparison operator != and an IF statement to
	// compare v3 and v4, and output "Same" or "Different"

	if (v3 != v4)
		cout << "Different" << endl;
	else
		cout << "Same" << endl;

	cout << "Expected output: Different" << endl;

	// overloaded comparison operator ==
	// Use the overloaded comparison operator == and an IF statement to
	// compare v2 and v5, and output "Same" or "Different"

	if (v2 == v5)
		cout << "Same" << endl;
	else
		cout << "Different" << endl;

	cout << "Expected output: Same" << endl;

	// erase(begin, end)
	// Erase the first 3 elements from v2

	v2.erase(v2.begin(), v2.begin() + 3);

	// erase(iter)
	// Erase the 4th element from v3

	v3.erase(v3.begin() + 3);

	// Print v2
	
	printVector(v2);

	cout << "Expected output: 7 7 100 7 7 0 0 0" << endl;

	// Print v3

	printVector(v3);

	cout << "Expected output: 7 7 100 7" << endl;

	// resize(n)
	// Use resize function to remove the last 3 elements from v5

	v5.resize(v5.size() - 3);

	// resize(n, elem)
	// Use resize function to add 3 fives at the end of v4

	v4.resize(v4.size() + 3, 5);

	// Print v5

	printVector(v5);

	cout << "Expected output: 13 14 15 7 7 100 7 7" << endl;

	// Print v4

	printVector(v4);

	cout << "Expected output: 4 4 4 5 5 5" << endl;


	/***************************************************************************
			LISTS
	***************************************************************************/

	cout << "\n\n----------------------------------------------------";
	cout << "\n  ***  STL LIST CLASS  ***  \n\n\n";

	// Use the default constructor to create three lists of integers, intLis1,
	// intList2, and intList3.

	list<int> intList1;
	list<int> intList2;
	list<int> intList3;

	// Use the function push_back to insert the following values in the first list: 
	// 23 58 58 58 36 15 93 98 58

	intList1.push_back(23);
	intList1.push_back(58);
	intList1.push_back(58);
	intList1.push_back(58);
	intList1.push_back(36);
	intList1.push_back(15);
	intList1.push_back(15);
	intList1.push_back(93);
	intList1.push_back(98);
	intList1.push_back(58);

	// Call function printList to print intList1.

	printList(intList1);

	//Using the assignment operator, copy elements of intList1 and intList2.

	intList2 = intList1;

	// Call function printList to print intList1.

	printList(intList1);

	//Remove all consecutive duplicates in the first list (browse the list of 
	//  functions in cplusplus.com to figure out which function you need to use).
	// --> This is only ONE statement.

	intList1.unique();

	// Call function printList to print intList1.

	printList(intList1);

	//Sort all elements in the second list (browse the list of 
	//  functions in cplusplus.com to figure out which function you 
	//  need to use).
	// --> This is ONE statement only.

	intList2.sort();

	// Call function printList to print intList2.

	printList(intList2);

	//Insert the following elements in the third list:
	//  13 23 25 136 198

	intList3.push_back(13);
	intList3.push_back(23);
	intList3.push_back(25);
	intList3.push_back(136);
	intList3.push_back(198);

	// Call function printList to print intList3.

	printList(intList3);

	//Add to the second list all elements of the third list(browse the  
	//  list of functions in cplusplus.com to figure out which function  
	//  you need to use).
	// --> This is ONE statement only.

	intList2.merge(intList3);

	// Call function printList to print intList2.

	printList(intList2);

	// Use the overloaded comparison operator == and an IF statement to
	// compare list1 and list2, and output "Same" or "Different"

	if (intList1 == intList2)
		cout << "Same" << endl;
	else
		cout << "Different" << endl;

	cout << "\n(Other functions...)\n";
	/*
		Keep on practicing with these functions:
			assign(begin, end)
			assign(n, elem)
			back()
			clear()
			empty()
			front()
			insert(iter, elem)
			pop_back(elem)
			pop_front
			push_front()
			remove(elem)
			reverse()
			splice(iter, list2)
			splice(iter1, lis2, begin, end)
			splice(iter1, list2, iter2)
			swap(ct2)
	*/

	cout << "\nExtra practice output: " << endl;

	// assign(begin, end)
	// Use function assign to copy elements from List1 to List3.

	intList3.assign(intList1.begin(), intList1.end());

	// Print List3
	
	printList(intList3);

	cout << "Expected output: 23 58 36 15 93 98 58" << endl;
	
	// assign(n, elem)
	// Replace all the elements in List3 with five 100's

	intList3.assign(5, 100);

	// Print List3

	printList(intList3);

	cout << "Expected output: 100 100 100 100 100" << endl;

	// back()

	// Output the last element of each list on the same line

	cout << intList1.back() << " " << intList2.back() << " " << intList3.back() << endl;

	cout << "Expected output: 58 198 100" << endl;

	// clear()
	// Remove all elements from List2

	intList2.clear();

	// Print List2

	printList(intList2);

	cout << "Expected output: List is empty." << endl;

	// empty()
	// Check if each list is empty or not. 

	cout << ((intList1.empty()) ? "List 1 is empty." : "List 1 is not empty.") << endl;
	cout << "Expected output: List 1 is not empty." << endl;
	cout << ((intList2.empty()) ? "List 2 is empty." : "List 2 is not empty.") << endl;
	cout << "Expected output: List 2 is empty." << endl;
	cout << ((intList3.empty()) ? "List 3 is empty." : "List 3 is not empty.") << endl;
	cout << "Expected output: List 3 is not empty." << endl;

	// front()
	// Output the first element of the non-empty lists

	cout << intList1.front() << " " << intList3.front() << endl;
	cout << "Expected output: 23 100" << endl;
	
	// insert(iter, elem)
	// Using iterator, insert 2 as the second element of List3

	list<int>::iterator iterList3 = intList3.begin();
	++iterList3;
	intList3.insert(iterList3, 2);

	// Print List3

	printList(intList3);

	cout << "Expected output: 100 2 100 100 100 100" << endl;
	
	// pop_back(elem)
	// Remove the last element of each list. 
	// If the list is empty, output: "Cannot remove because list __ is empty."

	if (intList1.empty())
		cout << "Cannot remove because list 1 is empty." << endl;
	else
		intList1.pop_back();

	if (intList2.empty())
		cout << "Cannot remove because list 2 is empty." << endl;
	else
		intList2.pop_back();

	if (intList3.empty())
		cout << "Cannot remove because list 3 is empty." << endl;
	else
		intList3.pop_back();

	cout << "Expected output: Cannot remove because list 2 is empty." << endl;

	//pop_front
	// Remove the first element of each list. 
	// If the list is empty, output: "Cannot remove because list __ is empty."

	if (intList1.empty())
		cout << "Cannot remove because list 1 is empty." << endl;
	else
		intList1.pop_front();

	if (intList2.empty())
		cout << "Cannot remove because list 2 is empty." << endl;
	else
		intList2.pop_front();

	if (intList3.empty())
		cout << "Cannot remove because list 3 is empty." << endl;
	else
		intList3.pop_front();

	cout << "Expected output: Cannot remove because list 2 is empty." << endl;

	// push_front()
	// Insert a 999 in front of each list

	intList1.push_front(999);
	intList2.push_front(999);
	intList3.push_front(999);

	// Print out all lists

	printList(intList1);
	cout << "Expected output: 999 58 36 15 93 98" << endl;

	printList(intList2);
	cout << "Expected output: 999" << endl;

	printList(intList3);
	cout << "Expected output: 999 2 100 100 100" << endl;

	// remove(elem)
	// Remove all elements that have the value of 100 from List3

	intList3.remove(100);

	// reverse()
	// Reverse the order of the elements in List1 and List2

	intList1.reverse();
	intList3.reverse();

	// Print out List1 and List3

	printList(intList1);
	cout << "Expected output: 98 93 15 36 58 999" << endl;

	printList(intList3);
	cout << "Expected output: 2 999" << endl;

	// splice(iter, list2)
	// Transfer all elements of List1 to the end of List3

	list<int>::const_iterator constIterList3 = intList3.end();
	intList3.splice(constIterList3, intList1);

	// Print out both List1 and List3
	
	printList(intList1);
	cout << "Expected output: List is empty." << endl;

	printList(intList3);
	cout << "Expected output: 2 999 98 93 15 36 58 999" << endl;
	
	//splice(iter1, list2, begin, end)
	// Transfer all elements in between, but not inclusive, the first and next 999 of List3 to List1

	list<int>::const_iterator constIterList1 = intList1.begin();
	list<int>::const_iterator constIterList32;

	constIterList3 = intList3.begin();

	while (*constIterList3 != 999)
		++constIterList3;
	constIterList32 = constIterList3;
	++constIterList32;

	while (*constIterList32 != 999)
		++constIterList32;

	++constIterList3;
	intList1.splice(constIterList1, intList3, constIterList3, constIterList32);

	// Print out both List1 and List3

	printList(intList1);
	cout << "Expected output: 98 93 15 36 58" << endl;

	printList(intList3);
	cout << "Expected output: 2 999 999" << endl;

	// splice(iter1, list2, iter2)
	// Transfer all elements of value 999 from List3 to List2

	list<int>::const_iterator constIterList2 = intList2.begin();

	constIterList3 = intList3.begin();

	while (constIterList3 != intList3.end())
	{
		if (*constIterList3 == 999)
		{
			intList2.splice(constIterList2, intList3, constIterList3);
			constIterList3 = intList3.begin();
		}
		++constIterList3;
	}
	
	// Print both List2 and List3

	printList(intList2);
	cout << "Expected output: 999 999 999" << endl;

	printList(intList3);
	cout << "Expected output: 2" << endl;

	// swap(ct2)
	// Swap List1 and List3

	intList1.swap(intList3);

	// Print all lists

	printList(intList1);
	cout << "Expected output: 2" << endl;
	printList(intList2);
	cout << "Expected output: 999 999 999" << endl;
	printList(intList3);
	cout << "Expected output: 98 93 15 36 58" << endl;


	/***************************************************************************
			DEQUE
	***************************************************************************/

	cout << "\n\n----------------------------------------------------";
	cout << "\n  ***  STL DEQUE CLASS  ***  \n\n\n";

	// Declare a deque dq of integers using the default constructor.

	deque<int> dq;

	// Use function push_back to insert the following values into dq: 13 75 28 35

	dq.push_back(13);
	dq.push_back(75);
	dq.push_back(28);
	dq.push_back(35);

	// Call function printDeque to print dq.

	printDeque(dq);

	// Use function push_front to insert the value 0 to the front of dq.

	dq.push_front(0);

	// Call function printDeque to print dq.

	printDeque(dq);

	// Use function pop_front to remove the first two elements of dq.

	dq.pop_front();
	dq.pop_front();

	// Call function printDeque to print dq.

	printDeque(dq);

	// Use function pop_back to remove the last two elements of the deque.

	dq.pop_back();
	dq.pop_back();

	// Call function printDeque to print dq.

	printDeque(dq);

	// Create an iterator iterDeque to point to the front item of dq.

	deque<int>::iterator iterDeque = dq.begin();

	// Using the iterator and the function insert,
	//  insert the value 444 to be the second element of the deque.			

	dq.insert((dq.begin() + 1), 444);

	// Call function printDeque to print dq.

	printDeque(dq);

	cout << "\n\n----------------------------------------------------";

	cout  <<  endl;
	system("Pause");
	return 0;
}

// Definition function printVector
// The function passes a vector and prints all
// the elements on one line, separated by a space.
// Use an iterator and a FOR loop.
void printVector(const vector<int>& v)
{ 
	if (v.empty())
	{
		cout << "Vector is empty.";
	}
	else
	{
		vector<int>::const_iterator itVector;

		for (itVector = v.begin(); itVector != v.end(); ++itVector)
		{
			cout << *itVector << " ";
		}
	}
	cout << endl;
}


// Definition function printList
// The function passes a list and prints all
// the elements on one line, separated by a space.
// Use an iterator and a FOR loop.
void printList(const list<int>& l)
{
	if (l.empty())
	{
		cout << "List is empty.";
	}
	else
	{
		list<int>::const_iterator itList;

		for (itList = l.begin(); itList != l.end(); ++itList)
		{
			cout << *itList << " ";
		}
	}
	cout << endl;
}


// Definition function printDeque
// The function passes a deque and prints all
// the elements on one line, separated by a space.
// Use an iterator and a FOR loop.
void printDeque(const deque<int>& dq)
{
	if (dq.empty())
	{
		cout << "Deque is empty.";
	}
	else
	{
		deque<int>::const_iterator itDeque;

		for (itDeque = dq.begin(); itDeque != dq.end(); ++itDeque)
		{
			cout << *itDeque << " ";
		}
	}
	cout << endl;
}


