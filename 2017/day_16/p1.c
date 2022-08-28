#include "../../aoc.h"

void spin(char *str, int n)
{
	int i;
	int x;
	char c;

	i = 0;
	while (i < n)
	{
		x = 14;
		c = str[15];
		while (x >= 0)
		{
			str[x + 1] = str[x];
			x--;
		}
		str[0] = c;
		i++;
	}
}

void partner(char *str, char a, char b)
{
	char *x;
	char *y;
	char c;

	x = strchr(str, a);
	y = strchr(str, b);

	c = x[0];
	x[0] = y[0];
	y[0] = c;
}

void exchange(char *str, int a, int b)
{
	char c;

	c = str[a];
	str[a] = str[b];
	str[b] = c;
}

int	main()
{
	int i;
	int x;
	int y;
	int tmp;
	int len;
	char *programs;
	char **input;

	programs = strdup("abcdefghijklmnop");
	len = fetch_input("input", &input, ",");

	i = 0;
	while (i < len)
	{
		if (input[i][0] == 'x')
		{
			tmp = extract_num(input[i], &x);
			extract_num(input[i] + tmp, &y);
			exchange(programs, x, y);
		}
		else if (input[i][0] == 's')
		{
			extract_num(input[i], &x);
			spin(programs, x);
		}
		else
		{
			partner(programs, input[i][1], input[i][3]);
		}
		i++;
	}
	printf("Solution : %s\n", programs);
}
