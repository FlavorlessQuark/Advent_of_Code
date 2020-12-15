#include "../../aoc.h"


int	main()
{
	int		mask;
	int		len;
	int		maximum;
	int		minimum;
	int		total;
	int		expected;
	int		id;
	int		i;
	char	**input;

	i = 0;
	expected = 0;
	maximum = 0;
	minimum = 919;
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
		expected += id;
		maximum = MAX(maximum, id);
		minimum = MIN(minimum, id);
		i++;
	}

	total = 0;
	i = minimum;
	while (i <= maximum)
	{
		total += i;
		i++;
	}
	printf("Solution : %d\n", total - expected);
}

