#include "../aoc.h"


int main()
{
	_Node *list;
	_Node *del;
	int size;
	int i;

	size = 3012210;
	list = malloc(size * sizeof(_Node));

	i = 0;
	while (i < size)
	{
		(i == size - 1) ? (list[i].next = &list[0]) : (list[i].next = &list[i + 1]);
		list[i].data = i + 1;
		i++;
	}
	list = &list[0];
	del = &list[(size / 2) - 1];
	while ((int)list->next->data != (int)list->data)
	{
		del->next = del->next->next;
		// printf("%d -> ", (int)list->data);
		if (size  % 2 == 1)
			del = del->next;
		list = list->next;
		size--;
		// printf("%d \n", (int)list->data);
	}
	printf("%d\n", (int)list->data);
// incompatible integer to pointer conversion assigning to 'void *' from 'int'
}
