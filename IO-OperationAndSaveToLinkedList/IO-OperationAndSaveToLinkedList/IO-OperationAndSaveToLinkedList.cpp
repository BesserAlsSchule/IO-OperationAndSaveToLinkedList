//#include <iostream>				//IO Output stream object lib -> c++
#include <stdlib.h>					//malloc(), free(), mem mngmt
#include <stdio.h>					//file related IO, putchar(), gets
#include <Windows.h>				//console
//#include <string.h>				//macros+functions für char arrays (Zeichenketten)

int main()
{
	//Bufferdeklarationen
	SetConsoleTitleA("Enter Text and save to linked List");

	char inputStrBuffer[20] = {};		//char Buffer mit leerer menge initialisieren für freigeräumten speicher
	char inputStrBuffer2[20] = {};		//nr 2 für element 2
	char inputStrBuffer3[20] = {};		//nr 3 für element 3


	//Start IO Operations 
	printf("Hello C LinkedList!");
	printf("\n");
	printf("\n");

	printf("Please enter your Elements via Keyboard");
	printf("\n");

	fgets(inputStrBuffer, sizeof(inputStrBuffer), stdin);		//fgets(buffer, größe, stream/input) seit c++11 raus -> fgets bessere lösung wgn compilersicherheit
	printf("\n");
	printf("Your 1st Input was: ");
	printf(inputStrBuffer);
	printf("\n");

	//gebe+printe input 2 + input 3
	fgets(inputStrBuffer2, sizeof(inputStrBuffer2), stdin);
	printf("\n");
	printf("Your 2nd Input was: ");
	printf(inputStrBuffer2);
	printf("\n");

	fgets(inputStrBuffer3, sizeof(inputStrBuffer3), stdin);
	printf("\n");
	printf("Your 3rd Input was: ");
	printf(inputStrBuffer3);
	printf("\n");

	//LinkedList
	typedef struct element												//definiere (typedef struct "element") <typ> struct element
	{
		char valueBuffer[20] = { };										//node value
		element* nextPtr;												//ptr to next element
	} nodeElement;														//deklariere (struct) nodeElement vom <datentyp> element <bezeichner für neu definierten type struct> element

	nodeElement element;												//deklariere instanz vom typ element
	nodeElement element2;
	nodeElement element3;

	element.nextPtr = &element2;										//pointe auf nächstes element
	element2.nextPtr = &element3;
	element3.nextPtr = 0;												//ende der linked list

	fgets(element.valueBuffer, sizeof(inputStrBuffer), stdin);		    //schreibe herein umgehe damit malloc?
	fgets(element2.valueBuffer, sizeof(inputStrBuffer2), stdin);	
	fgets(element3.valueBuffer, sizeof(inputStrBuffer3), stdin);
	
	printf("\n");
	printf("Input given, press ENTER to continue");
	printf("\n");

	system("Pause");													//getkeyboard
	
	printf("\n");
	printf("You did it bra!");
	printf("\n");

	if (element.nextPtr && element2.nextPtr != 0)						//NULLprüfung
	{
		printf("Elements ready and linked !");
		printf("\n");
	}
	else 
	{
		printf("Element creation of linked lists failed !");
		printf("\n");
	}

	//user answer, print input
	printf("Enter Y or y for printing values of linked list elements to console");
	char consoleAnswerBufferY[4] = "Y y";
	printf("Enter ´N´ or ´n´ for printing values of linked list elements to console");
	char consoleAnswerBufferN[4] = "N n";

	return 0;
}
