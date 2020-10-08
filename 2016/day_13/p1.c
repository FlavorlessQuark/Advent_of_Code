# include "../aoc.h"

typedef struct s_Tile
{
	int x;
	int y;
	int value;

	struct s_Tile *next;
}				_Tile;

void	new_tile(_Tile *tail, int x, int y)
{
	_Tile *new;

	new = malloc(sizeof(_Tile));
	new->x = x;
	new->y = y;
	new->value = tail->value + 1;
	new->next = NULL;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = new;
}

int check_wall(int x, int y, int num)
{
	int result;
	int i;

	if (x < 0 || y < 0)
		return 0;

	result = (x * x) + (x * 3) + (2 * y * x) + y + (y*y) + num;

	i = 0;

	while (result > 0)
	{
		if (result & 1)
			i++;
		result >>= 1;
	}
	if (i % 2 == 0)
		return 1;
	return 0;
}

int check_list(int x, int y, _Tile *head)
{
	while (head->next != NULL)
	{
		if (head->x == x && head->y == y)
		{return 0;}
		head = head -> next;
	}
	return 1;
}

int main()
{
	int number;
	_Tile *head;
	_Tile *list;

	number = 1364;

	list = malloc(sizeof(_Tile));
	list->x = 1;
	list->y = 1;
	list->value = 1;
	list->next = NULL;
	head = list;

	while (list != NULL)
	{
		if (list->x == 31 && list->y == 39)
			break ;
		if (check_wall(list->x + 1, list->y, number) && check_list(list->x + 1, list->y, head))
			new_tile(list, list->x + 1, list->y);

		if (check_wall(list->x - 1, list->y, number) && check_list(list->x - 1, list->y, head))
			new_tile(list, list->x - 1, list->y);

		if (check_wall(list->x, list->y + 1, number) && check_list(list->x, list->y + 1, head))
			new_tile(list, list->x, list->y + 1);

		if (check_wall(list->x + 1, list->y - 1, number) && check_list(list->x, list->y - 1, head))
			new_tile(list, list->x + 1, list->y - 1);
		list = list->next;
	}

	printf("%d\n", list->value);
}
