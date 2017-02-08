/*
	Nguyen, Thao
	CS A200
	February 2, 2015

	Exercise 1
*/

//Soda.h file

#ifndef SODA_H
#define SODA_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Soda
{
public:
	Soda();
	Soda(const string& newBrand);
	string getBrand() const;
	void setBrand(const string& newBrand);
	void print() const;
	~Soda();
private:
	string sodaBrand;
};

#endif