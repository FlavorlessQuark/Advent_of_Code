#include "../aoc.h"


int main()
{
	_Node *input;
	int total;
	int x, y, z;
	int i;

	total = 0;
	input = fetch_by_word("input", "\n",1, &i);
	while (input != NULL)
	{
		input->data += extract_num(input->data, &x);
		input->data += extract_num(input->data, &y);
		extract_num(input->data, &z);
		((x + z) > y && (y + z) > x && (x + y) > z) ? (total += 1) : (NULL);
	}
	printf("%d\n", total);
}
