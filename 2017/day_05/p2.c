#include "../../aoc.h"

int main()
{
	_Node	*input;
	size_t	steps;
	size_t	i;
	size_t	len;
	int		current;
	int		*instructions;

	input = fetch_by_word("input","\n", 1, &len);

	i = 0;
	instructions = malloc(len * sizeof(int));
	while (input != NULL)
	{
		instructions[i] = atoi(input->data);
		input = input->next;
		i++;
	}
	i = 0;
	steps = 0;
	int n = 0;
	while (i < len && i >= 0)
	{
		current = instructions[i];
		(current >= 3) ? (instructions[i]--) : (instructions[i]++);
		i += current;
		// printf("%d %d %d\n", i, current, instructions[current]);
		steps++;
	}

	printf("%zu\n", steps);
}
