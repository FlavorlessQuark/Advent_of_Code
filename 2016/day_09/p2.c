#include "../aoc.h"

size_t expand(char *str, size_t span)
{
	int len, mult;
	size_t total;
	int i;

	total = 0;
	i = 0;
	mult = 0; //Not sure this is necessary ?
	len = 0; //Something to test in the void_sandbox I guess
	while (str[i] && i < span)
	{
		if (str[i] == '(')
		{
			i += extract_num(str + i, &len);
			i += extract_num(str + i, &mult) + 1;
			// printf("%c %d %d\n", str[i], len, mult);
			total += (expand(str + i, len) * mult);
			i += len - 1;
		}
		else if (str[i] != ' ')//Unsure if necessary
			total++;
		i++;
	}
	return total;
}

int main()
{
	_File	file;
	char	*str;
	size_t	total;


	file = fetch_file("input", 1);
	total = expand(file.content, strlen(file.content));

	printf("%zu\n", total);
}
