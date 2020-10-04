# include "../aoc.h"


int main()
{
	_File file;
	int columns, i, max;
	char *str, *final;
	int **letters;

	file = fetch_file("test", 1);

	str = strtok((char *)(file.content), "\n");
	columns = strlen(str);


	letters = malloc(columns * (sizeof(int)));

	i = 0;

	while (i < columns)
	{
		letters[i] = calloc(26, (sizeof(int)));
		i++;
	}
	while (str != NULL)
	{
		i = 0;
		while (i < columns)
		{
			letters[i][((int)str[i])] += 1;
			// printf("HERE\n");
		// // printf("Final col %c\n", (char)max);
			i++;
		}
		str = strtok(NULL, "\n");
	}
		// printf("str %s----------\n", str);

	final = calloc(columns, 1);
	columns--;
	while (columns >= 0)
	{
		max = 0;
		i = 0;
		while (i < 26)
		{
			(letters[columns][i] > letters[columns][max]) ? (max = i) : (max +=0);
			// printf("here\n");
			i++;
		}
		final[columns] = (char)(max + 97);
		columns--;
	}
}
