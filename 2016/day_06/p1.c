# include "../aoc.h"


int main()
{
	_File	file;
	int		columns;
	int		i;
	int		max;

	int		*letters[8];
	char	*str;
	char	*final;

	i = 0;
	file = fetch_file("input", 1);
	str = strtok((char *)(file.content), "\n");

	columns = 8;
	while (i < columns)
	{
		letters[i] = calloc(sizeof(int), 26);
		i++;
	}
	while (str != NULL)
	{
		i = 0;
		while (i < columns)
		{
			letters[i][((int)str[i]) - 97] += 1;
			i++;
		}
		str = strtok(NULL, "\n");
	}

	final = calloc(columns, 1);
	columns--;
	while (columns >= 0)
	{
		i = 0;
		max = 0;
		while (i < 26)
		{
			(letters[columns][i] > letters[columns][max]) ? (max = i) : (max +=0);
			i++;
		}
		final[columns] = (char)(max + 97);
		columns--;
	}
	printf("str %s----------\n", final);
}
