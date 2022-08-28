#include "../aoc.h"


int path_len(_Node *start, _Node *end)
{
	int total;
	_V2 pos;
	total = 0;

	pos = *(_V2 *)start->data;

	while (pos.x != ((_V2 *)end->data)->x && pos.y != ((_V2 *)end->data)->y)
	{
		
	}

}

int bfs(_Node *current, char **map)
{
	int min;
	_Node *head;
	_Node *tail;

	_V2 this;
	head = current;
	while (current->next != NULL)
		current = current->next;
	tail = current;
	current = head;
	head = tail;

	do	{
		tail->next = current;
		tail = tail ->next;
		current = current->next;
	}	while (tail != head);
	return min;
}


int main()
{
	_Node *head;
	_Node *interest;

	_V2 *this;
	char **maze;
	_File file;
	int len, i, n;

	interest = new_node();
	head = interest;
	file = fetch_file("test", 1);

	len = strlen(strtok(file.content, "\n"));
	len = file.filesize / len;

	maze = malloc(len);
	maze[0] = file.content;

	i = 1;
	while (i < len)
	{
		maze[i] = strtok(NULL, "\n");
		n = 0;
		while (maze[i][n])
		{
			if (isdigit(maze[i][n]) && maze[i][n] != '0')
			{
				this = malloc(sizeof(_V2));
				this->x = n;
				this->y = i;
				interest->next = new_node();
				interest = interest->next;
				interest->data = this;
			}
			n++;
		}
		i++;
	}
	interest = head->next;
	bfs(interest, maze);


}
