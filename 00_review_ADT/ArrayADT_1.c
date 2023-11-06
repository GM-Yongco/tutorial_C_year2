/*
Description     : Code that will impress u ;)
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>

#include "ArrayADT_1.h"

int main(){
    printf("\n--------------------START--------------------\n");
    
    LIST L;
    LIST* M = &L;
    
    initialize(M);
    
    test(M);
    
    retrive_all(L);
    insert_pos(M, 3, 6);
    retrive_all(L);
    delete_pos(M, 2);
    retrive_all(L);
    retrieve_pos(L, 3);
    
    update_pos(M, 1, 69);
    update_pos(M, 9, 69);
    retrive_all(L);
    
    printf("\n---------------------END---------------------\n");
    return 0;
}
