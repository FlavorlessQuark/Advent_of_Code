#include "../aoc.h"



int distance(node *list, int size)
{
	int	dir = 0, x = 0, y = 0;
	int num, i, n;
	_V2 *pos;

	i = 0;
	pos = calloc(size, sizeof(_V2));
	while(list->next != NULL)
	{
		n = 0;
		num = atoi((char *)list->data + 1);
		if (*(char *)&list->data[0] == 'L')
			dir--;
		else
			dir++;

		pos[i].x = x;
		pos[i].y = y;
		dir = (dir + 4) % 4;
		if (dir == 0)
			y += num;
		else if (dir == 1)
			x += num;
		else if (dir == 2)
			y -= num;
		else
			x -= num;
		while (n < i)
		{
			if(pos[n].x == x && pos[n].y == y)
			{
				printf("x %d, posn %d\n", x, y);
				return x + y;
			}
			n++;
		}
		list = list->next;
		i++;
	}
	i = 0;
	return 0;
}

int		main()
{
	node *list;
	int len;

	list = fetch_by_word("input", " ,", 2, &len);
	const char *str = (char *)list->data;

	printf("Input : %d\n", distance(list, len));
	return 0;
}
