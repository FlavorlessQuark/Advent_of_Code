# include "../aoc.h"

typedef struct grid
{
	int data;
	_V2 pos;
	struct grid *next;
}				_Grid;

_Grid *new_grid()
{
	_Grid *node;

	node = calloc(1 , sizeof(_Grid));
	return node;
}

void _printgrid(_Grid *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", lst->data);
		lst = lst->next;
	}
}
_Grid *gridSort(_Grid *h1, _Grid *h2)
{
	_Grid head;
	_Grid *list;

	list = &head;
	list->next = NULL;
	while (1)
	{
		if(h1 == NULL)
		{
			list->next = h2;
			break ;
		}
		if (h2 == NULL)
		{
			list->next = h1;
			break ;
		}
		if (h1->data <= h2->data)
		{
			list->next = h1;
			h1 = h1->next;
		}
		else
		{
			list->next = h2;
			h2 = h2->next;
		}
		list = list->next;
	}
	return head.next;
}

//List Merge Sort
_Grid *gridMsort(_Grid *head, int len)
{
	_Grid *h1;
	_Grid *h2;
	int i;

	h1 = head;
	i = 0;
	if (len >= 2)
	{
		while (h1->next != NULL && i < (len / 2) - 1)
		{
			h1 = h1->next;
			i++;
		}
		h2 = h1->next;
		h1->next = NULL;
		h1 = head;

		h1 = gridMsort(h1,(len / 2));
		h2 = gridMsort(h2, (len / 2));
		head = gridSort(h1, h2);
	}
	return head;
}

_Grid *gcount(_Grid *av, _Grid *used, size_t *len)
{
	while (av != NULL)
	{
		if (av->data >= used->data)
			break ;
		if ((used->pos.x != av->pos.x || used->pos.y != av->pos.y) || av->data < used->data)
		{
			*len -= 1;
		}
		av = av->next;
	}
	return av;
}

int main()
{
	_Node *nodes;
	_Grid *size;
	_Grid *s_head;
	_Grid *a_head;
	_Grid *available;
	size_t len, pairs;
	int x, y, data;

	pairs = 0;
	nodes = fetch_by_word("input", "\n", 1, &len);
	size = new_grid();
	available = new_grid();
	s_head = size;
	a_head = available;
	while (nodes != NULL)
	{

		nodes->data += extract_num(nodes->data, &x);
		nodes->data += extract_num(nodes->data, &y);

		size->pos.x = x;
		size->pos.y = y;
		available->pos.x = x;
		available->pos.y = y;

		nodes->data += extract_num(nodes->data, &data);
		nodes->data += extract_num(nodes->data, &data);
		size->data = data;

		nodes->data += extract_num(nodes->data, &data);
		//printf("Size %d\n", data);
		available->data = data;
		nodes = nodes->next;
		if (nodes == NULL)
			break ;
		size->next = new_grid();
		available->next = new_grid();
		size = size->next;
		available = available->next;
	}
	size = s_head;
	available = a_head;
	size = gridMsort(s_head, len);
	available = gridMsort(a_head, len);

	while (size != NULL && available != NULL)
	{
		if (size->data > 0 )
		{
			if (size->pos.x != available->pos.x || size->pos.y != available->pos.y)
			{
				available = gcount(available, size,&len);
				pairs += len;
			}
		}
		size = size->next;
	}
	printf("%zu\n", pairs);
}
