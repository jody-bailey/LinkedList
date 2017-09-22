/*************************************************************************************************
Jody Bailey
CSC 307 - Data Structures
09/13/2017
This program will prompt the user to enter any number of integers seperated by spaces and then
when they are done to enter -999. Then the program will take those integers and store them into
a linked list in ascending order. It will then display the ordered linked list. Once the program
ends and the object of the class intList goes out of scope, the destructor will get called which
will call the function deleteList() which will traverse the linked list and deallocate the memory
for each node and delete the pointer to them.
*************************************************************************************************/
#include "intList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "linkedList.exe <fileName> <fileName>" << endl;
		cin.get();
		return(1);
	}
	// Create an object of the class intList
	intList myList;
	string first = "";
	string last = "";
	int age = 0;

	ifstream input(argv[1], ios::in);

	if (!input)
	{
		cout << "Could not open the input file!" << endl;
		cin.get();
		return(2);
	}

	
	

	// Perform a while loop to capture all of the integers entered by the user
	while (!input.eof())
	{
		string line = "";
		getline(input, line);

		if (line == "")
		{
			continue;
		}

		last = line.substr(0, line.find_first_of(" "));
		first = line.substr(line.find_first_of(" "));
		age = stoi(first.substr(first.find_last_of(" ")));
		first = first.substr(1, first.find_last_of(" "));

		// Call the appendNode function which will create a node in the linked
		// list in order and set it's data value equal to the integer
		// entered by the user
		myList.appendNode(last, first, age);

		// Capture the next integer
		getline(input, line);
	}

	cout << endl;
	cout << "The linked list in ascending order:" << endl;

	// Call the function displayList which will traverse the linked list
	// and display each node's data value
	myList.displayList();
	cout << endl;

	// Variable to store users answer
	char answer = 'n';

	// Prompt the user to answer if they would like to delete a node
	cout << "Would you like to delete one of the entries? (y/n)" << endl;

	// Get the users input
	cin >> answer;

	// If the user enters 'y' then prompt them to enter what number they
	// would like to delete from the list. Then print the linked list.
	if (answer == 'y')
	{
		// Variable to store the number entered by the user
		int number = 0;

		// Prompt the user to enter the number they would like to delete
		cout << "What number do you want to delete?" << endl;

		// Get the user input
		cin >> number;

		// This function will traverse the list and find the number in the
		// linked list that matches the users input and delete it.
		myList.deleteNode(last, first, age);

		cout << "The list with the node deleted:" << endl;
		myList.displayList();
		cout << endl;
	}

	// Prompt the user to press enter to end the program
	cout << "Press ENTER to continue..." << endl;

	// Pause the program
	cin.get();
	cin.get();
	return 0;
}
