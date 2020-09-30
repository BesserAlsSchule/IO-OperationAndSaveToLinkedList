//#include <iostream>			//IO Output stream object lib -> c++
#include <stdlib.h>				//malloc(), free(), mem mngmt
#include <stdio.h>				//file related IO, putchar(), gets
#include <Windows.h>			//console
//#include <string.h>				//macros+functions für char arrays (Zeichenketten)

//https://www.sololearn.com/Course/C/

int main()
{
	//Members, Variables, Structs deklarieren
	SetConsoleTitleA("Enter Text and save to linked List");

	char inputStrBuffer[20] = {};		//char Buffer mit leerer menge initialisieren für freigeräumten speicher
	char inputStrBuffer2[20] = {};		//nr 2 für element 2
	char inputStrBuffer3[20] = {};		//nr 3 für element 3


	//Start IO Operations 
	printf("Hello C LinkedList!");
	printf("\n");

	printf("Please enter your Elements via Keyboard");
	printf("\n");

	fgets(inputStrBuffer, sizeof(inputStrBuffer), stdin);		//fgets(buffer, größe, stream/input) seit c++11 raus -> fgets bessere lösung wgn compilersicherheit
	
	printf("\n");
	printf("Your Input was: ");
	printf(inputStrBuffer);

	//auswahl input 2 + input 3

	printf("\n");
	printf("Input given, press ENTER to continue");
	printf("\n");

	//LinkedList
	typedef struct element						//definiere <typ> struct element
	{
		char valueBuffer[20] = { };			//node value
		element* nextPtr;				//ptr to next element
	} nodeElement;						//deklariere (klasse) nodeElement vom <datentyp> element <structname> element

	nodeElement a1;							//macht instanz vom typ element, so what mit typedef in nächster zeile?
	fgets(a1.valueBuffer, sizeof(inputStrBuffer), stdin);		//schreibe herein umgehe damit malloc?
	
	nodeElement* a2;


	nodeElement* element = 0;				//deklariere elemente outdated, siehe zeile 45-46
	nodeElement* element2 = 0;				//
	nodeElement* element3 = 0;				//

	//statt elemen1+2+3.... liste aus pointern mit neualloziierten elementen für dynamische erweiterung zur runtime, bezeichner sind hierbei pointer
	element = (nodeElement*)malloc(sizeof(element));	//reserviere heap speicher für element -> unnötig
	element2 = (nodeElement*)malloc(sizeof(element2));	//
	element3 = (nodeElement*)malloc(sizeof(element3));
	
	
	element->nextPtr = element2;
	element2->nextPtr = element3;
	element3->nextPtr = 0;
	
	printf("\n");

	if (element || element2  || element3 != 0)						//NULLprüfung
	{
		printf("Elements ready!");
		printf("\n");
	}
	else {
		printf("Element creation of linked lists failed!");
		printf("\n");
	}


	return 0;
}
