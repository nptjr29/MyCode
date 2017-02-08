#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
using namespace std;

const int CAPACITY = 11;

class HashTable
{
	friend ostream& operator<<(ostream& out, HashTable& table);
public:
	HashTable();
	HashTable(int newCapacity);
	HashTable(const HashTable& otherTable);
	HashTable& operator=(const HashTable& rightSide);
	int operator[](int index) const;
	void insert(int key);
	bool search(int key) const;
	int getCapacity() const;
	~HashTable();

private:
	int hashValue(int key) const;

	int *table;				//pointer to the hash table
    int numOfElements;		//number of items in the hash table
    int capacity;			//maximum length of the hash table	
};

#endif
