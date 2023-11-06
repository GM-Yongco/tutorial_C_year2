/*
Description     : Code that will impress u ;)
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>

#include "Hashing_Open.h"

int main(){
    printf("\n--------------------START--------------------\n");
    
    full_name jules = {"Jules", "Young", 'M'};

    printf("%d", hash(jules.LN[0]));

    printf("\n%-20sx", "u suck");

    seprator("");

    Dictionary A;
	innit_dict(A);
	student_info P[] = {
					{{"Robert Michael","Albo",'L'}, 151011374, "BSCS"},
					{{"Samantha","A", 'L'}, 131001503, "BSCS"},
					{{"Samantha","Ab", 'L'}, 131001502, "BSCS"},
					{{"Marvin Gwapo","Lja", 'L'}, 151011381, "BSCS"},
					{{"Samanth","Aa", 'L'}, 131001505, "BSCS"}
				};		

    int i;
    for(i = 0; i<(sizeof(P)/sizeof(student_info)); i++){
        printf("%d", i);
    	insert(A, P[i]);
    }
	
	display(A);
    
    student_info compare = {
        {"Robert Michael","Albo",'L'}, 131001502, "BSCS"
    };

    if(isMember(A, compare)){
        printf("is member :DDD");
    }

    delete_student(A, compare);
    display(A);


    printf("\n---------------------END---------------------\n");
    return 0;
}
