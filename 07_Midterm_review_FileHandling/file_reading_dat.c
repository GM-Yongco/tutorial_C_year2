/*
Description     : Code that will impress u ;)
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>

#include "file_reading_dat.h"

int main(){
	printf("\nSTART ----------------------------------------\n");
	
	char file_name[] = "students.dat";

	StudentList* input = readFile(file_name);

	test();

	displayStudent(input->student_array, input->count);

	printf("\nEND ------------------------------------------\n");
	return 0;
}
