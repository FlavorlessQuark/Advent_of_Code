#include "../aoc.h"

int eval_chunk(char *str, int len)
{
	size_t i;
	char c;

	c = str[0];
	i = 1;
	while (i < len)
	{
		if (str[i] != c)
			c = str[i];
		else
		{
			if (i + 1 == len)
				return 0;
			if (i > 1 && str[i - 2] == str[i + 1] && str[i + 1] != c)
				return 1;
		}
		i++;
	}
	return 0;
}

int calc_chunk(char *str)
{
	int len;
	int eval;
	int chunk;

	len = 1;
	eval = 0;
	chunk = 0;
	while ((len = strspn(str,ABC_L)) != 0)
	{
		chunk++;
		if ((eval = eval_chunk(str, len)) && chunk %  2== 0)
			return 0;
		if (len == strlen(str))
			return eval;
		str += len + 1;
	}
	chunk++;
	len = strlen(str);
	eval = eval_chunk(str, len);
	return eval;
}

int main()
{
	_File file;
	int total;
	char *str;

	file = fetch_file("input", 1);
	str = strtok(file.content, "\n");
	total = 0;
	while (str != NULL)
	{
		total += calc_chunk(str);
		str = strtok(NULL, "\n");
	}
	printf("%d\n",total);
}
