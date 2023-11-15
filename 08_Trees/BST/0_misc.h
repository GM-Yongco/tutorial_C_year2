// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <string.h>

// =======================================================================
// MISC FUNCTIONS 1
// =======================================================================

void separator(char* message){
	int count = 53; 				//additional 3 for the (\n)s and the \0
	char new_string[count];

	memset(new_string, '-', count);

	new_string[0] = '\n';
	new_string[count-2] = '\n';
	new_string[count-1] = '\0';

	memcpy(new_string + 1, message, strlen(message));
	new_string[strlen(message) + 1] = ' ';

	printf("%s", new_string);
}

void error_in(char* function_name){
	int count = 53; 				//additional 3 for the (\n)s and the \0
	char new_string[count];
	char error_teplate[] = "Error in function: ";

	memset(new_string, '-', count);

	new_string[0] = '\n';
	new_string[count-2] = '\n';
	new_string[count-1] = '\0';

	memcpy(new_string + 1, error_teplate, strlen(error_teplate));
	memcpy(new_string + 1 + strlen(error_teplate), function_name, strlen(function_name));

	new_string[strlen(error_teplate) + strlen(function_name) + 1] = ' ';

	printf("%s", new_string);
}

