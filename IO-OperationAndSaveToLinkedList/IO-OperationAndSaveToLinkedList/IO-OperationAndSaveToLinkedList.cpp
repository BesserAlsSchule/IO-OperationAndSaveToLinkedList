//#define _CRT_SECURE_NO_WARNINGS							//für die Benutzung von alten funktionen ohne "_s"-suffix

#include "IO-OperationAndSaveToLinkedList.h"			

#include <stdlib.h>										
#include <stdio.h>										
#include <Windows.h>									
#include <stdbool.h>									
#include <string.h>										
#include <iostream>

using namespace std;

//NODE
typedef struct nodeElement										
{
	char valueBuffer = {};
	nodeElement* nextPtr = 0;
};

nodeElement* rootNode = 0;

int main()
{
	SetConsoleTitleA("Enter char and save to linked list");

	bool exitStartText = false;
	bool exitProgram = false;

	//STARTTEXT
	while (exitProgram != true)
	{
		if (exitStartText == false)
		{
			cout << "===== MAIN MENUE ===== \n";					
			cout << "1.Add element and value \n";
			cout << "2.Print list \n";
			cout << "3.Add single node to start \n";
			cout << "4.Add single node to end \n";
			cout << "5.Add single node to specified position \n";
			cout << "6.Delete last element of linked list \n";
			cout << "9.Exit program \n";
			cout << "===== MAIN MENUE ===== \n";
			cout << "\n";
			cout << "Enter your int input for choosing: \n";
			cout << "Integers 1-6 + 9 are possible inputs! \n";

			exitStartText = true;
		}
		 
		//ABLAUFSTEUERUNG FÜR OPERATIONEN
		int input;
		cout << "\n";
		cout << "Int  Input: \n";
		cin >> input;

		switch (input)
		{
		case 1:
			AddElementAndValue();
			break;
		case 2:
			PrintLinkedList();
			break;
		case 3:
			AddSingleNodeToStart();
			break;
		case 4:
			AddSingleNodeToEnd();
			break;
		case 5:
			InsertAtSpecifiedPosition();
			break;
		case 6:
			DeleteLinkedList();
			break;
		case 9:
			exitProgram = true;
			exit(0);
			break;
		default:
			cout << "Wrong input! \n";
			exit(0);
			break;
		}

	}
	return 0;
}

void AddElementAndValue()
{
	struct nodeElement* temp, * ptr;
	temp = (struct nodeElement*)malloc(sizeof(nodeElement));
	if (temp == 0)
	{
		cout << "No Memory left! \n";
		exit(0);
	}
	cout << "Enter the single char value for the new node: \n";

	cin >> temp->valueBuffer;
	temp->nextPtr = 0;
	if (rootNode == 0)
	{
		rootNode = temp;
	}
	else
	{
		ptr = rootNode;
		while (ptr->nextPtr != 0)
		{
			ptr = ptr->nextPtr;
		}
		ptr->nextPtr = temp;
	}
}

//APPEND, PREPEND, ADD AT SPECIFIED POSITION
void AddSingleNodeToStart()
{
	cout << "Add node to start of linked list! \n";
	struct nodeElement* temp;
	temp = (struct nodeElement*)malloc(sizeof(nodeElement));
	if (temp == 0)
	{
		cout << "No Memory left! \n";
		return;
	}
	cout << "Enter the single char value for the node: \n";
	cin >> temp->valueBuffer;
	temp->nextPtr = 0;
	if (rootNode == 0)
	{
		rootNode = temp;
	}
	else
	{
		temp->nextPtr = rootNode;
		rootNode = temp;
	}
}

void AddSingleNodeToEnd()
{
	cout << "Add node to end of linked list! \n";
	struct nodeElement* temp, * ptr;
	temp = (struct nodeElement*)malloc(sizeof(nodeElement));
	if (temp == 0)
	{
		cout << "No Memory left! \n";
		return;
	}
	cout << "Enter the single char value for the node: \n";
	cin >> temp->valueBuffer;
	temp->nextPtr = 0;
	if (rootNode == 0)
	{
		rootNode = temp;
	}
	else
	{
		ptr = rootNode;
		while (ptr->nextPtr != 0)
		{
			ptr = ptr->nextPtr;
		}
		ptr->nextPtr = temp;
	}
}

void InsertAtSpecifiedPosition()
{
	struct nodeElement* temp, * ptr;
	int i = 0;
	int listPos = 0;
	temp = (struct nodeElement*)malloc(sizeof(struct nodeElement));
	if (temp == 0)
	{
		cout << "No memory left! \n";
		return;
	}

	cout << "Enter int for adding node at specified position in linked list \n";
	cin >> listPos;

	cout << "Enter the single char value for the node: \n";
	cin >> temp->valueBuffer;
	if (listPos == 0)
	{
		temp->nextPtr = rootNode;
		rootNode = temp;
	}
	else
	{
		for (i = 0, ptr = rootNode; i < (listPos - 1); i++)
		{
			ptr = ptr->nextPtr;
			if (ptr == 0)
			{
				cout << "Specified position not found! \n";
				return;
			}
		}
		temp->nextPtr = ptr->nextPtr;
		ptr->nextPtr = temp;
	}
	return;
}

//PRINT, DELETE
void PrintLinkedList()					
{
	struct nodeElement* ptr;
	if (rootNode == 0)
	{
		cout << "List is empty! \n";
		return;
	}
	else
	{
		ptr = rootNode;
		cout << "The list elements are: \n";
		while (ptr != 0)
		{
			cout << ptr->valueBuffer, "\n";
			cout << "\n";
			ptr = ptr->nextPtr;
		}
	}
	return;
}

void DeleteLinkedList() 
{
	cout << "Delete \n";
	struct nodeElement* temp = {}, *ptr;
	if (rootNode == 0)
	{
		cout << "List is empty, exiting program \n";
		exit(0);
	}
	else if (rootNode->nextPtr == 0)
	{
		ptr = rootNode;
		rootNode = 0;
		printf("The deleted element is: %c", ptr->valueBuffer, "\n");
		free(ptr);
	}
	else
	{
		ptr = rootNode;
		while (ptr->nextPtr != 0)
		{
			temp = ptr;
			ptr = ptr->nextPtr;
		}
		temp->nextPtr = 0;
		printf("The deleted element is: %c", ptr->valueBuffer, "\n");
		free(ptr);
	}
}
