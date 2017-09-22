/*********************************************************************************************
Jody Bailey
CSC 307 - Data Structures
09/13/2017
This is the header file which contains the definitions of the class intList and the function
prototypes. The function prototypes are defined in intList.cpp
*********************************************************************************************/
#include "intList.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor for the class intList
intList::intList()
{
	head = new listNode;
	head->next = NULL;
}

// Destructor for the class intList.
// Destructor will call the function deleteList() which will
// traverse the linked list and delete each node
intList::~intList()
{
	deleteList();
}


void intList::appendNode(string last, string first, int age)
{
	listNode *newNode = new listNode;
	newNode->lastName = last;
	newNode->firstName = first;
	newNode->age = age;
	listNode *current = new listNode;
	current = head;

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = newNode;
}

// This function will create a new node and insert it into the 
// linked list in ascending order. The node's data value will
// be equal to the number that is passed in.
void intList::insertSorted(string last, string first, int age)
{
	// Check if head->next is NULL.
	// If it is then there is no other node in the list and we need to
	// insert the node and make head point to it.
	if (head->next == NULL)
	{
		listNode *node = new listNode;
		head->next = node;
		node->lastName = last;
		node->firstName = first;
		node->age = age;
		node->next = NULL;
	}
	// This code will exucute if there is already a node other than head
	// in the list.
	else
	{
		// Create a new node
		listNode *newNode = new listNode;

		// Create a temp node
		listNode *temp = new listNode;

		temp = head;

		//This boolean is used to control the while loop
		bool found = false;

		while (found != true)
		{
			// Check if the next node's data value in the list 
			// is less than the number passed in.
			if (temp->next->lastName < last)
			{
				// Check if the next node in the list is the tail.
				// If it is then the new node will become the tail.
				if (temp->next->next == NULL)
				{
					temp = temp->next;
					newNode->lastName = last;
					newNode->firstName = first;
					newNode->age = age;
					newNode->next = NULL;
					temp->next = newNode;
					found = true;
				}
				// If the next node is not the tail then we set the
				// temp node equal to the next node and continue.
				else
				{
					temp = temp->next;
					continue;
				}
			}
			// If the number passed in is less then the data value of the 
			// next node then we need to insert the node at the current
			// position.
			else if (temp->next->lastName >= last)
			{
				newNode->lastName = last;
				newNode->firstName = first;
				newNode->age = age;
				newNode->next = temp->next;
				temp->next = newNode;
				found = true;
			}
			// If both if statements return false, then we set the temp
			// node equal to the next node and loop again.
			else
			{
				temp = temp->next;
			}
		}
	}
}

// This function will traverse the list and find the node containing the
// number matching the user input and delete that node. (I added this code last
// minute just having fun in case something doesn't look right but I tested it)
void intList::deleteNode(string last, string first, int age)
{
	// Create the needed nodes
	listNode *temp = new listNode;
	listNode *current = new listNode;
	current = head;
	temp = current->next;

	// Variable to control the loop
	bool done = false;

	// Check if the linked list has any nodes
	if (head->next == NULL)
	{
		cout << "There are no nodes to delete." << endl;
		return;
	}

	while (done != true)
	{
		// Check if temp is equal to the number passed in. If it is then
		// set the current nodes next value equal to the node after temp
		// and then delete temp and set done to true
		if (temp->lastName == last)
		{
			current->next = temp->next;
			delete temp;
			done = true;
		}
		// Check if temp is the tail
		else if (temp->next == NULL)
		{
			cout << "The number you entered was not found." << endl;
			return;
		}
		// If both if statements return false then move to the next node
		else
		{
			current = current->next;
			temp = current->next;
		}
	}
}

// This function is going to display the data value's of each node
// in the linked list.
void intList::displayList()
{
	if (head->next == NULL)
	{
		return;
	}
	// Create a new node named current and set it equal
	// to the first node that has a data value.
	listNode *current = new listNode;
	current = head->next;

	// Boolean to control the while loop
	bool done = false;

	while (done != true)
	{
		// Check if the current node is the tail.
		// If it is then print it's data value and set done to true.
		if (current->next == NULL)
		{
			cout << current->lastName << " " << current->firstName << " " << current->age << endl;
			done = true;
		}
		// If the current node is not the tail, print the current data value
		// and set current equal to the next node.
		else {
			cout << current->lastName << " " << current->firstName << " " << current->age << endl;
			current = current->next;
		}
	}
}

// This function will traverse the linked list and delete all of it's nodes.
void intList::deleteList()
{
	// Check if there are any nodes in the list.
	// If not then just return.
	if (head->next == NULL)
	{
		return;
	}
	// Create a new node named current
	listNode *current = new listNode;

	// Create a new node named temp
	listNode *temp = new listNode;

	// Set current equal to the first node with a data value
	current = head->next;

	// Set temp equal to the node after current
	temp = current->next;

	// Boolean to control the while loop
	bool done = false;

	while (done != true)
	{
		// Delete the current node and then set current equal to 
		// the next node
		delete current;
		current = temp;

		// Make sure the current node is now not the tail.
		// If it is not the tail then set temp equal to the 
		// next node in the list.
		if (current->next != NULL)
		{
			temp = current->next;
		}
		// Check if the current node is the tail.
		// If it is the tail then delete the node and set done to true.
		else if (current->next == NULL)
		{
			delete current;
			done = true;
		}
	}
	// After the linked list has been deleted, delete the head 
	// and set it equal to null.
	delete head;
	head = NULL;
}