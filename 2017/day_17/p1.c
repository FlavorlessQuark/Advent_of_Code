#include "../../aoc.h"


int	main()
{
	int num;
	int i;
	int val;
	_Node *head;
	_Node *current;
	char **input;

	num = fetch_input("input", &input, "\n");
	extract_num(input[0], &num);

	head = list_node();
	head->data = (void *)0;
	head->next = head;
	val = 1;
	while (val <= 2017)
	{
		i = 0;
		while (i < num)
		{
			head = head->next;
			i++;
		}
		current = head->next;
		head->next = list_node();
		head->next->data = (void *)val;
		head->next->next = current;
		head = head->next;
		val++;
	}
	printf("Solution : %d\n", (int)(head->next->data));
}
