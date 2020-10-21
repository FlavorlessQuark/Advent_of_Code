#include "../../aoc.h"

int main()
{
	_Node *input;
	size_t len;
	int depth;
	int range;
	int severity;

	input = fetch_by_word("input", "\n", 1, &len);

	depth = 0;
	severity = 0;
	while (input != NULL)
	{
		extract_num(input->data + extract_num(input->data, &depth);, &range);
		if (depth % (range * 2 - 2) == 0)
			severity += (depth * range);
		input = input->next;
	}
	printf("Solution : %d\n", severity);
}
