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
// MAIN
// =======================================================================

int main(){
    section("START");

    // INITIALIZATION

    char* al = alphabet_array();
    
    b_tree_p root = NULL;
	init(&root, al[0]);

	init(&(root->left), al[1]);
	init(&(root->rite), al[2]);
	
	init(&(root->left->left), al[3]);    
	init(&(root->left->rite), al[4]);
	init(&(root->rite->left), al[5]);
	init(&(root->rite->rite), al[6]);

	init(&(root->left->left->left), al[7]);
	init(&(root->left->left->rite), al[8]);
	init(&(root->left->rite->left), al[9]);
	init(&(root->left->rite->rite), al[10]);
	init(&(root->rite->left->left), al[11]);
	init(&(root->rite->left->rite), al[12]);
	init(&(root->rite->rite->left), al[13]);
	init(&(root->rite->rite->rite), al[14]);

    return 0;
}
