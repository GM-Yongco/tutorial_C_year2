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

#define MAX 10

typedef enum boolean{FALSE, TRUE}BOOLEAN;

typedef struct node{
	int data;
	struct node* next;
}node, *p_node;

typedef struct Tree{
	int root;
	p_node H[MAX];
}Tree;


// =======================================================================
// MISC FUNCTIONS 1
// =======================================================================

void separator(char* message){

	int count = 43;
	char new_string[count];

	int i;
	for(i = 0; i<count; i++){
		new_string[i] = '-';
	}

	new_string[count-1] = '\0';
	new_string[count-2] = '\n';
	new_string[0] = '\n';

	int len = strlen(message);
	memcpy(new_string + 1, message, len);

	new_string[len+1] = ' ';

	printf("%s", new_string);
}

// =======================================================================
// FUNCTIONS 1
// ======================================================================= 

void node_initialize(p_node* node, int new_data){
	p_node new_node = NULL;
	new_node = (p_node)malloc(sizeof(node));
	new_node->data = new_data;
	new_node->next = NULL;

	*node = new_node;
}

void print_children(p_node index){
	
	
	while(index != NULL){
		printf("%d\n", index->data);
		index = index->next;
	}	
}

