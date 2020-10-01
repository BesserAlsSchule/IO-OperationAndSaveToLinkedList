#include <stdlib.h>					//malloc(), free(), mem mngmt
#include <stdio.h>					//file related IO, putchar(), gets
#include <Windows.h>				//console

int main()
{
	//Bufferdeklarationen
	SetConsoleTitleA("Enter Text and save to linked List");

	char inputStrBuffer[3] = {0};		//char Buffer mit leerer menge initialisieren für freigeräumten speicher
	char inputStrBuffer2[3] = {0};		//nr 2 für element 2
	char inputStrBuffer3[3] = {0};		//nr 3 für element 3


	//Start IO Operations 
	printf("Hello C LinkedList!");
	printf("\n");
	printf("\n");

	printf("Please enter your single char via Keyboard");
	printf("\n");

	fgets(inputStrBuffer, sizeof(inputStrBuffer), stdin);		//fgets(buffer, größe, stream/input) seit c++11 raus -> fgets bessere lösung wgn compilersicherheit
	printf("\n");
	printf("Your 1st Input was: ");
	printf(inputStrBuffer);
	printf("\n");

	//give+print input 2 + input 3
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
		char valueBuffer[3] = {0};										//node value
		element* nextPtr;												//ptr to next element
	} nodeElement;														//deklariere (struct) nodeElement vom <datentyp> element <bezeichner für neu definierten type struct> element

	nodeElement element;												//deklariere instanz vom typ element
	nodeElement element2;
	nodeElement element3;

	element.nextPtr = &element2;										//pointe auf nächstes element
	element2.nextPtr = &element3;
	element3.nextPtr = nullptr;

	//copy inputStrBuffer to element.values
	*element.valueBuffer = *inputStrBuffer;
	*element2.valueBuffer = *inputStrBuffer2;
	*element3.valueBuffer = *inputStrBuffer3;

	printf("\n");
	printf("Input given");
	printf("\n");

	system("Pause");													//getkeyboard

	printf("\n");
	printf("\n");

	if (element.nextPtr && element2.nextPtr != 0)						//NULLprüfung
	{
		system("cls");
		system("color 2");
		
		//print values
		printf("List elements ready and linked, printing elements values");
		printf("\n");
		printf(element.valueBuffer);
		printf("\n");
		printf(element2.valueBuffer);
		printf("\n");
		printf(element3.valueBuffer);
		printf("\n");
		printf("\n");

		//print memory adress of values
		printf("Printing adress stored in linked list elements");
		printf("\n");
		printf("%p", element.valueBuffer);
		printf("\n");
		printf("%p", element2.valueBuffer);
		printf("\n");
		printf("%p", element3.valueBuffer);
		printf("\n");
	}
	else
	{
		printf("Linked lists element creation failed !");
		printf("\n");
	}

	printf("\n");
	printf("End");
	printf("\n");

	return 0;
};
