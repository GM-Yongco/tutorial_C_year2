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

typedef struct node_b_tree{
	char data;
	struct node_b_tree* left;
	struct node_b_tree* rite;
}*b_tree_p, b_tree;

// =======================================================================
// FUNCTIONS MISC
// =======================================================================

void section(char* message){
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
	memcpy(new_string + 2, message, len);
	new_string[len+2] = ' ';
	new_string[1] = ' ';

	printf("%s", new_string);
}

char* alphabet_array(){
	int count = 26;

	char* ret_val = (char*)malloc(sizeof(char) *(count + 1) );
	ret_val[count] = '\0';

	char start = 'A';
	int x;
	for(x = 0; x < count; x++){
		ret_val[x] = start + x;

	}

	return ret_val;
}

// =======================================================================
// FUNCTIONS 1
// =======================================================================

void init(b_tree_p* node, char new_data){
	b_tree_p new_node = (b_tree_p)malloc(sizeof(b_tree));
	new_node->left = NULL;
	new_node->rite = NULL;
	new_node->data = new_data;
	
	*node = new_node;
}

void display_node(b_tree_p node){
	printf("\n %c", node->data);
}

// =======================================================================
// FUNCTIONS 2
// =======================================================================

void post_order(b_tree_p root){
	if(root != NULL){
		post_order(root->left);
		post_order(root->rite);
		display_node(root);
	}
}
void pre_order(b_tree_p root){
	if(root != NULL){
		display_node(root);
		pre_order(root->left);
		pre_order(root->rite);
	}
}

// note, should be the one for binary search tree
void in_order(b_tree_p root){
	if(root != NULL){
		in_order(root->left);
		display_node(root);
		in_order(root->rite);
	}
}
