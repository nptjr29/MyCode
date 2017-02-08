#include "Student.h"

using namespace std;

Student::Student()
{
	id = 0;
}

Student::Student(int newID, const string& newMajor)
{
	id = newID;
	major = newMajor;
}

int Student::getID() const
{
	return id;
}

string Student::getMajor() const
{
	return major;
}

void Student::setID(int newID)
{
	id = newID;
}

void Student::setMajor(const string& newMajor)
{
	major = newMajor;
}

void Student::print() const
{
	cout << id << " " << major << endl;
}

Student::~Student()
{

}