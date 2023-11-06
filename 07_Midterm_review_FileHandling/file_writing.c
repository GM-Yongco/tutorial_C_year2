/*
Description     : Code that will impress u ;)
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>

#include "files.h"

int main(){
    printf("\nSTART ----------------------------------------\n");
    
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

    FILE* the_file;
    the_file = fopen("NEWTEXT.bin", "wb");
    
    fwrite(input, sizeof(student_info), 8,  the_file);

    fclose(the_file);

    printf("\nEND ------------------------------------------\n");
    return 0;
}
