/*
Description     : Code that will impress u ;)
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>

#include "closed_hashing.h"

int main(){
    printf("\nSTART----------------------------------------\n");
    
    Dictionary A;
    initialize(A);
    display(A);

    student_info input[] = {
        {19106001, 1, "Robert", "LIM", 'X'},
        {19104001, 1, "Robert", "LIM", 'X'},
        {19104002, 2, "Alice", "SMITH", 'Y'},
        {19104006, 3, "John", "DOE", 'Z'},
        {19105002, 2, "Emily", "WILLIAMS", 'A'},
        {19105004, 4, "Michael", "JOHNSON", 'B'},
        {19105003, 3, "Sophia", "BROWN", 'C'},
        {19105003, 3, "Sophia", "BROWN", 'C'},
        {19105001, 1, "William", "JONES", 'D'}
    };

    int i;
    for(i = 0; i < (sizeof(input)/sizeof(student_info)); i++){
        insert(A, input[i]);
    }
    display(A);

    student_info del = {19104006, 3, "John", "DOE", 'Z'};
    delete(A, del);
    display(A);

    student_info mem = {19105003, 3, "Sophia", "BROWN", 'C'};
    printf("%d", is_member(A, mem));
    
    printf("\nEND------------------------------------------\n");
    return 0;
}
