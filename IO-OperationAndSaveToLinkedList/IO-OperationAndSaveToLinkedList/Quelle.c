//#include <stdlib.h>					//malloc(), free(), mem mngmt
//#include <stdio.h>					//file related IO, putchar(), gets
//#include <Windows.h>				//console
//#include "IO-OperationAndSaveToLinkedList.h"
//#include <stdbool.h>
//
//
//
//char inputStrBuffer[3] = {0};		//char Buffer mit leerer menge initialisieren f�r freiger�umten speicher
//
//
////LinkedList
//typedef struct element												//definiere (typedef struct "element") <typ> struct element
//{
//	char valueBuffer[3];
//	nodeElement* nextPtr;// = nullptr;										//ptr to next element
//} nodeElement;
//
//
//int main()
//{
//	bool exitProgram = false;
//	SetConsoleTitleA("Enter Text and save to linked List");
//
//	//deklariere (struct) nodeElement vom <datentyp> element <bezeichner f�r neu definierten type struct> element
//
//
//#pragma region MAIN MENU
//
//
//
//
//
//	printf("===== HAUPTEMENUE =====\n");
//
//	char input;
//
//	while (!exitProgram) { // DAS EIGENTLICHE PROGRAMM (IN ENDLOSSCHLEIFE)
//		printf("1. Ein Element Hinzufuegen.\n");
//		printf("2. Die Liste Ausgeben.\n");
//		printf("x. Programm Beenden\n");
//		printf("Eingabe: ");
//
//		//https://stackoverflow.com/questions/2279379/how-to-convert-integer-to-char-in-c
//
//		//while (fgets(&input, 1, stdin)) 	//HOL TEXT AUS STDIN UND SCHMEISS IN ADDRESSE VON INPUT
//		while (input = getc(stdin)) 	//HOL EIN CHAR AUS STDIN UND SCHMEISS IN ADDRESSE VON INPUT ->  http://www.cplusplus.com/reference/cstdio/getc/
//		{
//			if (input == 'x') {
//				exitProgram = true;
//				break;
//			}
//			else if (input == '1') {
//				//Element Hinzuf�gen
//				AddElementToLinkedList();
//			}
//			else if (input == '2') {
//				//Liste Ausgeben
//				PrintLinkedList();
//			}
//		}
//
//	}
//#pragma endregion
//
//	// Free Allocated Memory
//
//	//CLose the Program
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#pragma region LOGIK
//
//
//
////if (element.nextPtr && element2.nextPtr != 0)						//NULLpr�fung
////{
////	system("cls");
////	system("color 2");
//
////	//print values
////	printf("List elements ready and linked, printing elements values");
////	printf("\n");
////	printf(element.valueBuffer);
////	printf("\n");
////	printf(element2.valueBuffer);
////	printf("\n");
////	printf(element3.valueBuffer);
////	printf("\n");
////	printf("\n");
//
////	//print memory adress of values
////	printf("Printing adress stored in linked list elements");
////	printf("\n");
////	printf("%p", element.valueBuffer);
////	printf("\n");
////	printf("%p", element2.valueBuffer);
////	printf("\n");
////	printf("%p", element3.valueBuffer);
////	printf("\n");
////}
////else
////{
////	printf("Linked lists element creation failed !");
////	printf("\n");
////}
//
//
//
//#pragma endregion
//
//
//void PrintLinkedList() {
//	printf(" Anweisungen um ein Die Liste Anzuzeigen\n");
//}
//
//void AddElementToLinkedList() {
//	printf(" Anweisungen um ein Element Hinzuzuf�gen\n");
//
//	GetUserInput(inputStrBuffer);
//
//	// Ein Listeneelement Erstellen (malloc, oder so)
//	nodeElement newNode;
//	nodeElement* pNewNode;
//	pNewNode = (struct nodeElement*)malloc(sizeof(newNode));
//
//	// Adressee des neu Erstelltes Listenelement ,dem vorherigen Listenelemnt in (nextPtr) reinschreiben
//
//#pragma region USER INPUT
//
//
//
//#pragma endregion
//
//#pragma region Erstes Element der Liste erstellen
//
//	nodeElement element;	//deklariere instanz vom typ element
//
//	//copy inputStrBuffer to element.values _ OK
//	*element.valueBuffer = *inputStrBuffer;
//
//
//#pragma endregion
//}
//
//
///// <summary>
///// 
///// </summary>
///// <param name="inputStrBuffer"></param>
//void GetUserInput(char  inputStrBuffer[3])
//{
//	//Start IO Operations 
//	printf("Hello C LinkedList!");
//	printf("\n");
//	printf("\n");
//
//	printf("Please enter your single char via Keyboard");
//	printf("\n");
//
//	fgets(inputStrBuffer, sizeof(inputStrBuffer), stdin);		//fgets(buffer, gr��e, stream/input) seit c++11 raus -> fgets bessere l�sung wgn compilersicherheit
//
//	printf("\n");
//	printf("Your Input was: ");
//	printf(inputStrBuffer);
//	printf("\n");
//}
//
//
