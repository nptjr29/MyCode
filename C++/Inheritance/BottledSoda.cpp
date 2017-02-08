// BottledSoda.cpp file

#include "BottledSoda.h"

BottledSoda::BottledSoda()
{
	fluidOz = 0.0;
}

BottledSoda::BottledSoda(const string& newBrand, double newFluidOz) 
			: Soda(newBrand)
{
	fluidOz = newFluidOz;
}

double BottledSoda::getFluidOunces() const
{
	return fluidOz;
}

void BottledSoda::setFluidOunces(double newFluidOz)
{
	fluidOz = newFluidOz;
}

bool BottledSoda::compareFluidOunces(const BottledSoda& otherSoda) const
{
	return (fluidOz == otherSoda.fluidOz);
}

void BottledSoda::print() const
{
	//Soda::print();
	//cout << "    Fl. Oz. " << fixed << showpoint << setprecision(2) << fluidOz << endl;

	cout << "Brand:\n    " << getBrand() << endl;
	cout << "    Fl. Oz. " << fixed << showpoint << setprecision(2) << fluidOz << endl;
}

BottledSoda::~BottledSoda()
{

}