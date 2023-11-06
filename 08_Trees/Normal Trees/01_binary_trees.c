// ==========================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// Description     : Actually just me playing around
// ==========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "01_binary_trees.h"

int main(){
	printf("\n START -------------------------------------------\n");
	
	char* al = alphabet_array();

	// ===================================================================
	// INIT

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
	
	// ===================================================================
	// DISPLAY

	display_all_1(root);

	section("DISPLAY MANUAL");

	display_node_1(bin_trav(root, 0b0, 0));
	display_node_1(bin_trav(root, 0b0, 1));
	display_node_1(bin_trav(root, 0b1, 1));
	display_node_1(bin_trav(root, 0b00, 2));
	display_node_1(bin_trav(root, 0b01, 2));
	display_node_1(bin_trav(root, 0b10, 2));
	display_node_1(bin_trav(root, 0b11, 2));

	// see screnshot for referece
	section("DISPLAY LAYER");

	display_layer(root, 0);
	printf("\n");
	display_layer(root, 3);

	section("DISPLAY ALL");

	display_all_2(root, 4);

	printf("\n END ---------------------------------------------\n");
	return 0;
}
