#include "../../aoc.h"

int get_max(int *numbers, size_t len, int *max)
{
	size_t i;
	int tmp;
	int save;

	i = 0;
	*max = numbers[0];
	save = 0;
	while (i < len)
	{
		tmp = i + 1;
		while (tmp < len)
		{
			if (numbers[tmp] > *max)
			{
				*max = numbers[tmp];
				save = tmp;
				i = tmp;
			}
			tmp++;
		}
		i++;
	}
	return save;
}


char *convert_intstr(int *array, size_t len, char *separator)
{
	size_t i;
	char *str;

	i = 0;
	str = "";
	while (1)
	{
		str = join(str, itoa(array[i]));
		i++;
		if (i >= len)
			break ;
		str = join(str, separator);
	}
	return str;
}

bool search_list(_Node *list, char *str)
{
	while (list != NULL)
	{
		if (!strcmp(list->data, str))
			return true;
		list = list->next;
	}
	return false;
}

int main()
{
	_File	file;
	_Node	*list;
	_Node	*head;
	char	*tmp;
	int		*banks;
	int		n;
	int		remainder;
	size_t	i;

	file = fetch_file("input",1);
	file.filesize -= count_occurence(file.content, '\t') + 1;
	banks = calloc(file.filesize, sizeof(int));
	head = new_node();
	head->data = join("",file.content);
	head->next = NULL;
	list = head;

	i = 0;
	while (file.content[0] != '\0')
	{
		file.content += extract_num(file.content, &n);
		banks[i] = n;
		i++;
	}

	int cycle = 0;
	while (1)
	{
		n = get_max(banks, i, &remainder) + 1;
		banks[n - 1] = 0;
		while (remainder > 0)
		{
			if (n >= i)
				n = 0;
			banks[n] += 1;
			remainder--;
			n++;
		}
		cycle++;
		n = 0;
		tmp = convert_intstr(banks, i, " ");
		if (search_list(head, tmp) == true)
			break ;
		list = get_last(head);
		list->next = new_node();
		list->next->data = tmp;
	}
	head = new_node();
	head->data = tmp;
	cycle = 0;
	while (1)
	{
		n = get_max(banks, i, &remainder) + 1;
		banks[n - 1] = 0;
		while (remainder > 0)
		{
			if (n >= i)
				n = 0;
			banks[n] += 1;
			remainder--;
			n++;
		}
		cycle++;
		n = 0;
		tmp = convert_intstr(banks, i, " ");
		if (search_list(head, tmp) == true)
			break ;
		list = get_last(head);
		list->next = new_node();
		list->next->data = tmp;
	}
		// while (n < i)
		// {
	printf("%d \n", cycle);
		// n++;
		// }
	// }

}
