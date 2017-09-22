/*********************************************************************************************
Jody Bailey
CSC 307 - Data Structures
09/13/2017
This is the header file which contains the definitions of the class intList and the function
prototypes. The function prototypes are defined in intList.cpp
*********************************************************************************************/
#pragma once
#include <iostream>
#include <string>

using namespace std;

class intList
{
	// Private member variables
private:
	// Struct that will be used for each node
	struct listNode
	{
		string lastName;
		string firstName;
		int age;
		listNode *next;
	};

	listNode *head;

	// Public member variables
public:
	// See intList.cpp for description of functions
	void appendNode(string last, string first, int age);

	void insertSorted(string last, string first, int age);

	void deleteNode(string last, string first, int age);

	void displayList();

	void deleteList();

	intList();

	~intList();
};
