/*
	Thao Nguyen
	CWID: 890848781

	Implementation for Part class
	February 1st, 2016
*/

#include "Part.h"

//Default Part constructor
Part::Part()
{
	ID = 0;
	setDescription("");
	price = 0.0;
} //end default Part constructor

//Overloaded Part constructor
Part::Part(int newID, const string newDescription, double newPrice)
{
	ID = newID;
	setDescription(newDescription);
	price = newPrice;
}//end overloaded Part constructor

//Mutator function for ID
void Part::setID(int newID)
{
	ID = newID;
}//end mutator function for ID

//Mutator function for description
void Part::setDescription(const string newDescription)
{
	int length = newDescription.size();
	length = (length < 20 ? length : 19);
	newDescription.copy(description, length);
	description[length] = '\0';
}//end mutator function for description

//Mutator function for price
void Part::setPrice(double newPrice)
{
	price = newPrice;
}//end mutator function for price

//Accessor function for ID
int Part::getID() const
{
	return ID;
}//end accessor function for ID

//Accessor function for description
string Part::getDesciption() const
{
	return description;
}//end accessor function for description

////Accessor function for price
double Part::getPrice() const
{
	return price;
}//end accessor function for price

//Part destructor
Part::~Part()
{

}//end Part destructor