#include "../aoc.h"

typedef struct s_cell
{
	int x;
	int y;

	char *path;
	struct s_cell *next;
}				_cell;


void	tile(char *path, int x, int y, _cell *head)
{
	_cell *new;

	new = malloc(sizeof(_cell));
	new->x = x;
	new->y = y;
	new->path = path;
	new->next = NULL;
	while (head->next != NULL)
		head = head->next;
	head->next = new;
}

int check_wall(char *hash, int dir, int x, int y)
{
	if (x <= 0 || x > 4 || y <= 0 || y > 4)
		return 0;

	if (hash[dir] >= 'b' && hash[dir] <= 'f')
		return 1;
	return 0;
}


int main()
{
	_cell *head;
	_cell *current;
	char *hash;

	hash = malloc(32);

	current = malloc(sizeof(_cell));
	current->x = 1;
	current->y = 1;
	current->next = NULL;
	current->path = join("","yjjvjgan");
	head = current;


	while (current != NULL)
	{
		printf("Top (%d, %d) %s\n", current->x, current->y, current->path);
		get_new_hash(current->path, hash);
		if (current->x == 4 && current->y == 4)
			break;

		if (check_wall (hash, 0, current->x,	 current->y - 1))
			tile(join(current->path,"U"), current->x,	 current->y - 1, head);

		if (check_wall (hash, 1, current->x,	 current->y + 1))
			tile(join(current->path,"D"), current->x,	 current->y + 1, head);

		if (check_wall (hash, 2, current->x - 1, current->y))
			tile(join(current->path,"L"), current->x - 1, current->y, head);

		if (check_wall (hash, 3, current->x + 1, current->y))
			tile(join(current->path,"R"), current->x + 1, current->y, head);
		current = current->next;
	}
		printf("Bottom\n");
	printf("%s\n", current->path);
}
