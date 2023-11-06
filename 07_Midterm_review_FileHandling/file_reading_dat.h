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
typedef struct { 
	char FN[24];
	char MI;
	char LN[16];
}Nametype;

typedef struct {
	Nametype name;
	int ID;
	char course[8]; //BSCS, BSIS, BSIT
	int yrLevel;
}Studtype;

typedef struct{
	Studtype* student_array;
	int count;
}StudentList;

// ---------------------------------------------
// My Misc
// ---------------------------------------------

void test(){	
	printf("it went in senpai");
}

// ---------------------------------------------
// Core
// ---------------------------------------------
void displayHeader(){

}
void displayStudent(Studtype S[], int count){
	printf("\n");
	for (size_t i = 0; i < count; i++){
		printf("%d:%s\n", S[i].ID, S[i].name.FN);
	}
	
}
StudentList* readFile(char file_name[]){
	FILE* file_ptr;
	file_ptr = fopen("students.dat", "rb");

	// ---------------------------------------------
	// Getting number of data thingy 
	// ---------------------------------------------
	fseek(file_ptr, 0, SEEK_END);
	long size = ftell(file_ptr);
	fseek(file_ptr, 0, SEEK_SET);

	int count = size/sizeof(Studtype);

	// ---------------------------------------------
	// Storing the data
	// ---------------------------------------------

	Studtype* data = (Studtype*)malloc(sizeof(Studtype)* count);
	int i = 0;
	while(!feof(file_ptr)){
		fread(&(data[i]), sizeof(Studtype), 1, file_ptr);
		i++;
	}

	StudentList* student_list = (StudentList*)malloc(sizeof(StudentList));
	student_list->student_array = data;
	student_list->count = count;
	
	return student_list;
}