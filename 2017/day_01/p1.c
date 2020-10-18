#include "../../aoc.h"

int main()
{
	_File	file;
	int		total;
	size_t	i;

	i = 0;
	total = 0;
	file = fetch_file("input", 1);

	while (file.content[i + 1] != '\0')
	{
		if (file.content[i] == file.content[i + 1])
			total += (int)(file.content[i] - 48);
		i++;
	}
	if (file.content[i] == file.content[0])
		total += (int)(file.content[0] - 48);
	printf("Solution : %d\n", total);
}
