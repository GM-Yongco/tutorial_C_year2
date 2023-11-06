//==========================================================================
//Description     : Code that will impress u ;)
//Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
//Date            : ur my date uwu
//==========================================================================

#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{FALSE, TRUE}BOOLEAN;
 
typedef struct node_b_tree{
	char data;
	struct node_b_tree* left;
	struct node_b_tree* rite;
}*b_tree_p, b_tree;

// =======================================================================
// FUNCTIONS CORE 1
// =======================================================================

void init(b_tree_p* node, char new_data){
	b_tree_p new_node = (b_tree_p)malloc(sizeof(b_tree));
	new_node->left = NULL;
	new_node->rite = NULL;
	new_node->data = new_data;
	
	*node = new_node;
}

void display_node_1(b_tree_p node){
	printf("\n %c", node->data);
}

// =======================================================================
// FUNCTIONS MISC 1
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
	char* ret_val = (char*)malloc(sizeof(char)*27);
	ret_val[26] = '\0';

	char start = 'A';
	int x;
	for(x = 0; x<26; x++){
		ret_val[x] = start + x;

	}

	return ret_val;
}

void display_all_1(b_tree_p root){
	display_node_1(root);

	if(root->left != NULL){
		display_all_1(root->left);
	}	
	if(root->left != NULL){
		display_all_1(root->rite);
	}
}

// =======================================================================
// FUNCTIONS MISC 2
// =======================================================================


// just a recursive binary combination thingy
void print_combi(char* past, int len){

	char* s1 = (char*)malloc(sizeof(char) * len);
	char* s2 = (char*)malloc(sizeof(char) * len);
	strcpy(s1, past);
	strcpy(s2, past);
	strcat(s1, "0");
	strcat(s2, "1");

	if(len>1){
		print_combi(s1, len-1);
		print_combi(s2, len-1);
	}else{
		printf("%s", s1);
		printf("\n");
		printf("%s", s2);
		printf("\n");
	}

	free(s1);
	free(s2);
}


void print_bin(int x, int len){
	//len dictates how many displayed digits

	int comp = 1 << (len - 1);

	int i;
	for(i = 0; i<len; i++){
		(x & comp)?(printf("1")):(printf("0"));
		x = x<<1;
	}
}

// =======================================================================
// FUNCTIONS CORE 2
// =======================================================================

b_tree_p bin_trav(b_tree_p root, int x, int layer){

	int comp = 1 << (layer-1);

	//I made 1 go left and 0 go right
	int i;
	for(i = 0; i<layer; i++){
		if(x & comp){
			root = root->rite;
		}else{
			root = root->left;
		}
		x = x<<1;
	}
	return root;
}

void display_layer(b_tree_p root, int layer){
	
	// GETTING THE NUMBER OF COMBINATIONS
	int combi = 1 << layer;
	int i;
	
	// DISPLAYING THE COMBINATIONS IN BINARY
	for(i = 0; i<combi; i++){
		display_node_1(bin_trav(root, i, layer));
	}
}

void display_all_2(b_tree_p root, int layer_num){
	int i;
	for(i = 0; i<layer_num; i++){
		display_layer(root, i);
	}
}