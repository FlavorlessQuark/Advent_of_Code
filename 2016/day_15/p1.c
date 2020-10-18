#include "../aoc.h"

int summation(_Node *head, int time)
{
	while (head != NULL)
	{
		time++;
		if ((time +  atoi(head->data + strlen(head->data) - 2)) % atoi(head->data + 11) != 0)
			return 0;
		head = head->next;
	}
	return 1;
}

int main()
{
	_Node	*head;
	int		i;

	head = fetch_by_word("input", "\n", 1, &i);
	i = 0;
	while (1)
	{
		if (summation(head, i))
			break ;
		i++;
	}
	printf("%d\n", i);
}
