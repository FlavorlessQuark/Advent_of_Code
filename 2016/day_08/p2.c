#include "../aoc.h"

void rect(int h, int w, char **str)
{
	int i;

	w--;
	while (w >= 0)
	{
		i  = 0;
		while (i < h)
		{
			str[w][i] = '#';
			i++;
		}
		w--;
	}
}

void rotate_row(int shift, char **str, int col)
{
	char c, tmp;
	int i;

	while (shift > 0)
	{
		i = 0;
		c = str[col][strlen(str[col]) - 1];
		while (str[col][i])
		{
			tmp = str[col][i];
			str[col][i] = c;
			c = tmp;
			i++;
		}
		shift--;
	}
}

void rotate_col(int shift, char **str, int row, int len)
{
	char c, tmp;
	int i;

	while (shift > 0)
	{
		i = 0;
		c = str[len - 1][row];
		while (i < len)
		{
			tmp = str[i][row];
			str[i][row] = c;
			c = tmp;
			i++;
		}
		shift--;
	}
}

void print(char **str)
{
	int i ,n, len;

	i = 0;
	len = 0;
	putchar('\n');
	while (i < 6)
	{
		n = 0;
		while (n <  50)
		{
			if (str[i][n] == '#')
				len++;
			n++;
		}
		printf("%s\n", str[i]);
		i++;
	}
}

int main()
{
	char **grid;
	char *str;
	size_t len;
	_File file;

	file = fetch_file("input", 1);

	grid = malloc(sizeof(char *)  * 6);

	len = 0;
	while (len < 6)
	{
		grid[len] = malloc(50);
		memset(grid[len], '.', 50);
		len++;
	}
	str = strtok((char *)file.content, "\n");

	int n  = 0;
	while (str != NULL)
	{
		if (strspn(str, ABC_L) == 4)
			rect(atoi(str + 5), atoi(strchr(str, 'x') + 1), grid);
		else
		{
			if (str[7] == 'r')
				rotate_row(atoi(strstr(str, "by") + 3), grid, atoi(str + strcspn(str, NUMS)));
			else
				rotate_col(atoi(strstr(str, "by") + 3), grid, atoi(str + strcspn(str, NUMS)), 6);
		}
		str = strtok(NULL,"\n");
		n++;
	}
	print(grid);
}
