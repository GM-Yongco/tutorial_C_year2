/*
Description     : Code that will impress u ;D
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct LIST{
	int* data;
	int count;
}LIST, *pLIST;

void initialize(pLIST* ppL){
	*ppL = (pLIST)malloc(sizeof(LIST));
	(*ppL)->data = (int*)malloc(sizeof(int)*MAX);
	(*ppL)->count = 0;
}
void test(pLIST pL){
	
	*((pL->data)+ 0) = 25;	
	*((pL->data)+ 1) = 356;	
	*((pL->data)+ 2) = 278;	
	*((pL->data)+ 3) = 89;	
	*((pL->data)+ 4) = 265;
	
	pL->count = 5;
}

int retrieve_pos(pLIST L, int index){
	if(index >= 0 && index < L->count){
		printf("%d\n", *(L->data + index));
		return 1;
	}else{
		return -1;
	}
}
void retrive_all(pLIST pL){
	int i = 0;
	while(i < pL->count){
		printf("%d", *((pL->data) + i));
		if(i< ((pL->count)-1)){
			printf(",");
		}
		i++;
	}
	printf("\n");
}

void insert_pos(pLIST pL, int index, int data){
	if(index < 0 || pL->count >= MAX || index >= MAX-1){
	}else if(index > pL->count){
		//basically puts it in the next empty slot in the list
		index = pL->count;
	}else if(index < MAX-2 && index < pL->count){
		int* source = (pL->data) + index;
		int* destination = (pL->data) + index + 1;
		int size = sizeof(int)*(pL->count - index);
		
		memcpy(destination, source, size);
	}
	
	*((pL->data)+index) = data;
	pL->count += 1;
}

void delete_pos(pLIST pL, int index){
	if(index >= MAX || index < 0 || index >= pL->count){}
	else{
		if(index < pL->count -1){
			int* source = (pL->data) + index + 1;
			int* destination = (pL->data) + index;
			int size = sizeof(int)*(pL->count - index);	
			memcpy(destination, source, size);
		}
		pL->count -= 1;
	}
}

void update_pos(pLIST pL, int index, int data){
	
	if(index < pL->count && index > -1){	
		*(pL->data + index) = data;	
	}else{
		printf("invalid index: %d\n", index);
	}
}
