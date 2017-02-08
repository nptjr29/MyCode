// Soda.cpp file

#include "Soda.h"

Soda::Soda()
{
	// no need to initialize string
}

Soda::Soda(const string& newBrand)
{
	sodaBrand = newBrand;
}

string Soda::getBrand() const
{
	return sodaBrand;
}

void Soda::setBrand(const string& newBrand)
{
	sodaBrand = newBrand;
}

void Soda::print() const
{
	cout << "Brand:\n    " << sodaBrand << endl;
}

Soda::~Soda()
{

}