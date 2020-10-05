# include "../aoc.h"


int main()
{
	_File file;
	int columns = 8, i, max;
	char *str, *final;
	int letters[8][26];

	file = fetch_file("input", 1);

	str = strtok((char *)(file.content), "\n");

	i = 0;
	while (i < columns)
	{
		max = 0;
		while (max < 26)
		{
			letters[i][max] = 0;
			max++;
		}
		i++;
	}

	max = 0;
	while (str != NULL)
	{
		i = 0;
		while (i < columns)
		{
			letters[i][(((int)str[i]) - 97)] = letters[i][(((int)str[i]) - 97)] += 1;
			// printf("Max %c %d  %d\n", str[i], letters[i][(((int)str[i]) - 97)], (((int)str[i]) - 97));
			i++;
		}
		str = strtok(NULL, "\n");
	}

	final = calloc(columns, 1);
	columns--;
	while (columns >= 0)
	{
		max = 0;
		i = 0;
		while (i < 26)
		{
			(letters[columns][i] > letters[columns][max]) ? (max += 0) : (max = i);
			i++;
		}
		final[columns] = (char)(max + 97);
		columns--;
	}
	printf("str %s----------\n", final);
}
