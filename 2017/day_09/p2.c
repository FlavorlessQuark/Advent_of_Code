# include "../../aoc.h"

int garbage(char *str, int *count)
{
	int i;

	i = 1;
	while (str[i] != '>')
	{
		// printf("%c", str[i]);
		if (str[i] == '!')
			i++;
		else
			*count += 1;
		i++;
	}
	return i;
}

int main()
{
	_File	file;
	size_t	i;
	int		total;
	int		score;

	file = fetch_file("input", 0);
	i = 0;
	total = 0;
	while (file.content[i])
	{

		if (file.content[i] == '<')
			i += garbage(file.content + i, &total);
		i++;
	}
	printf("Solution : %d\n", total);
}
