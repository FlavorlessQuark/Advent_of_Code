#include "../aoc.h"

int distance(node *list)
{
	int	dir = 0, x = 0, y = 0;
	int num;
	while(list->next != NULL)
	{
		num = atoi((char *)list->data + 1);
		if (*(char *)&list->data[0] == 'L')
			dir--;
		else
			dir++;

		dir = (dir + 4) % 4;
		if (dir == 0)
			y += num;
		else if (dir == 1)
			x += num;
		else if (dir == 2)
			y -= num;
		else
			x -= num;
		list = list->next;
	}
//	x *= (y/y) * -1;
	return x + y;
}

int		main()
{
	node *list;
	int len;

	list = fetch_by_word("input", " ,", 2, &len);
	const char *str = (char *)list->data;

	printf("Input : %d\n", distance(list));
	return 0;
}
