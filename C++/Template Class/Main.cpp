//This program creates partially-filled arrays
//  of integers.

#include "DArray.h"
#include "DArray.cpp"
#include "Student.h"

#include <iostream>
#include <string>
using namespace std;

int main( )
{
	//Ask the user to enter the capacity
	cout << "Enter the capacity of the array: ";
	int cap1;
	cin >> cap1;

	//Create the new array
	DArray<int> a1(cap1);

	//Ask the user to enter values for the array
	cout << "\nEnter positive numbers "
		<< "(enter -1 to quit)" << endl;
	int n1;
	cin >> n1;
	while(n1 != -1)
	{
		a1.addElement(n1);
		cin >> n1;
	}

	//Print out the array of intergers
	cout << "Array of intergers: "; 
	a1.printArray();
	
	//Ask the user to enter the capacity
	cout << "\nEnter the capacity of the array: ";
	int cap2;
	cin >> cap2;

	//Create the new array
	DArray<double> a2(cap2);

	//Ask the user to enter values for the array
	cout << "\nEnter positive decimal numbers "
		<< "(enter -1 to quit)" << endl;
	double n2;
	cin >> n2;
	while (n2 != -1.0)
	{
		a2.addElement(n2);
		cin >> n2;
	}

	//Print out the array of intergers
	cout << "Array of doubles: ";
	a2.printArray();

	//Ask the user to enter the capacity
	cout << "\nEnter the capacity of the array: ";
	int cap3;
	cin >> cap3;

	//Create the new array
	DArray<string> a3(cap3);

	//Ask the user to enter values for the array
	cout << "\nEnter words "
		<< "(enter -1 to quit)" << endl;
	string n3;
	cin >> n3;
	while (n3 != "-1")
	{
		a3.addElement(n3);
		cin >> n3;
	}

	//Print out the array of intergers
	cout << "Array of strings: ";
	a3.printArray();
	
	//Object student
	//Ask the user to enter the capacity
	cout << "\nEnter the capacity of the array: ";
	int cap4;
	cin >> cap4;

	DArray<Student> a4(cap4);
	int userID = 0;
	string userMajor;
	string ans = "y";
	int count = 0;

	while (ans == "y")
	{
		cout << "\nEnter student id and major: " << endl;
		cin >> userID >> userMajor;
		Student newStudent(userID, userMajor);
		a4.addElement(newStudent);
		++count;
		if (count < cap4)
		{
			cout << "\nContinue adding students? (y/n)" << endl;
			cin >> ans;
		}
		else
		{
			cout << "Array's capacity reached." << endl;
			ans = "n";
		}
	}
	
	//Print out the array of objects

	int usedStudent = a4.getNumberUsed();
	cout << "\nArray of objects: " << endl;

	for (int i = 0; i < usedStudent; ++i)
	{
		a4.getElementAt(i).print();
	}
	
	cout << endl;
	system("Pause");
    return 0;
}

