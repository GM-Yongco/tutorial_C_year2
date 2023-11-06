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

typedef struct tree_node{
	int data;
	struct tree_node* left;
	struct tree_node* right;
}tree_node, *p_tree_node;

// =======================================================================
// MISC FUNCTIONS 1
// =======================================================================

void separator(char* message){
	int count = 43;
	char new_string[count];

	memset(new_string, '-', count);

	new_string[0] = '\n';
	new_string[count-2] = '\n';
	new_string[count-1] = '\0';

	memcpy(new_string + 1, message, strlen(message));
	new_string[strlen(message) + 1] = ' ';

	printf("%s", new_string);
}

// =======================================================================
// MISC FUNCTIONS 1
// =======================================================================

void init_tree(p_tree_node* node, int new_data){
	p_tree_node new_node = NULL;
	new_node = (p_tree_node)malloc(sizeof(tree_node));
	new_node->data = new_data;
	new_node->left = NULL;
	new_node->right = NULL;

	*node = new_node;
}

void add_to_tree(p_tree_node* node, int new_data){
	if(*node == NULL){
		init_tree(node, new_data);
	}else if(new_data < (*node)->data){
		add_to_tree(&((*node)->left), new_data);
	}else if(new_data > (*node)->data){
		add_to_tree(&((*node)->right), new_data);
	}
}

void add_to_tree_2(p_tree_node* node, int new_data){
	while(*node != NULL){
		if(new_data < (*node)->data){
			node = &((*node)->left);
		}else{
			node = &((*node)->right);
		}
	}
	init_tree(node, new_data);
}