#include "../aoc.h"

int summation(_Node *head, int t_0)
{
	int time;
	int uwu;

	time = t_0;
	// printf("\n------New iteration----\n");
	while (head->next!= NULL)
	{
		time++;
		// uwu = (time +/* X_0 */ atoi(head->data + strlen(head->data) - 2)) % atoi(head->data + 11)/* Max pos */;

		// printf("t_0: %d | t: %d | X0: %d | Mod: %d | Result: %d\n",t_0, time,  atoi(head->data + strlen(head->data) - 2), atoi(head->data + 11), uwu);
		if ((time +  atoi(head->data + strlen(head->data) - 2)) % atoi(head->data + 11) != 0)
			return 0;
		head = head->next;
	}
	return 1;
}

int main()
{
	_Node *head;
	int len;
	int i;

	head = fetch_by_word("input", "\n", 1, &len);

	i = 0;
	while (1)
	{
		if (summation(head, i))
			break ;
		i++;
	}
	printf("%d\n", i);
}
