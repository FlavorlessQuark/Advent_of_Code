#include "../aoc.h"

int check(_V2 *pos, int x, int y, int i)
{
	int n = 0;

	while (n < i)
	{
		if(pos[n].x == x && pos[n].y == y)
			return x + y;
		n++;
	}
	return 0;
}


int distance(_Node *list, int size)
{
	int	dir = 0, x = 0, y = 0, x_inc, y_inc;
	int num;
	int i;
	_V2 *pos;
	_Node *head;

	i = 0;
	num = 0;
	head = list;

	while(list->next != NULL)
	{
		num += atoi((char *)list->data + 1);
		list = list->next;
	}
	list = head;

	pos = calloc(num, sizeof(_V2));

	while(list->next != NULL)
	{
		extract_num(list->data, &num);
		if (*(char *)&list->data[0] == 'L')
			dir--;
		else
			dir++;

		dir = (dir + 4) % 4;
		x_inc = 0;
		y_inc = 0;

		if (dir == 0)
			y_inc = 1;
		else if (dir == 1)
			x_inc = 1;
		else if (dir == 2)
			y_inc = -1;
		else
			x_inc = -1;

		while (num >= 0)
		{
			pos[i].x = x;
			pos[i].y = y;
			y += y_inc;
			x += x_inc;
			if (check(pos, x,y,i))
				return x + y;
			i++;
			num--;
		}
		list = list->next;
	}
	return 0;
}

int		main()
{
	_Node *list;
	int len;

	list = fetch_by_word("input", " ,", 1, &len);
	printf("Input : %d\n", distance(list, len));
	return 0;
}
