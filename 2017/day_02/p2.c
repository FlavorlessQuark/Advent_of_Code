#include "../../aoc.h"

int get_div(int numi, char *str)
{
	int num;
	int a, b;
	int n;

	n = 0;
	while (str[n])
	{
		n += extract_num(str + n, &num);
		if ((MAX(numi, num) % MIN(numi,num) == 0))
			return (MAX(numi, num) / MIN(numi,num));
	}
	return 0;
}

int main()
{
	_Node	*head;
	size_t	total;
	int		i, n, num, res1, res2;

	head = fetch_by_word("input", "\n", 1, &total);
	total = 0;
	while (head != NULL)
	{
		i = 0;
		while (((char *)head->data)[i])
		{
			i += extract_num(head->data + i, &num);
			total += get_div(num, head->data + i);
		}
		head = head->next;
	}
	printf("Solution : %lu\n", total);
}
