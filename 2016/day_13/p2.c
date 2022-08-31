# include "../../aoc.h"

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

	result = (x * x) + (3 * x) + (2 * x * y) + y + (y * y) + num;

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

int check_list(int x, int y, _Tile *head, int *location)
{
	while (head->next != NULL)
	{
		if (head->x == x && head->y == y)
		{return 0;}
		head = head -> next;
	}
	*location += 1;
	return 1;
}

int main()
{
	int		number;
	int		location;
	int		i;
	_Tile	*head;
	_Tile	*list;

	i = 0;
	location = 1;
	number = 1364;

	list = malloc(sizeof(_Tile));
	list->x = 1;
	list->y = 1;
	list->value = 1;
	list->next = NULL;
	head = list;

	while (list)
	{
		if (check_wall(list->x + 1, list->y, number) && check_list(list->x + 1, list->y, head, &location) && list->value < 50)
		{
			new_tile(list, list->x + 1, list->y);
		}

		if (check_wall(list->x - 1, list->y, number) && check_list(list->x - 1, list->y, head, &location) && list->value < 50)
		{
			new_tile(list, list->x - 1, list->y);
		}

		if (check_wall(list->x, list->y + 1, number) && check_list(list->x, list->y + 1, head, &location) && list->value < 50)
		{
			new_tile(list, list->x, list->y + 1);
		}

		if (check_wall(list->x + 1, list->y - 1, number) && check_list(list->x, list->y - 1, head, &location) && list->value < 50)
		{
			new_tile(list, list->x + 1, list->y - 1);
		}
		list = list->next;
		i++;
	}
	while (head)
	{
		head = head->next;
	}

	printf("%d %d\n", location);
}
