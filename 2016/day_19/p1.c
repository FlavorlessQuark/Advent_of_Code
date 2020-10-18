#include "../aoc.h"


int main()
{
	_Node	*list;
	int		size;
	int		i;

	i = 0;
	size = 5;
	list = malloc(size * sizeof(_Node));
	while (i < size)
	{
		(i == size - 1) ? (list[i].next = &list[0]) : (list[i].next = &list[i + 1]);
		list[i].data = i + 1;
		i++;
	}
	list = &list[0];
	while ((int)list->next->data != (int)list->data)
	{
		list->next = list->next->next;
		list = list->next;
	}

	printf("%d\n", (int)list->data);
}
