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

	char inputStrBuffer[256] = {};		//char Buffer mit leerer menge initialisieren für freigeräumten speicher


	//Start IO Operations 
	printf("Hello C LinkedList!");
	printf("\n");

	printf("Please enter your Elements via Keyboard");
	printf("\n");

	fgets(inputStrBuffer, sizeof(inputStrBuffer), stdin);		//fgets(buffer, größe, stream/input) seit c++11 raus -> fgets bessere lösung wgn compilersicherheit
	
	printf("\n");
	printf("Your Input was: ");
	printf(inputStrBuffer);

	printf("Input given, press ENTER to continue");
	printf("\n");

	return 0;
}
