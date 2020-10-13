#include "../aoc.h"



int main()
{
	_Node *blacklist;

	int len;
	long num;
	long lower;
	long allowed;
	long tmp = 0;

	allowed = 0;
	lower = 0;
	blacklist = fetch_by_word("input", "\n", 1, &len);
	blacklist = lstMsort(blacklist, len);
// Works if sorted asc
	while (blacklist != NULL)
	{
		num = atol(blacklist->data);
		tmp = (atol(strchr(blacklist->data, '-') + 1));
		blacklist = blacklist->next;
	}
	printf("%ld\n", allowed);
}
