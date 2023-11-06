/*
Description     : Code that will impress u ;)
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>

#include "files.h"

int main(){
	printf("\nSTART ----------------------------------------\n");
	
	FILE* the_file;
	the_file = fopen("NEWTEXT.bin", "rb");

	student_info input[20];
	int i = 0;

	while(!feof(the_file)){
		fread(&(input[i]), sizeof(student_info), 1, the_file);
		i++;
	}
	i--;


	display(input, i);

	printf("\nEND ------------------------------------------\n");
	return 0;
}
