#include "../../aoc.h"


int	main()
{
	int num;
	int val;
	int zero;
	int i;
	char **input;

	fetch_input("input", &input, "\n");
	extract_num(input[0], &num);

	i = 1;
	val = 0;
	while (i < 50000000)
	{
		if ((val = (val + 1 + num) % i) == 0)
			zero = i;
		i++;
	}
	printf("Solution : %d\n", zero);
}
