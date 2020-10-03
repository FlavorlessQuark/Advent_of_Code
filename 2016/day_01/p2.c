#include "../aoc.h"

int check(_V2 *pos, int x, int y, int i)
{
	int n = 0;

	while (n < i)
	{
		if(pos[n].x == x && pos[n].y == y)
		{
			printf("x %d, posn %d\n", x, y);
			return x + y;
		}
		n++;
	}
	return 0;
}


int distance(node *list, int size)
{
	int	dir = 0, x = 0, y = 0;
	int num;
	int i;
	_V2 *pos;
	node *head;

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
		num = atoi((char *)list->data + 1);
		if (*(char *)&list->data[0] == 'L')
			dir--;
		else
			dir++;

		dir = (dir + 4) % 4;

		if (dir == 0)
		{
			while (num >= 0)
			{
				pos[i].x = x;
				pos[i].y = y;
				y++;
				if (check(pos, x,y,i))
					return 0;
				i++;
				num--;
			}
		}
		else if (dir == 1)
			while (num >= 0)
			{
				pos[i].x = x;
				pos[i].y = y;
				x++;
				i++;
				if (check(pos, x,y,i))
					return 0;
				num--;
			}
		else if (dir == 2)
			while (num >= 0)
			{
				pos[i].x = x;
				pos[i].y = y;
				y--;
				if (check(pos, x,y,i))
					return 0;
				i++;
				num--;
			}
		else
			while (num >= 0)
			{
				pos[i].x = x;
				pos[i].y = y;
				x--;
				if (check(pos, x,y,i))
					return 0;
				i++;
				num--;
			}
		list = list->next;
	}
	return 0;
}

int		main()
{
	node *list;
	int len;

	list = fetch_by_word("input", " ,", 1, &len);
	const char *str = (char *)list->data;

	printf("Input : %d\n", distance(list, len));
	return 0;
}
