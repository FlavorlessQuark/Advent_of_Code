#include "../aoc.h"

size_t expand(char *str, size_t span)
{
	int		i;
	int		len;
	int		mult;
	size_t	total;

	i = 0;
	total = 0;
	while (str[i] && i < span)
	{
		if (str[i] == '(')
		{
			i += extract_num(str + i, &len);
			i += extract_num(str + i, &mult) + 1;
			total += (expand(str + i, len) * mult);
			i += len - 1;
		}
		else
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
