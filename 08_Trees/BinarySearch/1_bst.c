// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "1.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){
	separator("START");

	int SET_A[] = {10, 5, 14, 12, 7, 18, 15};

	p_tree_node root = NULL;

	int i;
	for(i = 0; i < 4; i++){
		// add_to_tree(&root, SET_A[i]);
		add_to_tree_2(&root, SET_A[i]);
	}

	printf("%d\n", root->data);
	printf("%d\n", root->left->data);
	printf("%d\n", root->right->data);
	printf("%d\n", root->right->left->data);
	
	separator("END");
	return 0;
}
