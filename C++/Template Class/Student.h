/*
	Nguyen, Thao
	CS A150
	October 14, 2014

	Exercise 10
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "DArray.h"
using namespace std;

class Student
{
public:
	Student();
	Student(int newID, const string& newMajor);

	int getID() const;
	string getMajor() const;

	void setID(int newID);
	void setMajor(const string& newMajor);

	void print() const;
	~Student();
	
private:
	int id;
	string major;
};

#endif