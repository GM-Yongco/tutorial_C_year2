// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "02_bt.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){
    section("START");

    // INITIALIZATION

    char* al = alphabet_array();
    
    b_tree_p root = NULL;
	init(&root, al[0]);

	init(&(root->left), al[1]);
	init(&(root->rite), al[2]);
	
	init(&(root->left->left), al[3]);    
	init(&(root->left->rite), al[4]);
	init(&(root->rite->left), al[5]);
	init(&(root->rite->rite), al[6]);

	init(&(root->left->left->left), al[7]);
	init(&(root->left->left->rite), al[8]);
	init(&(root->left->rite->left), al[9]);
	init(&(root->left->rite->rite), al[10]);
	init(&(root->rite->left->left), al[11]);
	init(&(root->rite->left->rite), al[12]);
	init(&(root->rite->rite->left), al[13]);
	init(&(root->rite->rite->rite), al[14]);

    // DISPLAY
    section("DISPLAY");

    section("post");
    post_order(root);
    
    section("pre");
    pre_order(root);
    
    section("in");
    in_order(root);

    section("END");
    return 0;
}
