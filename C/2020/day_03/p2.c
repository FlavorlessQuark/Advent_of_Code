#include "../../aoc.h"


int	main()
{
	int i;
	int n;
	int len;
	int count;
	long total;
	int linelen;
	int checks[5][2] = {{1, 1}, {3,1}, {5, 1}, {7, 1}, {1, 2}};
	char **input;

	count = 0;
	total = 1;
	len = fetch_input("input", &input, "\n");
	linelen = strlen(input[0]);

	for (int x = 0; x < 5; x++)
	{
		count = 0;
		i = 0;
		n = 0;
		while(i < len)
		{
			if (n >= linelen)
				n -= linelen;
			if (input[i][n] == '#')
				count++;
			n += checks[x][0];
			i += checks[x][1];
		}
		total *= count;
	}
	printf("Solution : %ld\n",total);

}
