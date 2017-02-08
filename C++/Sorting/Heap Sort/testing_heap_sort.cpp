#include "DArray.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	cout << "****TESTING MIN-ORDER HEAPSORT****\n" << endl;
	DArray a1;
	int value;
	int num;

	for (int i = 0; i < 7; i++)
	{
		srand(static_cast<unsigned int>(time(0)));
		value = rand() % (a1.getNumOfElem() + 1 * 10);
		cout << "Insert " << value << ": ";
		a1.insertMin(value);
		a1.print();
		cout << endl;
	}

	cout << endl;

	num = a1.getNumOfElem();
	for (int i = 0; i < num; i++)
	{
		cout << "Delete " << a1.getFirst() << ": ";
		a1.removeMin();
		a1.print();
		cout << endl;
	}

	cout << endl;

	DArray a2(9);
	a2.setRoot(3);

	for (int i = 9; i >= a2.getRoot(); i--)
	{
		cout << "Insert " << i << ": ";
		a2.insertMin(i);
		a2.print();
		cout << endl;
	}

	cout << endl;

	num = a2.getNumOfElem();
	for (int i = 0; i < num; i++)
	{
		cout << "Delete " << a2.getFirst() << ": ";
		a2.removeMin();
		a2.print();
		cout << endl;
	}

	cout << endl;

	DArray a3;

	cout << "Insert 8: ";
	a3.insertMin(8);
	a3.print();
	cout << endl;
	cout << "Insert 3: ";
	a3.insertMin(3);
	a3.print();
	cout << endl;
	cout << "Insert 9: ";
	a3.insertMin(9);
	a3.print();
	cout << endl;
	cout << "Insert 15: ";
	a3.insertMin(15);
	a3.print();
	cout << endl;
	cout << "Insert 6: ";
	a3.insertMin(6);
	a3.print();
	cout << endl;
	cout << "Insert 4: ";
	a3.insertMin(4);
	a3.print();
	cout << endl;
	cout << "Insert 12: ";
	a3.insertMin(12);
	a3.print();
	cout << endl;
	cout << "Insert 5: ";
	a3.insertMin(5);
	a3.print();
	cout << endl;
	cout << "Insert 11: ";
	a3.insertMin(11);
	a3.print();
	cout << endl;

	cout << endl;

	a3.removeAllMin();

	cout << "\n\n********************************************************************\n\n" << endl;

	cout << "****TESTING MAX-ORDER HEAPSORT****\n" << endl;

	DArray a4;

	for (int i = 0; i < 7; i++)
	{
		srand(static_cast<unsigned int>(time(0)));
		value = rand() % (a4.getNumOfElem() + 1 * 10);
		cout << "Insert " << value << ": ";
		a4.insertMax(value);
		a4.print();
		cout << endl;
	}

	cout << endl;

	num = a4.getNumOfElem();
	for (int i = 0; i < num; i++)
	{
		cout << "Delete " << a4.getFirst() << ": ";
		a4.removeMax();
		a4.print();
		cout << endl;
	}

	cout << endl;

	DArray a5(9);
	a5.setRoot(3);

	for (int i = 9; i >= a5.getRoot(); i--)
	{
		cout << "Insert " << i << ": ";
		a5.insertMax(i);
		a5.print();
		cout << endl;
	}

	cout << endl;

	num = a5.getNumOfElem();
	for (int i = 0; i < num; i++)
	{
		cout << "Delete " << a5.getFirst() << ": ";
		a5.removeMax();
		a5.print();
		cout << endl;
	}

	cout << endl;

	DArray a6;

	cout << "Insert 8: ";
	a6.insertMax(8);
	a6.print();
	cout << endl;
	cout << "Insert 3: ";
	a6.insertMax(3);
	a6.print();
	cout << endl;
	cout << "Insert 9: ";
	a6.insertMax(9);
	a6.print();
	cout << endl;
	cout << "Insert 15: ";
	a6.insertMax(15);
	a6.print();
	cout << endl;
	cout << "Insert 6: ";
	a6.insertMax(6);
	a6.print();
	cout << endl;
	cout << "Insert 4: ";
	a6.insertMax(4);
	a6.print();
	cout << endl;
	cout << "Insert 12: ";
	a6.insertMax(12);
	a6.print();
	cout << endl;
	cout << "Insert 5: ";
	a6.insertMax(5);
	a6.print();
	cout << endl;
	cout << "Insert 11: ";
	a6.insertMax(11);
	a6.print();
	cout << endl;

	cout << endl;

	a6.removeAllMax();


	cout << endl;
	system("Pause");
	return 0;
}