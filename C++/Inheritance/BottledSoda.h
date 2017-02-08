// BottledSoda.h file

#ifndef BOTTLEDSODA_H
#define BOTTLEDSODA_H

#include "Soda.h"

class BottledSoda : public Soda
{
public:
	BottledSoda();
	BottledSoda(const string& newBrand, double newFluidOz);
	double getFluidOunces() const;
	void setFluidOunces(double newFluidOz);
	bool compareFluidOunces(const BottledSoda& otherSoda) const;
	void print() const;
	~BottledSoda();
private:
	double fluidOz;
};

#endif