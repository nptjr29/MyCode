/*
	Nguyen, Thao
	CS A250
	Sep 9, 2014

	Project 1
*/

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class PersonType
{
public:
	PersonType();
	PersonType(const string& newFirstName, const string& newLastName, int newSSN);
	void setPersonInfo(const string& newFirstName, const string& newLastName, int newSSN);
	string getFirstName() const;
	string getLastName() const;
	void printName() const;
	void printPersonInfo() const;
	void printSSN() const;
	int getSSN() const;
	~PersonType();
private:
	string firstName;
	string lastName;
	int SSN;
};

#endif