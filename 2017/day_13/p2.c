#include "../../aoc.h"

int main()
{
	_Node *input;
	_Node *head;
	size_t len;
	int depth;
	int range;
	int severity;

	input = fetch_by_word("input", "\n", 1, &len);

	head = input;
	depth = 0;
	severity = 0;
	len = 0;
	while (1)
	{
		input = head;
		severity = 0;
		while (input != NULL)
		{

			extract_num(input->data + extract_num(input->data, &depth), &range);
			// printf("TURN : [ %d ], depth %d, range %d", len, depth + len, range);
			// printf("'| Mode %d\n\n'", (depth + len) % (range * 2 - 2));
			if ((depth + len) % (range * 2 - 2) == 0)
			{
				severity++;
				break ;
			}
			input = input->next;
		}
		// printf("---------------\n");
		if (severity == 0)
			break;
		len++;
	}
	printf("Solution : %zu\n", len);
}
