#include "../aoc.h"

int main()
{
	_Node *blacklist;

	int len;
	long num;
	long tmp = 0;

	blacklist = fetch_by_word("input", "\n", 1, &len);
	blacklist = lstMsort(blacklist, len);
	while (blacklist->next != NULL)
	{
		num = atol(blacklist->data);
		if (num < tmp)
			break ;
		tmp = (atol(strchr(blacklist->data, '-') + 1))+ 1;
		blacklist = blacklist->next;
	}
	printf("%ld\n", (atol(strchr(blacklist->data, '-') + 1))+ 1);
}
