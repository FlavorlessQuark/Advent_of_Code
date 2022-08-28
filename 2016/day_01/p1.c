#include "../aoc.h"

int		distance(_Node *list)
{
	int	dir;
	int x;
	int y;
	int num;

	x = 0;
	y = 0;
	dir = 0;
	while(list->next != NULL)
	{
		extract_num(list->data, &num);
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
	return x + y;
}

int		main()
{
	_Node	*list;
	int 	len;

	list = fetch_by_word("input", " ,", 2, &len);
	const char *str = list->data;

	printf("Input : %d\n", distance(list));
	return 0;
}
