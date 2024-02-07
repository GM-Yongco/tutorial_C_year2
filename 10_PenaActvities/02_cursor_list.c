// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "02_cursor_list.h"



// =======================================================================
// MAIN
// =======================================================================

int main(){
	separator("START");

	virtual_heap x;
	init(&x);

	pos HEAD_1 = null;
	HEAD_1 = alloc(&x);
	x.elements[HEAD_1].data = 22;

	insert_first(&x, &HEAD_1, 21);
	insert_first(&x, &HEAD_1, 20);
	insert_first(&x, &HEAD_1, 19);
	insert_first(&x, &HEAD_1, 18);
	insert_first(&x, &HEAD_1, 17);
	display_list(&x, HEAD_1);

	delete_first(&x, &HEAD_1);
	display_list(&x, HEAD_1);
	insert_first(&x, &HEAD_1, 17);
	display_list(&x, HEAD_1);

	display_vh(&x);

	delete_end(&x, &HEAD_1);
	display_list(&x, HEAD_1);
	insert_first(&x, &HEAD_1, 17);
	display_list(&x, HEAD_1);

	display_pos(&x, HEAD_1, 2);
	display_pos(&x, HEAD_1, 1);
	display_pos(&x, HEAD_1, 0);
	display_pos(&x, HEAD_1, 5);

	
	display_vh(&x);
	delete_pos(&x, &HEAD_1, 2);
	display_vh(&x);

	
	delete_first(&x, &HEAD_1);
	delete_first(&x, &HEAD_1);
	display_list(&x, HEAD_1);
	insert_end(&x, &HEAD_1, 30);
	display_list(&x, HEAD_1);

	insert_pos(&x, &HEAD_1, 30, 0);
	display_list(&x, HEAD_1);
	

	separator("END");
	return 0;
}
