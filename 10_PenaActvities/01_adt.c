// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define MAX 5

// =======================================================================
// STRUCTS
// =======================================================================

typedef struct{	
	int elem[MAX];
	int count;
}LIST;

// =======================================================================
// FUNCTIONS
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

void display_list(LIST L){
	separator("LIST");

	printf("count = %d", L.count);
	int i;
	for(i = 0; i < L.count; i++){
		printf("\n[%d] : %d", i, L.elem[i]);
	}
}

LIST get_even(LIST L){
	LIST ret_val;
	ret_val.count = 0;

	int x;
	for(x = 0; x < L.count; x++){
		if(L.elem[x] % 2 == 0){
			ret_val.elem[ret_val.count] = L.elem[x];
			ret_val.count++;
		}
	}

	return ret_val;
}

LIST get_even_pt(LIST* L){
	LIST ret_val;
	ret_val.count = 0;

	int x;
	for(x = 0; x < L->count; x++){
		if(L->elem[x] % 2 == 0){
			ret_val.elem[ret_val.count] = L->elem[x];
			ret_val.count++;
		}
	}

	return ret_val;
}

// =======================================================================
// MAIN
// =======================================================================

int main(){
	separator("START");

	// LIST example;
	// example.elem[0] = 3;
	// example.elem[1] = 2;
	// example.elem[2] = 1;
	// example.elem[3] = 0;
	// example.count = 4;

	LIST example = {{1, 2, 3, 4, 5}, 5};

	display_list(example);

	LIST catcher = get_even(example);
	display_list(catcher);

	LIST catcher2 = get_even_pt(&example);
	display_list(catcher2);
	
	separator("END");
	return 0;
}
