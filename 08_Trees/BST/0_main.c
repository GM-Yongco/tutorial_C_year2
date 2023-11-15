// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "1_core.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){
	separator("START");

	p_node root = NULL;

	rec_insert(&root, 4);
	rec_insert(&root, 2);
	rec_insert(&root, 3);
	rec_insert(&root, 1);
	rec_insert(&root, 6);
	rec_insert(&root, 5);
	rec_insert(&root, 7);

	separator("printing tree");

	rec_trav_inorder(root);

	printf("\n");

	separator("is_member test");

	int i;
	for(i = 0; i<10; i++){
		if(is_member(root, i)){
			printf("%d is a member", i);
		}else{
			printf("%d, is not a member", i);
		}
		printf("\n\n");
	}


	error_in("main");
	
	separator("END");
	return 0;
}
