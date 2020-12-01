# include "../../aoc.h"

int garbage(char *str)
{
	int i;

	i = 0;
	while (str[i] != '>')
	{
		if (str[i] == '!')
			i++;
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
	score = 0;
	while (file.content[i])
	{

		if (file.content[i] == '<')
			i += garbage(file.content + i);
		if (file.content[i] == '{')
			score++;
		if (file.content[i] == '}')
		{
			total += score;
			score--;
		}
		i++;
	}
	printf("Solution : %d\n", total);
}
