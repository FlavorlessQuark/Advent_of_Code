#include "../../aoc.h"


int	main()
{
	int		mask;
	int		len;
	int		maximum;
	int		id;
	int		i;
	char	**input;

	i = 0;
	maximum = 0;
	len = fetch_input("input", &input, "\n");
	while (i < len)
	{
		mask = 1;
		id = 0;
		for (int n = 9; n >= 0; n--)
		{
			if (input[i][n] == 'B' || input[i][n] == 'R')
				id |= mask;
			mask <<= 1;
		}
		maximum = MAX(maximum, id);
		i++;
	}
	printf("Solution : %d\n", maximum);
}
