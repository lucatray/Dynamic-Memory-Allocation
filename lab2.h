#include <stdio.h>
#include <string.h>
//Header file for lab2.c by Lucas and Tyler
struct Data {
	int idNum;
	char eName[10];
};

void printData(struct Data data) {
	fprintf(stderr, "Employee Number: %d\n", data.idNum);
	fprintf(stderr, "Employee Name: %s\n\n", data.eName);
} //return data; //returns the data for usage

void createData() {
	struct Data *headPtr; //pointer for beginning or data
	struct Data *movePtr;

	headPtr = (struct Data *) malloc (sizeof(struct Data) * 5);//Alc. Mem
	movePtr = headPtr;
	if (movePtr == NULL){
		fprintf(stderr, "Out of Memory Error\n\n");
	}
	else {
		/* Add Data to Allocated Memory */
		fprintf(stderr, "Memory created\n");
		movePtr->idNum = 1234;
		//movePtr->eName = "Bob";
		movePtr++;
		movePtr->idNum = 5678;
		//movePtr->eName = "Joe";
		movePtr++;
		movePtr->idNum = 2458;
		//movePtr->eName = "Carl";
		movePtr++;
		movePtr->idNum = 0250;
		//movePtr->eName = "Lucas";
		movePtr++;
		movePtr->idNum = 3810;
		//movePtr->eName = "Tyler";
		movePtr++;
		for (int num = 0; num < 5; num++){
			fprintf(stderr, "Test Outut: \"%d\"\"%s\"\n", movePtr->idNum, movePtr->eName);
			movePtr++;
		}
	}
} //createData
