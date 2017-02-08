/*
	Thao Nguyen
	CWID: 890848781

	February 1st, 2016
*/

//Interactive program for processing inventory information for a parts warehouse
#include "Part.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//Declaration of function displayMenu
void displayMenu();
	//displayMenu - Displays main menu with 4 choices to the user

//Declaration of function is_empty
bool isEmpty(ifstream& pFile);
	//isEmpty - Checks whether a file is empty
	//@param ifstream& - The input text file
	//@return bool - return true if file is empty, false if it isn't

//Declaration of function newPart
void newPart(vector<Part>& partList);
	//newPart - Asks user for info of the new part
	//		  - and then add that part into the list
	//@param vector<Part>& - the list of parts

//Declaration of function findPart
void findPart(vector<Part>& partList);
	//partList - Asks user for a part's ID
	//		   - and then search for the part from the list
	//@param vector<Part>& - the list of parts

//Declaration of function archiveBinary
void archiveBinary(const vector<Part>& partList);
	//archiveBinary - Copies all data into a binary file
	//@param const vector<Part>& - the list of parts

//Declaration of function quitProgram
void quitProgram(const vector<Part>& partList);
	//quitProgram - Copies all data into a text file
	//@param const vector<Part>& - the list of parts

//main program
int main()
{
	//Create variables to store info of each new part
	int ID = 0;
	string description;
	double price;

	//Create a list to store the parts, implemented with vector
	vector<Part> partList;

	//Read in from a file textSave.txt used for storing info between sessions
	ifstream infile;
	infile.open("textSave.txt");

	//Consider when the file does not exist
	if (!infile)
	{
		//Output error message
		cerr << "Input file does not exist.";
		//Exit the program
		exit(1);
	}
	//Consider when the file is empty
	else if (isEmpty(infile))
	{
		cerr << "Text file is empty." << endl;
	}
	else
	{
		//Read a part's ID from the text file
		infile >> ID;
		//Repeat until the end of the file
		while (!infile.eof())
		{
			//Create a new part object
			Part newPart;
			//Read a part's description from the text file
			infile >> description;
			//Read a part's price from the text file
			infile >> price;

			//Input the part's info using the info collected from the text file
			newPart.setDescription(description);
			newPart.setPrice(price);
			//Add that new part to the list of parts
			partList.push_back(newPart);

			//Read the next part's ID from the text file
			infile >> ID;
		}
	}
	infile.close();
	
	//Output main menu with 4 choices
	cout << "Main menu - ";
	displayMenu();

	char choice;
	cin >> choice;

	//Processing user's choice
	while (choice != 'Q')
	{
		switch (choice)
		{
		case 'N':
			newPart(partList);
			break;
		case 'F':
			findPart(partList);
			break;
		case 'A':
			archiveBinary(partList);
			break;
		default:
			//Invalid command
			cerr << "Invalid command" << endl;
		}
		
		displayMenu();
		cin >> choice;
	}
	
	if (choice == 'Q')
	{
		quitProgram(partList);
	}


	cout << endl;
	system("Pause");
	return 0;
}

//Definition of function displayMenu
void displayMenu()
{
	cout << "Please enter one of the following letters corresponding to the 4 choices below:" << endl;
	cout << "N - Enter a new part for the system." << endl;
	cout << "F - Find and print data for a part." << endl;
	cout << "A - Archiving the information." << endl;
	cout << "Q - Quit." << endl;
	cout << "Enter your choice: ";
}

//Definition of function is_empty
bool isEmpty(ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

//Definition of function newPart
void newPart(vector<Part>& partList)
{
	int ID;
	string description;
	double price;
	//Ask the user to enter the part ID and the rest of the part information.
	cout << "Please enter the part's ID: ";
	cin >> ID;
	cout << "Please enter the part's description: ";
	cin >> description;
	cout << "Please enter the part's price: ";
	cin >> price;

	//Enter the new part information into the system.
	//Create a new part object
	Part newPart(ID, description, price);
	//Insert that part into the list
	partList.push_back(newPart);
}

//Definition of function findPart
void findPart(vector<Part>& partList)
{
	//Ask for a part ID number, and search the system for a part with that ID
	cout << "Please enter the part's ID: ";
	int searchID;
	cin >> searchID;
	bool found = false;

	vector<Part>::const_iterator current = partList.begin();
	while (!found && current != partList.end())
	{
		if (current->getID() == searchID)
			found = true;
		else
			current++;
	}

	//If it is found, display the ID and all other information about the part to the screen
	if (found)
	{
		cout << "Part's ID: " << current->getID() << ", description: " << current->getDesciption() << ", price: $" << current->getPrice() << endl;
	}
	//If it is not found, print a message to the screen, telling the user that it could not be found
	else
	{
		cerr << "The part's ID you entered did not exist." << endl;
	}
	cout << endl;
}

//Definition of function archiveBinary
void archiveBinary(const vector<Part>& partList)
{
	//Everything is output to a binary file called binarySave.dat
	//Any previous file of that name will be overwritten
	ofstream outBinFile("binarySave.dat", ios::out | ios::binary);
	//Output error message if cannot create file
	if (!outBinFile)
	{
		cerr << "Could not create binarySave.dat." << endl;
	}
	vector<Part>::const_iterator current = partList.begin();
	while (current != partList.end())
	{
		outBinFile << current->getID() << " " << current->getDesciption() << " " << current->getPrice() << endl;
		++current;
	}
	cout << endl;
}

//Definition of function quitProgram
void quitProgram(const vector<Part>& partList)
{
	//Write all the current parts information into the text file textSave.txt, overwriting any previous data before quitting.
	ofstream outFile;
	outFile.open("textSave.txt", ios::out);
	if (!outFile)
	{
		cerr << "Could not open textSave.txt" << endl;
	}
	vector<Part>::const_iterator current = partList.begin();
	while (current != partList.end())
	{
		outFile << current->getID() << " " << current->getDesciption() << " " << current->getPrice() << endl;
		++current;
	}
	outFile.close();
}