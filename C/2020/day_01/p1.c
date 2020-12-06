#include "../../aoc.h"


int	main()
{
	int		i;
	int		*num;
	char	**input;

	i = fetch_input("input", &input, "\n");

	MAP(input, atoi, i, num);

	for(int n = 0; n < i; n++)
		FOREACH(ITER < i, if (num[ITER] +num[n] == 2020){printf("%d\n", num[ITER] * num[n]);return 1;})
}
