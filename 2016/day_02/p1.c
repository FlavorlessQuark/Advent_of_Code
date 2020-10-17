#include "../aoc.h"

int main()
{
	_Node	*input;
	int 	len;
	int 	pos;
	int 	n;

	pos = 5;
	input = fetch_by_word("input", "\n", 1, &len);

	while (input->next)
	{
		n = 0;
		while(*(char *)&input->data[n])
		{
			if (*(char *)&input->data[n] == 'U')
				pos = (pos - 3 < 1) ? (pos) : (pos - 3);
			else if (*(char *)&input->data[n] == 'D')
				pos = (pos + 3 > 9) ? (pos) : (pos + 3);
			else if (*(char *)&input->data[n] == 'L')
				pos = ((pos == 4) || (pos == 1) || (pos == 7) ) ? (pos) : (pos - 1);
			else
				pos = ((pos == 3) || (pos == 6) || (pos == 9) ) ? (pos) : (pos + 1);
			n++;
		}
		printf("%d\n", pos);
		input = input->next;
	}
}
