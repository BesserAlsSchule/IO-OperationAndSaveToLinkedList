#include <stdlib.h>					//malloc(), free(), mem mngmt
#include <stdio.h>					//file related IO, putchar(), gets
#include <Windows.h>				//console
#include "IO-OperationAndSaveToLinkedList.h"
#include <stdbool.h>



char inputStrBuffer[3] = {};
			//positive ints für input um menge an erstellter nodes festzulegen

//LinkedList
typedef struct element												//definiere (typedef struct "element") <typ> struct element
{
	char valueBuffer[3] = {};
	element *nextPtr = nullptr;										//ptr to next element
} nodeElement;														//struct element heißt "nodeElement"

nodeElement* rootNode = 0;

int main()
{

	bool exitProgram = false;

	SetConsoleTitleA("Enter char and save to linked list");


#pragma region MAIN MENU

	printf("===== HAUPTEMENUE =====\n");

	char decisionValues[5] = { '1','2','3','x' };
	char input;

	while (!exitProgram) { // DAS EIGENTLICHE PROGRAMM (IN ENDLOSSCHLEIFE)
		printf("1. Ein Element Hinzufuegen.\n");
		printf("2. Die Liste Ausgeben.\n");
		printf("3. Die Liste loeschen.\n");
		printf("x. Programm Beenden\n");
		printf("Eingabe: ");
		printf("\n");

		if (getc(stdin) != *decisionValues)
		{
			printf("Wrong input -> '1','2','3' and 'x' possible! \n");
		}

		//https://stackoverflow.com/questions/2279379/how-to-convert-integer-to-char-in-c

		//while (fgets(&input, 1, stdin)) 	//HOL TEXT AUS STDIN UND SCHMEISS IN ADDRESSE VON INPUT
		while (input = getc(stdin)) 	//HOL EIN CHAR AUS STDIN UND SCHMEISS IN ADDRESSE VON INPUT ->  http://www.cplusplus.com/reference/cstdio/getc/
		{
			if (input == 'x') {
				exitProgram = true;
				break;
			}
			else if (input == '1') {
				//Element Hinzufügen
				//AddElementToLinkedList();		Temporarly Disabled

				AddLinkedListElement();
			}
			else if (input == '2') {
				//Liste Ausgeben
				PrintLinkedList();
			}
			else if (input == '3') {
				//Liste löschen
				DeleteLinkedList();
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
	int integerInput[5] = { '1','2','3','4','5'};
	
	rootNode = (nodeElement*)malloc(sizeof(rootNode));				//heap mem for rootelement
	nodeElement* newNode1 = 0;										//init newNode für neue Node
	nodeElement* newNode2 = 0;
	nodeElement* newNode3 = 0;
	nodeElement* newNode4 = 0;
	nodeElement* newNode5 = 0;

	printf("\n");
	printf("You can create up to 5 nodes per input! \n");
	printf("\n");
	printf("Inputs '1','2','3','4' and '5' possible! \n");
	printf("\n");
	
	//int i = 0;

		while (*integerInput = getc(stdin))
		{	//input<int> = get streambuffer für for loop um nodes zu erstellen
			//hier for loop --> für jedes i < input erstelle nodes
			//hier scanfunktion um nodebezeichner der inputs auf zahlen zu scannen -> scanf()??
				printf("List element creation... \n");
				printf("\n");

				newNode1 = (nodeElement*)malloc(sizeof(newNode1));		//platz für newNode1
				newNode2 = (nodeElement*)malloc(sizeof(newNode2));
				newNode3 = (nodeElement*)malloc(sizeof(newNode3));
				newNode4 = (nodeElement*)malloc(sizeof(newNode4));
				newNode5 = (nodeElement*)malloc(sizeof(newNode5));

				rootNode->nextPtr = newNode1;							//ptr von rootNode an element new node = link zu root
				newNode1->nextPtr = newNode2;
				newNode2->nextPtr = newNode3;
				newNode3->nextPtr = newNode4;
				newNode4->nextPtr = newNode5;
				newNode5->nextPtr = nullptr;


				printf("5 Nodes created, decide how much we´ll keep and which chars they carry! \n");
				printf("\n");
				printf("Following inputs are possible: ");
				printf("newNode1, newNode2, newNode3, newNode4, newNode5");

				char input;
				char checkNodeNames[100] = { 'newNode1','newNode2','newNode3','newNode4','newNode5' };
				while (input = getc(stdin))							//solange input aus inputstream
				{
					if (input == *checkNodeNames)
					{
						printf("Value entered! ", input);
					}
				}
				printf("Test printing of adresses of all nodes: \n");	//testprint adressen
				printf("%p\n", &rootNode);
				printf("%p\n", &newNode1);
				printf("%p\n", &newNode2);
				printf("%p\n", &newNode3);
				printf("%p\n", &newNode4);
				printf("%p\n", &newNode5);
		}
		if (*integerInput != getc(stdin))
		{
			printf("Input out of range -> '1','2','3','4' and '5' are valid! \n");
		}
	return;
}


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
		printf(rootNode->valueBuffer ,"\n");                     //printe die werte, welche in die nodes gepackt wurden
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
