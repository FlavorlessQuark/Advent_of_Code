#include "../../aoc.h"

int unravel(int corner, int input)
{
	int i;
	
	i = 0;
	while (corner - i != input)
		i++;
	return i;
}

int find_num(int input)
{
	int size;
	int bottom;
	int half;
	int x, y;

	size = 3;
	while (1)
	{
		if (size * size >= input)
			break ;
		size += 2;
	}
	half = (size / 2) + 1;
	bottom = size * size;
	size -= 1;

	if (bottom - size <= input) // y is  size
	{
		y = abs((size + 1) - half);
		x = abs(1 + unravel(bottom, input) - half);
	}
	else if (bottom - (size * 2) <= input) // y is  size
	{
		y = abs((size + 1) - half);
		x = abs(1 + unravel(bottom - size, input) - half);
	}
	else if (bottom - (size * 3) <= input) // y is  size
	{
		y = abs((size + 1) - half);
		x = abs(1 + unravel(bottom - (size * 2), input) - half);
	}
	else
	{
		y = abs((size + 1) - half);
		x = abs(1 + unravel(bottom - (size * 3), input)- half);
	}
	printf("Solution %d\n", x + y);
	return x + y;
}

int main()
{
	find_num(347991);
}
