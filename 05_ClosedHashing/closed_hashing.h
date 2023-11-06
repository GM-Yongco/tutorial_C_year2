/*
Description     : Code that will impress u ;D
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum BOOL{FALSE, TRUE}BOOL;

// ---------------------------------------------
// Dictionary Definition
// ---------------------------------------------

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

typedef student_info Dictionary[SIZE];
// ---------------------------------------------
// functions misc
// ---------------------------------------------

void test(){
	printf("it went in senpai");
}

// ---------------------------------------------
// functions 1
// ---------------------------------------------

int hash(int ID){
	return ID % SIZE;
}
void initialize(Dictionary D){
	int i;
	for(i = 0; i<SIZE; i++){
        D[i].idNumber = EMPTY;
    }
}
void display(Dictionary D){
	printf("\n\nDISPLAY --------------------\n");
	int i;
    for(i = 0; i < SIZE; i++){
        printf("%d\n", D[i].idNumber);
    }
	printf("\n");
}

// ---------------------------------------------
// functions 2
// ---------------------------------------------

BOOL is_member(Dictionary D, student_info S){
	BOOL found = FALSE;

	int h = hash(S.idNumber);

	int i = h;
	do{
		if(D[i].idNumber == S.idNumber){
			found = TRUE;
		}
		i = (i + 1)%SIZE;
	}while(i != h && D[i].idNumber != EMPTY && found == FALSE);
	// first condition is if it went back to its original positin
	// meaning it went through the list without finding
	// second if it found an emtpy slot before finding which men no member
	// third stops when found is true jsut to not waste cmputation

	return found;
}
BOOL is_full(Dictionary D){
	BOOL is_full = TRUE;
	int i;
	for (i = 0; i < SIZE && is_full; i++){
		if(D[i].idNumber == EMPTY){
			is_full = FALSE;
		}
	}
	return is_full;
}
BOOL insert(Dictionary D, student_info S){
	BOOL success = FALSE;

	// dont do anything if dict is full 
	// or if student is alreayd a member
	if(is_full(D)){	
		printf("\n\nerror: is full");
	}else if(is_member(D, S)){
		printf("\n\nerror: %d: %s already exist", S.idNumber, S.FN);
	}else{
		int h = hash(S.idNumber);

		// finds an empty slot
		// empty slot is guaranteed cuz it passed is_full()
		while(D[h].idNumber != EMPTY){
			h = (h+1)%SIZE;
		}
		D[h].idNumber = S.idNumber;

		success = TRUE;
	}

	return success;
}
BOOL delete(Dictionary D, student_info S){
	// basically same as is_member but deletes when found
	BOOL found = FALSE;

	int h = hash(S.idNumber);

	int i = h;
	do{
		if(D[i].idNumber == S.idNumber){
			D[h].idNumber = DELETED;
			found = TRUE;
		}
		i = (i + 1)%SIZE;
	}while(i != h && D[i].idNumber != EMPTY && found == FALSE);

	return found;
}
