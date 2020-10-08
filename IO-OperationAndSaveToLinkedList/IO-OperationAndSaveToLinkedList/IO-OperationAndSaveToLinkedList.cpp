#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>					//malloc(), free(), mem mngmt
#include <stdio.h>					//file related IO, putchar(), gets
#include <Windows.h>				//console
#include "IO-OperationAndSaveToLinkedList.h"
#include <stdbool.h>
#include <string.h>

char inputStrBuffer[100] = {};
//positive ints für input um menge an erstellter nodes festzulegen



//LinkedList
typedef struct nodeElement												//definiere (typedef struct "element") <typ> struct element
{
	char valueBuffer[100] = {};
	nodeElement* nextPtr = 0;										//ptr to next element
};													//struct element heißt "nodeElement"

nodeElement* rootNode = 0;

int main()
{
	bool exitProgram = false;

	SetConsoleTitleA("Enter char and save to linked list");

#pragma region MAIN MENU

	printf("===== HAUPTEMENUE =====\n");

	char decisionValues[5] = { '1','2','3','x' }; // = "123x"
	char input = ' ';

	while (!exitProgram) { // DAS EIGENTLICHE PROGRAMM (IN ENDLOSSCHLEIFE)
		printf("1. Ein Element Hinzufuegen.\n");
		printf("2. Die Liste Ausgeben.\n");
		printf("3. Die Liste loeschen.\n");
		printf("x. Programm Beenden\n");
		printf("Eingabe: ");



		auto a = scanf("%c", &input);
		switch (input)
		{
			//https://stackoverflow.com/questions/2279379/how-to-convert-integer-to-char-in-c
		case '1':
			AddLinkedListElement();
			break;
		case '2':
			PrintLinkedList();
			break;
		case '3':
			DeleteLinkedList();
			break;
		case  'x':
			exitProgram = true;
			break;

		default:
			printf("Wrong input -> '1','2','3' and 'x' possible! \n");
			break;
		}



		//while (fgets(&input, 1, stdin)) 	//HOL TEXT AUS STDIN UND SCHMEISS IN ADDRESSE VON INPUT
		while (!scanf("%c", &input)) 	//HOL EIN CHAR AUS STDIN UND SCHMEISS IN ADDRESSE VON INPUT ->  http://www.cplusplus.com/reference/cstdio/getc/
		{
			if (input == 'x') {
				exitProgram = true;
				break;
			}
			else if (input == '1') {
				//Element Hinzufügen
				//AddElementToLinkedList();		Temporarly Disabled


			}
			else if (input == '2') {
				//Liste Ausgeben

			}
			else if (input == '3') {
				//Liste löschen

			}
		}
	}
#pragma endregion

	//CLose the Program
	return 0;
};

#pragma region LOGIK

//if (element.nextPtr && element2.nextPtr != 0)						//NULLprüfung
//{
//	system("cls");
//	system("color 2");

//	//print values
//	printf("List elements ready and linked, printing elements values");
//	printf("\n");
//	printf(element.valueBuffer);
//	printf("\n");
//	printf(element2.valueBuffer);
//	printf("\n");
//	printf(element3.valueBuffer);
//	printf("\n");
//	printf("\n");

//	//print memory adress of values
//	printf("Printing adress stored in linked list elements");
//	printf("\n");
//	printf("%p", element.valueBuffer);
//	printf("\n");
//	printf("%p", element2.valueBuffer);
//	printf("\n");
//	printf("%p", element3.valueBuffer);
//	printf("\n");
//}
//else
//{
//	printf("Linked lists element creation failed !");
//	printf("\n");
//}

#pragma endregion

void AddLinkedListElement()				//erstelle bis zu 5 nodes per user input -> wenn noderstellung klappt noch char values zu value buffer hinzufügen
{
	int integerInput[5] = { '1','2','3','4','5' };

	//heap mem for rootelement
	nodeElement* latestNode = 0;

	nodeElement* newNode1 = 0;										//init newNode für neue Node
	nodeElement* newNode2 = 0;
	nodeElement* newNode3 = 0;
	nodeElement* newNode4 = 0;
	nodeElement* newNode5 = 0;

	printf("\n");
	printf("You can create up to 5 nodes per input! \n");
	printf("\n");
	printf("Inputs '1','2','3','4' and '5' possible! \n");
	printf("Input:");

	int i_input = 0;
	//Einlesen der Anzahl der zu erstellenden Nodes
	scanf("%i", &i_input);

	//Erstellen der Nodes

	/*
	*	Bei Eingabe von genau 1
	*	erste node Erstellen wenn nicht vorhanden
	*/
	/*if (i_input == 1)
	{
		if (rootNode == NULL) {
			rootNode = (nodeElement*)malloc(sizeof(rootNode));
		}
		printf("Node Erstellt - Adresse: %p", rootNode);
		return;
	}*/

	/*
	*	Bei Eingabe von größer 1
	*	erste node Erstellen wenn nicht vorhanden und weitere Nodes erstellen und anhängen
	*/
	//if (rootNode == NULL) {
	//	rootNode = (nodeElement*)malloc(sizeof(rootNode));
	//	printf("Root Node Erstellt - Adresse: %p", rootNode);
	//}

	int i = 0;
	//Neue Anzahl an Nodes hinzufügen
	for (i = 1; i <= i_input; i++) {
		//Ersten Node Erstellen, Überspringen wenn schon vorhanden
		if (rootNode == nullptr) {
			rootNode = getNewNode();

			//Werte für den Node Alloziieren
			rootNode->nextPtr = 0;
			strcpy(rootNode->valueBuffer, "0");

			printf("Root Node Erstellt - Adresse: %p\n", rootNode);
		}
		if (i_input == 1) break;


		//rootNode->nextPtr = (nodeElement*)malloc(sizeof(rootNode));

		latestNode = rootNode;


		bool lastNodeFound = false;
		//Letzte Node Suchen
		while (lastNodeFound == false)
		{
			//Im Aktuellen Node, den Eintrag für den Nächsten Node abfragen auf nullptr
			if (latestNode->nextPtr == nullptr)
			{
				//Letzten Node Gefunden, an diesem Einen neuen anhängen
				latestNode->nextPtr = getNewNode();

				//Neusten node in der Loop Aktualisieren
				latestNode = latestNode->nextPtr;
				printf("\nNeue Node Erstellt - Adresse: %p\n", latestNode);
				lastNodeFound = true;
			}
			else
			{
				//TODO: Er weist sich nicht das Nächste Nodeelement Zu, ist in endlosschleife gefangen

				//Node ist nicht der Letzte, weitersuchen!
				latestNode = latestNode->nextPtr;
			}
		}



	}
}

nodeElement* getNewNode()
{
	static nodeElement* newNode = (nodeElement*)malloc(sizeof(rootNode));
	newNode->nextPtr = 0;
	strcpy(newNode->valueBuffer, "0");
	return newNode;
}


//
//
//	//input<int> = get streambuffer für for loop um nodes zu erstellen
//	//hier for loop --> für jedes i < input erstelle nodes
//	//hier scanfunktion um nodebezeichner der inputs auf zahlen zu scannen -> scanf()??
//	printf("List element creation... \n");
//	printf("\n");
//
//	newNode1 = (nodeElement*)malloc(sizeof(newNode1));		//platz für newNode1
//	newNode2 = (nodeElement*)malloc(sizeof(newNode2));
//	newNode3 = (nodeElement*)malloc(sizeof(newNode3));
//	newNode4 = (nodeElement*)malloc(sizeof(newNode4));
//	newNode5 = (nodeElement*)malloc(sizeof(newNode5));
//
//	rootNode->nextPtr = newNode1;							//ptr von rootNode an element new node = link zu root
//	newNode1->nextPtr = newNode2;
//	newNode2->nextPtr = newNode3;
//	newNode3->nextPtr = newNode4;
//	newNode4->nextPtr = newNode5;
//	newNode5->nextPtr = nullptr;
//
//	printf("5 Nodes created, decide how much we´ll keep and which chars they carry! \n");
//	printf("\n");
//	printf("Following inputs are possible: ");
//	printf("1 - newNode1, 2 - newNode2, 4 - newNode3, 4 - newNode4, 5 - newNode5");
//
//	//Anzahl an nodes Bestimmen:
//	char checkNodeNames[100];
//	int input;
//
//	bool valid = false;
//	do {
//		//Einlesen aus Konsole
//		scanf("%i", &input);
//
//		//Eingabe vergleichen (SWitch Case) - Bei Default Erneut Fragen#
//		switch (input)
//		{
//		case 1:
//			strcpy(checkNodeNames, "newNode1");
//			valid = true;
//			break;
//		case 2:
//			strcpy(checkNodeNames, "newNode2");
//			valid = true;
//			break;
//		case 3:
//			strcpy(checkNodeNames, "newNode3");
//			valid = true;
//			break;
//		case 4:
//			strcpy(checkNodeNames, "newNode4");
//			valid = true;
//			break;
//		case 5:
//			strcpy(checkNodeNames, "newNode5");
//			valid = true;
//			break;
//		default:
//			valid = false;
//			break;
//		}
//	} while (valid == false);
//	printf("Value entered: %i", input);
//
//
//	printf("Test printing of adresses of all nodes: \n");	//testprint adressen
//	printf("%p\n", &rootNode);
//	printf("%p\n", &newNode1);
//	printf("%p\n", &newNode2);
//	printf("%p\n", &newNode3);
//	printf("%p\n", &newNode4);
//	printf("%p\n", &newNode5);
//}


#pragma region AddElementToListRapha
//void AddElementToLinkedList() {
//	printf(" Anweisungen um ein Element Hinzuzufügen\n");
//
//	GetUserInput();
//
//	// Ein Listeneelement Erstellen (malloc) und die Adresse des reservierten Speichers in einen ZwischenPointer ablegen
//	nodeElement* pNewNode = 0;
//	pNewNode = (nodeElement*)malloc(sizeof(pNewNode));		//pnewnode hält adresse des speicherblockes von malloc
//
//	//Das Letzte Listenelement Holen und den erstellten Speicherbereich Verweisen
//	/* Von der Root node anfangen das Feld nextPTr zu prüfen bis es einen nullpointer zeigt, dieser Node ist dann der letzte
//	* Node
//	*/
//	nodeElement* currentNodeElement = &rootNode;				//deklariere currentNodeElement und gebe diesem
//
//	while (currentNodeElement->nextPtr != nullptr) {
//		//currentNextPTr = nextPtr des Nächsten nodes
//		currentNodeElement = &(*(currentNodeElement->nextPtr));		//adresse+pointer von currentnodelement.nextPtr???
//	}
//	// Adressee des neu Erstelltes Listenelement ,dem vorherigen Listenelemnt in (nextPtr) reinschreiben
//}

void PrintLinkedList()
{
	printf("Linked list values and node adresses: \n");

	do
	{
		printf(rootNode->valueBuffer, "\n");                     //printe die werte, welche in die nodes gepackt wurden
		rootNode = rootNode->nextPtr;                            //auf zum nächsten Knoten
	} while (rootNode != 0);

	//for (i = 5; *integerInput <= i; ++i)				//schwachsinn, soll adressen und values auf node->valueBuffer zeigen
	//{
	//	printf("Print new nodes´ value buffer: \n");
	//	(nodeElement*)printf(newNode->valueBuffer);
	//	printf("\n");
	//	printf("Print new nodes´ adresses: \n");
	//	(nodeElement*)printf((const char*)&newNode);
	//};
}

void DeleteLinkedList()						//wird im endeffekt kopie von node erstellung
{
	printf("Start deletion of linked list \n");
	//Delete Linked List
	// Free Allocated Memory
}

void WriteValuesToLinkedList()
{
	char nodeInput[3] = {};

	//nodeElement* newNode1;

	printf("Write a single char to every node of the list: ");
	*nodeInput = getc(stdin);

	//AddLinkedListElement();

	//for (int i = 1; i <= 5; ++i)                                    //for loop für node erstellung ->
	//{
	//	&newNode1->valueBuffer = (int*)i;                                   //greife auf member data zu und weise int i als Datensatz zu
	//}
}

/// <summary>
/// eingabe Vom User in inputStrBuffer Schreiben
/// </summary>
/// <param name="inputStrBuffer"></param>
void GetUserInput()															//erstmal nicht genutzt
{
	//Start IO Operations
	printf("\n");
	printf("Please enter your single char via keyboard \n");
	printf("\n");

	while (fgets(inputStrBuffer, sizeof(inputStrBuffer), stdin) != nullptr) {
		printf("Your input was: \n");
		printf("%s", inputStrBuffer);									//print input-> warum bei getuserinput?
		break;
	}

	//fgets(buffer, größe, stream/input) seit c++11 raus -> fgets bessere lösung wgn compilersicherheit

	printf("\n");
	printf("Your Input was: \n");
	printf(inputStrBuffer);
	printf("\n");
}