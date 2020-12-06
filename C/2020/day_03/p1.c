#include "../../aoc.h"


int	main()
{
	int i;
	int n;
	int len;
	int count;
	int linelen;
	char **input;

	i = 0;
	n = 0;
	count = 0;
	len = fetch_input("input", &input, "\n");
	linelen = strlen(input[0]);

	while(i < len)
	{
		if (n >= linelen)
			n -= linelen;
		if (input[i][n] == '#')
			count++;
		n += 3;
		i++;
	}
	
	printf("Solution : %d\n", count);
}
