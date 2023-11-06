/*
Description     : Code that will impress u ;)
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>

#include "ArrayADT_2.h"

int main(){
    printf("\n--------------------START--------------------\n");
    
    pLIST L;
    
    initialize(&L);
    test(L);
    
    retrive_all(L);
    
    insert_pos(L, 3, 6);
    retrive_all(L);
    delete_pos(L, 2);
    retrive_all(L);
    retrieve_pos(L, 3);
    
    update_pos(L, 1, 69);
    update_pos(L, 9, 69);
    retrive_all(L);
    
    printf("\n---------------------END---------------------\n");
    return 0;
}
