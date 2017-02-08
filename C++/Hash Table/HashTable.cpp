#include "HashTable.h"

ostream& operator<<(ostream& out, HashTable& table)
{
	if (table.numOfElements == 0)
	{
		out << "Table is empty." << endl;
	}
	else
	{
		for (int i = 0; i < CAPACITY; ++i)
		{
			out << table.operator[](i) << " ";
		}
		out << endl;
	}

	return out;
}

HashTable::HashTable()
{
	capacity = CAPACITY;
	numOfElements = 0;
	table = new int[capacity];

	for (int i = 0; i < capacity; ++i)
	{
		table[i] = -1;
	}
}

HashTable::HashTable(int newCapacity)
{
	capacity = newCapacity;
	numOfElements = 0;
	table = new int[capacity];

	for (int i = 0; i < capacity; ++i)
	{
		table[i] = -1;
		++numOfElements;
	}

}

HashTable::HashTable(const HashTable& otherTable)
{
	capacity = otherTable.capacity;
	numOfElements = otherTable.numOfElements;
	table = new int[capacity];
	for (int i = 0; i < capacity; ++i)
	{
		table[i] = otherTable.table[i];
	}

}

HashTable& HashTable::operator=(const HashTable& rightSide)
{
	if (&rightSide != this)
	{
		if (capacity != rightSide.capacity)
		{
			delete[] table;
			table = new int[rightSide.capacity];
			capacity = rightSide.capacity;
		}
		for (int i = 0; i < rightSide.numOfElements; ++i)
			table[i] = rightSide.table[i];
		numOfElements = rightSide.numOfElements;
	}
	else
	{
		cerr << "Attempted assignment to itself." << endl;
	}

	return *this;
}

int HashTable::operator[](int index) const
{
	return table[index];
}

void HashTable::insert(int key)
{
	bool done = false;
	int index = hashValue(key);

	if (table[index] == -1)
	{
		table[index] = key;
		++numOfElements;
	}
	else
	{
		while ((table[index] != -1) && (!done))
		{
			++index;

			//wrap around
			if (index > (capacity - 1))
				index = 0;

			//finish one round
			if (index == hashValue(key))
			{
				cerr << "Hash Table is full." << endl;
				done = true;
			}

		}

		//insert item
		if (table[index] == -1)
		{
			table[index] = key;
			++numOfElements;
		}		

	}
}

bool HashTable::search(int key) const
{
	bool found = false;
	bool flag = false;

	int index = hashValue(key);

	if (table[index] == key)
	{
		found = true;
	}		
	else
	{
		while ((!found) && (!flag))
		{
			++index;

			if (table[index] == key)
			{
				found = true;
			}
			//Item not in the table
			else if (index == hashValue(key) || table[index] == -1)
			{
				flag = true;
			}

			//wrap around
			if (index > (capacity - 1) && table[index] != hashValue(key))
			{
				index = 0;
				//Item is at the first index
				if (table[index] == key)
				{
					found = true;
				}
			}

		}
	}

	return found;
}

int HashTable::getCapacity() const
{
	return capacity;
}

HashTable::~HashTable()
{
	numOfElements = 0;
	delete[] table;
	table = NULL;
}

int HashTable::hashValue(int key) const
{
	return (key % capacity);
}