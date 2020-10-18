#include "../../aoc.h"

#define SOMENUMBER 50

int calc(int **grid, int y, int x, int input)
{
	int res;

	res = (	grid[x - 1][y + 0] +
			grid[x + 1][y + 0] +
			grid[x + 0][y - 1] +
			grid[x + 0][y + 1] +
			grid[x + 1][y + 1] +
			grid[x - 1][y + 1] +
			grid[x + 1][y - 1] +
			grid[x - 1][y - 1]);
	grid[x][y] = res;
	if (res > input)
	{
		printf("Solution : %d\n", res);
	// printf("\nres %d (%d,%d)\n", res, x, y);
	// printf("%d %d %d\n",grid[x - 1][y - 1],grid[x + 0][y - 1], grid[x + 1][y - 1] );
	// printf("%d %d %d\n",grid[x - 1][y + 0],grid[x + 0][y + 0],grid[x + 1][y - 0] );
	// printf("%d %d %d\n",
	// 		grid[x - 1][y + 1],
	// 		grid[x + 0][y + 1],
	// 		grid[x + 1][y + 1]);
	}
	return res;
}

int main()
{
	int **grid;
	int x, y, i, size;
	int input, n;

	y = (SOMENUMBER / 2);
	x = (SOMENUMBER / 2) + 1;
	grid = calloc(SOMENUMBER, sizeof(int *));

	i = 0;
	while (i < SOMENUMBER)
	{
		grid[i] = calloc(SOMENUMBER, sizeof(int));
		i++;
	}
	grid[SOMENUMBER / 2][SOMENUMBER / 2] = 1;
	//Rrefactor note :
	//Repetitive stuff here, must be a way to switch from x to y and reduce this to a single while loop
	// y is actually x >.> hehe surprise

	i = 0;
	n = 1;
	size = 2;
	input = 347991;
	while (42)
	{
		//Backwards because too much offset shenanigans


		while (i < size )
		{
			// if (grid[x][y] != 0)
			// {
			// 	x--;
			// 	y++;
			// }
			if (calc(grid, x,y, input) > input)
				return 0;
			y--;
			i++;
		}
		y++;
		i = 0;
		// if (n == 1)
		// 	i = 1;
		while (i < size )
		{
			x--;
			// 	if (grid[x][y] != 0)
			// {
			// 	x++;
			// 	y++;
			// }
			// n = 0;
			if (calc(grid, x,y, input) > input)
				return 0;
			i++;
		}

		i = 0;
		while (i < size )
		{
			y++;
			// 	if (grid[x][y] != 0)
			// {
			// 	x++;
			// 	y--;
			// }
			if (calc(grid, x,y, input) > input)
				return 0;
			i++;
		}
		i = 0;
		while (i < size )
		{
			x++;
			// if (grid[x][y] != 0)
			// {
			// 	x--;
			// 	y--;
			// }
			if (calc(grid, x,y, input) > input)
				return 0;
			i++;
		}
		x++;
		size += 2;
		i = 0;
	}
	return 0;
}
