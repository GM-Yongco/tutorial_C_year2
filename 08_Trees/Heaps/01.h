// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================================================================
// STRUCTS 1
// =======================================================================

typedef enum boolean{FALSE, TRUE}BOOLEAN;

// =======================================================================
// MISC FUNCTIONS 1
// =======================================================================

void separator(char* message){
	int count = 43; 				//additional 3 for the (\n)s and the \0
	char new_string[count];

	memset(new_string, '-', count);

	new_string[0] = '\n';
	new_string[count-2] = '\n';
	new_string[count-1] = '\0';

	memcpy(new_string + 1, message, strlen(message));
	new_string[strlen(message) + 1] = ' ';

	printf("%s", new_string);
}