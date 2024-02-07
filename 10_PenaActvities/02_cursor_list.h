// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <string.h>

#define MAX 5
#define null -1

typedef enum{TRUE, FALSE}BOOL;

typedef int pos;
typedef struct{
	int data;
	pos link;
}node_type;
typedef struct{
	node_type elements[MAX];
	pos avail;
}virtual_heap;

// =======================================================================
// MISC FUNCTIONS
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

// =======================================================================
// CORE FUNCTIONS 1
// =======================================================================

void init(virtual_heap* vh){
	int x;
	for(x = 0; x < MAX-1; x++){
		vh->elements[x].link = x+1;
	}
	vh->elements[x].link = null;
	vh->avail = 0;
}

BOOL is_valid_pos(pos x){
	return (x>=0 && x<MAX)?(TRUE):(FALSE);
} 

pos alloc(virtual_heap* vh){
	pos temp = null;

	if(vh->avail != null){
		temp = vh->avail;
		vh->avail = vh->elements[temp].link;
		vh->elements[temp].link = null;
	}else{
		printf("failed to allocate: virtual heap is full\n");
	}

	return temp;
}

void de_alloc(virtual_heap* vh, pos to_free){
	if(is_valid_pos(to_free) == FALSE){
		printf("invalid position\n");
	}else{
		vh->elements[to_free].link = vh->avail;
		vh->avail = to_free;
	}
}

// =======================================================================
// CORE FUNCTIONS 2
// =======================================================================

void delete_first(virtual_heap* vh, pos* head){
	if(is_valid_pos(*head) == FALSE){
		printf("invalid position\n");
	}else{
		pos temp = *head;
		*head = vh->elements[*head].link;
		de_alloc(vh, temp);
	}
}

void delete_end(virtual_heap* vh, pos* head){
	if(is_valid_pos(*head) == FALSE){
		printf("invalid position\n");
	}else{
		pos* trav;
		for(trav = head; 
			vh->elements[*trav].link != null; 
			trav = &(vh->elements[*trav].link)){}
		de_alloc(vh, *trav);
		*trav = null;
	}
}

void delete_pos(virtual_heap* vh, pos* head, int list_no){
	int x;
	if(is_valid_pos(*head) == FALSE){
		printf("invalid position\n");
	}else{
		pos* trav = head;
		for(x = 0; x<list_no && vh->elements[*trav].link != null; x++){
			trav = &(vh->elements[*trav].link);
		}
		if(x == list_no){
			pos temp = *trav;
			*trav = vh->elements[*trav].link;
			de_alloc(vh, temp);
		}else{
			printf("out of bounds\n");
		}
	}
}

// =======================================================================
// CORE FUNCTIONS 3
// =======================================================================

void insert_first(virtual_heap* vh, pos* head, int new_data){
	if(is_valid_pos(*head) == FALSE){
		printf("invalid position\n");
	}else{
		pos temp = alloc(vh);
		if(temp != null){
			vh->elements[temp].data = new_data;
			vh->elements[temp].link = *head;
			*head = temp;
		}
	}
}
void insert_end(virtual_heap* vh, pos* head, int new_data){
	if(is_valid_pos(*head) == FALSE){
		printf("invalid position\n");
	}else{
		pos* trav;
		for(trav = head; *trav != null; trav = &(vh->elements[*trav].link)){}
		pos temp = alloc(vh);
		if(temp != null){
			vh->elements[temp].data = new_data;
			vh->elements[temp].link = null;
			*trav = temp;
		}
	}
}
void insert_pos(virtual_heap* vh, pos* head, int new_data, pos list_num){
	if(is_valid_pos(*head) == FALSE || is_valid_pos(list_num) == FALSE ){
		printf("invalid position\n");
	}else{
		int x;
		pos* trav;
		for(trav = head, x = 0; 
			*trav != null, x < list_num; 
			trav = &(vh->elements[*trav].link), x++ ){}

		pos temp = alloc(vh);
		if(temp != null && x == list_num){
			vh->elements[temp].data = new_data;
			vh->elements[temp].link = *trav;
			*trav = temp;
		}else{
			printf("out of bounds");
		}
	}
}
// =======================================================================
// CORE FUNCTIONS 2
// =======================================================================
void display_vh(virtual_heap* vh){
	// function uses *vh 
	// so that it doenst have to copy the entire virtual heap
	// which would be inefficient
	separator("Displaying virtual heap");
	printf("avail: %d\n\n", vh->avail);

	int x;
	for(x = 0; x<MAX; x++){
		printf("%d [%d, %d]\n", x, vh->elements[x].data, vh->elements[x].link);
	}
}
void display_list(virtual_heap* vh, pos head){
	if(is_valid_pos(head) == FALSE){
		printf("invalid position\n");
	}else{
		separator("Displaying list");
		pos trav = head;
		while(trav != null){
			printf("%d\n", vh->elements[trav].data);
			trav = vh->elements[trav].link;
		}
	}
}
void display_pos(virtual_heap* vh, pos head, int list_no){
	if(is_valid_pos(head) == FALSE){
		printf("invalid position\n");
	}else{
		separator("Displaying list_pos");
		int x;
		pos trav = head;
			for(x = 0; x<list_no && trav != null; x++){
			trav = vh->elements[trav].link;
		}
		(trav == null || list_no < 0)?(printf("out of bounds\n")):printf("%d", vh->elements[trav].data);
	}
}



