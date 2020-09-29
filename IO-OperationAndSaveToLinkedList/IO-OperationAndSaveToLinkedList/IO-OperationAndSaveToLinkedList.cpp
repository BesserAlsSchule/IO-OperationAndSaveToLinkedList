//#include <iostream>			//IO Output stream object lib -> c++
#include <stdlib.h>				//malloc(), free(), mem mngmt
#include <stdio.h>				//file related IO, putchar(), gets
#include <Windows.h>			//console
#include <string.h>				//macros+functions für char arrays (Zeichenketten)

//https://www.sololearn.com/Course/C/

int main()
{
	//Members, Variables, Structs deklarieren
	SetConsoleTitle(L"");

	char* inputStr[256] = {};		//char Buffer mit leerer menge initialisieren für "leeren", freigeräumten speicher


	//Start IO Operations 
	printf("Hello C LinkedList!");
	printf("\n");

	printf("Please enter your Elements via Keyboard");
	printf("\n");

	//getchar(inputStr);

	scanf("%C", &inputStr);

	//strcat(inputStr, *inputStr);
	printf("Input given, press ENTER to continue");
	printf("\n");


	for (int i = 0; i < sizeof(inputStr); ++i)					//char array wird nicht gelesen
	{
		printf(inputStr[i]);								//argument=inputstr, parameter=was frisst die foo
	}

}