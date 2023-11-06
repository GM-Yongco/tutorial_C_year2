/*
Description     : Code that will impress u ;D
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ---------------------------------------------
// Dictionary Definition
// ---------------------------------------------

// id indicator
#define EMPTY -1 
#define DELETED -99 
#define SIZE 8

typedef struct student_info{
	int idNumber;
	int yearLevel;
	char FN [20];
	char LN [20]; 
	char MI;
}student_info;

// ---------------------------------------------
// My Misc
// ---------------------------------------------

void test(){	
	printf("it went in senpai");
}

void seprator(char x[]){
	printf("\n\n============================================================\n");
	printf(" %s", x);
	printf("\n============================================================\n\n");
}

// ---------------------------------------------
// Core
// ---------------------------------------------

void display(student_info S[], int num){
	int i;
	seprator("DISPLAY");
	printf("number of structs in the bin %d\n", num);

	for(i = 0; i < num; i++){
		printf("%d %s\n", S[i].idNumber, S[i].FN);
	}
}