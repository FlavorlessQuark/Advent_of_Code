#include "../../aoc.h"


int	main()
{
	int i;
	int x;
	int y;
	int count;
	int total;
	char **input;
	char search[1];

	total = 0;
	i = fetch_input("input", &input, "\n");
	for (size_t n = 0; n < i; n++)
	{
		input[n] += extract_num(input[n], &x) + 1;
		input[n] += extract_num(input[n], &y) + 1;
		search[0] = input[n][0];
		input[n] += 3;
		if (input[n][x - 1] != input[n][y - 1] && (input[n][x - 1] == search[0]
			|| input[n][y - 1] == search[0]))
			total++;
	}
	printf("Solution : %d\n", total);
}
