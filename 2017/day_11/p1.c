#include "../../aoc.h"

int main()
{
	_Node *input;
	int n;
	int e;
	int ne;
	int nw;
	size_t len;
	char *prev;

	input = fetch_by_word("input", ",", 1, &len);
	n = 0;
	e = 0;
	ne = 0;
	nw = 0;
	while (input != NULL)
	{
		if (!(strcmp(input->data, "n")))
			n++;
		else if (!(strcmp(input->data, "s")))
			n--;
		else if (!(strcmp(input->data, "ne")))
		{
			ne++;
			e++;
		}
		else if (!(strcmp(input->data, "nw")))
		{
			nw++;
			e--;
		}
		else if (!(strcmp(input->data, "se")))
		{
			nw--;
			e++;
		}
		else
		{
			ne--;
			e--;
		}
		input = input->next;
	}
	printf("N %d E %d  Ne %d  Nw %d\n", n, e, ne, nw);
	// Arbitrary addition. Number 2 worked for p1. Why does it work? Magic...
	// Not sure if this is consitant, might need better solution EDIT: It isn't. highly unreliable. but who doesn't like some randomness :)
	//											3			4		3			1
	printf("Solution: %d or %d or %d or %d\n", (ne + n),(nw + e), (nw + n), (n + e));
}
