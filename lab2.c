#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab2.h"

int dataEntries = 0; //default entries --> assuming the database begins empty
struct Data *tempPtr; //pointer to beginning of new block of created memory
struct Data *movePtr; //pointer that moves around (floater)
struct Data *tailPtr; //pointer that moves through the "head" memory
struct Data *headPtr; //pointer to beginning of "old" block of memory


//funtion to recognize if user entered invalid input
void validInput (void){
	int i = getchar();
	while (i != '\n' && i != EOF)
		i = getchar();
}


//function to print all records in allocated memory
void printRecords(){ //Menu 1
	if (headPtr == NULL){
		fprintf(stderr, "THERE ARE NO ENTRIES::\n\n");
	}
	else{
		movePtr = headPtr;
		for (int num = 0; num < dataEntries; num++){
			fprintf(stderr, "Data Output: \"%d\" \"%s\"\n", movePtr->idNum, movePtr->eName);
			movePtr++;
		}
	}
	fprintf(stderr, "\n"); //spacer
}


//Menu 2 is in case 2

//function to print size of current size of allocated memory (database)
void printSize(){ //Menu 3 ***NOT DONE have to fix size value
	if (headPtr == NULL){
		fprintf(stderr, "Total Database Size: 0\n");
	}
	else{
		fprintf(stderr, "Total Database Size: \"%lu\"\n", sizeof(headPtr->eName)+sizeof(headPtr->idNum));
	}
} //printSize


//Ensures that memory allocation is possible
void addRecValidate(){ //Menu 4.a
	if (dataEntries == 0){
		fprintf(stderr, "Zero Entries::\n");
		tempPtr = (struct Data *)malloc(sizeof(struct Data));
		movePtr = tempPtr;
	}
	else{
		fprintf(stderr, "Allocating New Memory::\n");
		tempPtr = (struct Data *)malloc(sizeof(struct Data)*dataEntries+1);
		movePtr = tempPtr;
		if (movePtr == NULL){
			fprintf(stderr, "Out of Memory ---> Error::\n\n");
		}
		else{
			fprintf(stderr, "Memory Successfully Allocated:: \"%lu\"\n", (sizeof(tempPtr->eName)+sizeof(tempPtr->idNum))*dataEntries);
		}
	}
} //addRecValidate


//function to add new record to database
void addRecord(){ //Menu 4
	addRecValidate();
	if (headPtr == NULL) { //means that there is no head block data --> no previously allocated memory
		fprintf(stderr, "No Previous Data::\n");
		int counter;
		for (int num = 0; num < dataEntries+1; num++){
			fprintf(stderr, "Enter Employee ID: ");
			scanf("%d", &movePtr->idNum);
			fprintf(stderr, "Enter Employee Name: ");
			scanf("%s", movePtr->eName);
			/* Second option for single line input
			fprintf(stderr, "Enter Employee ID followed by Name: ");
			scanf("%d %s", &movePtr->idNum, movePtr->eName);
			*/
			fprintf(stderr, "\nPtr record: \"%d\"\"%s\"\n", movePtr->idNum, movePtr->eName);
			fprintf(stderr, "New mem record: \"%d\"\"%s\"\n", tempPtr->idNum, tempPtr->eName);
			movePtr++;
			fprintf(stderr, "Mover value after increment: \"%d\"\"%s\"\n", movePtr->idNum, movePtr->eName);
			counter = num + 1;
		}
		dataEntries = counter;
	}
	else { //for every entry after the inital entry
		fprintf(stderr, "Copying Data::\n");
		tailPtr = headPtr; //set tail to beginning of old block
		int counter = 0;
		/*
		Pointer notes before loop
		head = old block
		move = beginning of new block
		tail = beginning of old block
		temp = new block
		*/
		for (tailPtr != NULL; counter < dataEntries; counter++){ //copy over records
			fprintf(stderr, "movePtr: \"%d\"\"%s\"\n", movePtr->idNum, movePtr->eName); //should always be empty
			fprintf(stderr, "tailPtr: \"%d\"\"%s\"\n", tailPtr->idNum, tailPtr->eName); //should have record to add
			memcpy(movePtr++, tailPtr++, strlen(tailPtr->eName)+sizeof(tailPtr->idNum));//data transferred from head to temp
		}
		fprintf(stderr, "\nEnter Employee ID: ");
		scanf("%d", &tailPtr->idNum);
		fprintf(stderr, "Enter Employee Name: ");
		scanf("%s", tailPtr->eName);
		/*  Second option for single line input
		fprintf(stderr, "Enter Employee ID followed by Name: ");
		scanf("%d %s", &movePtr->idNum, movePtr->eName);
		*/
		fprintf(stderr, "\nAdded Record: \"%d\"\"%s\"\n", tailPtr->idNum, tailPtr->eName);
		memcpy(movePtr++, tailPtr++, strlen(tailPtr->eName)+4);
		dataEntries++;
	}
	headPtr = tempPtr;
	fprintf(stderr, "Head value: \"%d\"\"%s\"\n\n", headPtr->idNum, headPtr->eName);
} //addRecord




void load_menu() {
	int choice;
	system("clear");
	int count = 0;
	while (1){
		choice = '\0';
		fprintf(stderr, "Menu\n\n");
		fprintf(stderr, "1.) Print all records\n");
		fprintf(stderr, "2.) Print number of records\n");
		fprintf(stderr, "3.) Print size of database\n");
		fprintf(stderr, "4.) Add record\n");
		fprintf(stderr, "5.) Delete record\n");
		fprintf(stderr, "6.) Print number of accessess to database\n");
		fprintf(stderr, "7.) Exit program\n\n");
		fprintf(stderr, "Selection Choice: ");
		scanf("%d", &choice);
		fprintf(stderr, "\n");
		if(choice == 4 || choice == 5)
			count++;
		switch(choice)
		{
		case 1:
			system("clear");
			printRecords();
			//createData(); //If looking for header data
			break;
		case 2:
			system("clear");
			fprintf(stderr, "Total Entires: %d\n\n", dataEntries);
			break;
		case 3:
			system("clear");
			printSize();
			break;
		case 4:
			system("clear");
			addRecord();
			break;
		case 5:
			system("clear");
			//deleteRecord();
			break;
		case 6:
			system("clear");
			fprintf(stderr, "Total number of accesses to database: %d\n\n", count);
			break;
		case 7:
			fprintf(stderr, "Quitting program.\n");
			exit(0);
			system("clear");
			break;
		default:
			fprintf(stderr, "Invalid choice. Please select options 1-7.");
			validInput();
			break;
		} //switch
	} //while loop
} //loadMenu



void main(void) {
	load_menu();
} //main
