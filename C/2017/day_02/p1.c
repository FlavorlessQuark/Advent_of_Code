#include "../../aoc.h"

int main()
{
	_Node	*head;
	size_t	total;
	int		min, max, num;

	head = fetch_by_word("input", "\n", 1, &total);
	total = 0;
	while (head != NULL)
	{
		min = INT16_MAX;
		max = 0;

		//The below code should technically segfault
		while (isdigit(((char *)(head->data += extract_num(head->data, &num)))[1]) && ((char *)head->data)[0] != '\0')
		{
			min = MIN(min, num);
			max = MAX(max, num);
		}
		min = MIN(min, num);
		max = MAX(max, num);
		total += max - min;
		head = head->next;
	}
	printf("Solution : %lu\n", total);
}
