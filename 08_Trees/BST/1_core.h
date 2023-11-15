// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "0_misc.h"
// =======================================================================
// STRUCTS 1
// =======================================================================

typedef enum boolean{FALSE, TRUE}BOOLEAN;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node, *p_node;

// =======================================================================
// CORE FUNCTIONS
// =======================================================================

void initialize(p_node* x, int new_data){
	if(*x == NULL){    
		p_node temp = (p_node)malloc(sizeof(node));
		temp->data = new_data;
		temp->left = NULL;
		temp->right = NULL;
		*x = temp;
	}
}

void rec_trav_inorder(p_node root){

	if(root != NULL){	
		rec_trav_inorder(root->left);
		printf("%d\n", root->data);
		rec_trav_inorder(root->right);
	}
}

void itt_trav_inorder(){}

void rec_insert(p_node* x, int new_data){
	if(*x == NULL){
		initialize(x, new_data);
	}else if(new_data == (*x)->data){
		printf("%d already exists\n", new_data);
	}else if(new_data > (*x)->data){
		rec_insert(&((*x)->right), new_data);
	}else{
		rec_insert(&((*x)->left), new_data);
	}
} 

void itt_insert(p_node* x, int new_data){
	BOOLEAN found = FALSE;
	while(*x != NULL && found == FALSE){
		if(root->data == new_data){
			found == TRUE;		
			printf("%d already exists\n", new_data);
		}else if(new_data > (*x)->data){
			rec_insert(&((*x)->right), new_data);
		}else{
			rec_insert(&((*x)->left), new_data);
		}
	}

}

BOOLEAN is_member(p_node root, int maybe){
	BOOLEAN ret_val = FALSE;

	if(root == NULL){
		//do nothing
	}else if(root->data == maybe){
		ret_val = TRUE;

	}else if(maybe > root->data){
		ret_val = is_member(root->right, maybe);
	}else{
		ret_val = is_member(root->left, maybe);
	}

	return ret_val;
}