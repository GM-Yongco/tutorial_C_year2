/*
Description     : Code that will impress u ;D
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum{FALSE, TRUE}Boolean;

// DATA =========================

typedef struct{
	char FN[24], LN[16], MI;
}full_name;

typedef struct{
	full_name N;
	unsigned long idNumber;
	char course[5];
}student_info;

// LINKED LIST ==================

typedef struct node{
	student_info S;
	struct node *next;
}node, *p_node;

// DICTIONARY DEFINITION ========

#define SIZE 26
typedef p_node Dictionary[SIZE];



// ============================================================
// MISC FUNCTIONS
// ============================================================
void seprator(char x[]){
	printf("\n============================================================\n");
	printf(" %s", x);
	printf("\n============================================================\n");
}

// my hash is base on the first letter of the last name
int hash(char c){
	return (c - 'A') % 26 ;
}
void innit_dict(Dictionary D){
	int i;
	for(int i = 0; i<SIZE; i++){
		D[i] = NULL;
	}
}
p_node innit_node(student_info new_info){
	p_node new_node = (p_node)malloc(sizeof(node));
	new_node->S = new_info;
	new_node->next = NULL;

	return new_node;
}
Boolean isMember(Dictionary D, student_info S){
	//looks for id number if it exists in the list
	Boolean retval = FALSE;
	
	int h = hash(S.N.LN[0]);
	
	p_node trav;
	for(trav = D[h]; trav->next != NULL && retval == FALSE; trav = trav->next){
		if(trav->S.idNumber == S.idNumber){
			retval = TRUE;
		}
	}

	return retval;
}

// ============================================================
// CORE FUNCTIONS
// ============================================================

void display(Dictionary D){
	seprator("");

	int i;
	for(i = 0; i<SIZE; i++){
		printf("%d\n", i);

		p_node trav;
		for(trav = D[i]; trav != NULL; trav = trav->next){
			printf("\t%-10s %c. %-1s\n\t\t%s\n\t\t%d\n", 
				trav->S.N.FN, 
				trav->S.N.MI, 
				trav->S.N.LN,
				trav->S.course,
				trav->S.idNumber
				);
		}
		printf("\t\tNULL\n");
	}
}

void delete_student(Dictionary D, student_info S){
	
	int h = hash(S.N.LN[0]);

	Boolean found = FALSE;
	p_node* trav;
	for(trav = &D[h]; *trav != NULL && found == FALSE; trav = &(*trav)->next ){
		if((*trav)->S.idNumber == S.idNumber){
			found = TRUE;
			*trav = (*trav)->next;
		}
	}
	if(!found){
		printf("student info is not found");	
	}
}

void insert(Dictionary D, student_info S){
	int h = hash(S.N.LN[0]);

	if(D[h] == NULL){
		D[h] = innit_node(S);
		printf("it went in");
	}else{
		p_node *trav, temp;

		// regular ol link list insert sorted in alphabetical order
		for (trav = &(D[h]); 
			(*trav)->next != NULL
			&& strcmp((*trav)->S.N.LN, S.N.LN);
			trav = &(*trav)->next){}

		temp = innit_node(S);
		temp->next = (*trav)->next;
		(*trav)->next = temp;
	}
}