/*
	Nguyen, Thao
	CS A200
	February 2, 2015

	Exercise 1
*/

#include "Soda.h"
#include "BottledSoda.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int recursive(int a, int b);
int main()
{
	int result = 0;
	result = recursive(5861, 7);
	cout << result;
	/*cout << fixed << showpoint << setprecision(2);

	Soda coke;
	coke.setBrand("Coca Cola");
	coke.print();
	cout << endl;

	Soda pepsi("Pepsi");
	cout << "Brand:\n    " << pepsi.getBrand() << endl;
	cout << endl;

	BottledSoda sevenUp("Seven Up", 20.0);
	cout << "Brand:\n    " << sevenUp.getBrand() << endl;
	cout << "    Fl. Oz. " << sevenUp.getFluidOunces() << endl;
	cout << endl;

	BottledSoda sprite;
	sprite.setBrand("Sprite");
	sprite.setFluidOunces(67.6);
	sprite.print();
	cout << endl;

	BottledSoda fanta;
	fanta.setBrand("Fanta");
	fanta.setFluidOunces(67.6);
	fanta.print();
	cout << endl;

	cout << "Brand: " << sprite.getBrand() << endl;
	cout << "Brand: " << fanta.getBrand() << endl;
	if (sprite.compareFluidOunces(fanta))
		cout << "    Same bottle size." << endl;
	else
		cout << "    Different bottle size." << endl;
	cout << endl;

	cout << "Brand: " << sevenUp.getBrand() << endl;
	cout << "Brand: " << sprite.getBrand() << endl;
	if (sevenUp.compareFluidOunces(sprite))
		cout << "    Same bottle size." << endl;
	else
		cout << "    Different bottle size." << endl;
	cout << endl;
*/
	cout << endl;
	system("Pause");
	return 0;
}

int recursive(int a, int b)
{
	//int result = 0;
	if (a < b)
		return 0;
	else
		return (recursive(a - b, b) + 1);

	

}