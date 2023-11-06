// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "03.h"

// =======================================================================
// MAIN
// =======================================================================

void main(){
	separator("START");
	
	// TREE DEFINITION

	Tree* x = NULL;
	x = (Tree*)malloc(sizeof(Tree));
	
	int i;
	for(i = 0; i<MAX; i++){
		x->H[i] = NULL;
	}
	x->root = 5;

	node_initialize(&(x->H[1]), 4);
	node_initialize(&(x->H[1]->next), 7);

	node_initialize(&(x->H[2]), 8);

	node_initialize(&(x->H[5]), 0);
	node_initialize(&(x->H[5]->next), 6);
	node_initialize(&(x->H[5]->next->next), 2);
	
	node_initialize(&(x->H[6]), 0);
	node_initialize(&(x->H[6]->next), 0);

	// PRINTING

	char title_string[99] = "PRINTING CHILDREN ";
	char temp_atoi[10];

	for(i = 0; i<MAX; i++){
		if(x->H[i] != NULL){
			itoa(i, temp_atoi, 10);
			strcpy(title_string + 18, temp_atoi);
			separator(title_string);
			
			print_children(x->H[i]);
			printf("\n%d\n", i);
		}
	}

	separator("END");
}
