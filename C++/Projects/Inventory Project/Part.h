/*
	Thao Nguyen
	CWID: 890848781

	Class Part definition
	February 1st, 2016
*/

#include <string>
using namespace std;

#ifndef PART_H
#define PART_H

class Part
{
public:
	//Default Part constructor
	Part();

	//Overloaded Part constructor
	Part(int newID, const string newDescription, double newPrice);

	//Mutator function for ID
	void setID(int newID);

	//Mutator function for description
	void setDescription(const string newDescription);

	//Mutator function for price
	void setPrice(double newPrice);

	//Accessor function for ID
	int getID() const;

	//Assessor function for description
	string getDesciption() const;

	//Assessor function for price
	double getPrice() const;

	//Destructor
	~Part();

private:
	int ID;
	char description[20];
	double price;
	//need to include count for the warehouse
}; //end class Part





#endif
