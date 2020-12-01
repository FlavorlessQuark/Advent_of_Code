#include "../aoc.h"

int main()
{
	_File	file;
	char	*str;
	int		i;
	int		total;
	int		dup;

	i = 0;
	total = 0;
	file = fetch_file("input", 1);
	while (file.content[i] != '\0')
	{
		if (file.content[i] == '(')
		{
			dup = (atoi(file.content + i + 1) * atoi(file.content + (strcspn(file.content + i, "x") + i + 1)));
			i += strcspn(file.content + i, ")") + atoi(file.content + i + 1);
			total += dup;
		}
		else
			total++;
		i++;
	}
	printf("%d\n", total);
}
