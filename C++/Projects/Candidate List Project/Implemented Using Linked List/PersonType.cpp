#include "PersonType.h"

PersonType::PersonType()
{
	SSN = 0;
}

PersonType::PersonType(const string& newFirstName, const string& newLastName, int newSSN)
{
	firstName = newFirstName;
	lastName = newLastName;
	SSN = newSSN;
}

void PersonType::setPersonInfo(const string& newFirstName, const string& newLastName, int newSSN)
{
	firstName = newFirstName;
	lastName = newLastName;
	SSN = newSSN;
}

string PersonType::getFirstName() const
{
	return firstName;
}

string PersonType::getLastName() const
{
	return lastName;
}

void PersonType::printName() const
{
	cout << getLastName() << ", " << getFirstName();
}

void PersonType::printPersonInfo() const
{
	printSSN();
	cout << " " << getFirstName() << " " << getLastName() << endl;
}

void PersonType::printSSN() const
{
	int firstThreeDigits = SSN / 1000000;
	int midTwoDigits = (SSN / 10000) % 100;
	int lastFourDigits = SSN % 10000;

	cout << setfill('0') << setw(3) << firstThreeDigits << "-" << setw(2) 
		<< midTwoDigits << "-" << setw(4) << lastFourDigits;
}

int PersonType::getSSN() const
{
	return SSN;
}

PersonType::~PersonType()
{
}
