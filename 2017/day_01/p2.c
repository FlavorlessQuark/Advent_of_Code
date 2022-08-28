#include "../../aoc.h"

int main()
{
	_File	file;
	int		total;
	size_t	i, len, index;

	i = 0;
	total = 0;
	file = fetch_file("input", 1);
	len = strlen(file.content);
	while (file.content[i] != '\0')
	{
		((i + len / 2) >= len) ? (index = len / 2 - (len - i)) : (index = i + len /2);
		if (file.content[i] == file.content[index])
			total += (int)(file.content[index] - 48);
		i++;
	}
	printf("Solution : %d\n", total);
}
