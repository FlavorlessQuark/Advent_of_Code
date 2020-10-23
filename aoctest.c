#include "aoc.h"

int main()
{
	char a[] = {"abcde"};
	int b[] = {0,1,2,3};
	bool c[] = {true,false,true,true};
	_Node *node;

	node = new_node();
	node->data = "Hello, World!";
	// swap(&a, &b);
	_DEBUG_("This works");
	_PRINT_1D(a,4);
	_PRINT_1D(b,4);
	_PRINT_1D(c,4);
	_PRINT_1D(node, 0);
	// printf("SWAP TEST: a %c b %c\n", a, b);


}
