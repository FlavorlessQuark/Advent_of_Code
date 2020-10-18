# include "../aoc.h"

char is_safe(int x, int y, char** traps, int *count)
{
	int r, m, l;
	int total;

	(x - 1 == -1 || traps[x - 1][y] == '.') ? (r = 0) : (r = 1);
	(x + 1 == 100 || traps[x + 1][y] == '.') ? (l = 0) : (l = 1);
	(traps[x][y] == '.') ? (m = 0) : (m = 1);

	total = r + m + l;
	if ((total == 1 && m == 1) || (total == 2 && m == 0) || total == 3 || total == 0)
	{
		*count += 1;
		return '.';
	}
	return '^';
}

int main()
{
	_File file;
	char **traps;
	int i,n, count, rows = 40;

	file = fetch_file("test", 1);
	traps = malloc(strlen(file.content) * sizeof(char *));

	i = 0;
	n = 0;
	count = 0;
	while (file.content[i])
	{
		traps[i] = malloc(rows);
		traps[i][0] = file.content[i];
		i++;
	}

	n = 1;
	printf("%s\n", file.content);
	while (n < rows)
	{
		i = 0;
		while (i < 100)
		{
			traps[i][n] = is_safe(i, n - 1, traps, &count);
			printf("%c", traps[i][n]);
			i++;
		}
		printf("\n");
		n++;
	}
	printf("%d\n", count + 47);
}
