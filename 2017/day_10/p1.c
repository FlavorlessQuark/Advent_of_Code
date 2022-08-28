# include "../../aoc.h"

void reverse(int len, int i, int *list, int listsize)
{
	int *hold;
	int n;
	int _i;
	hold = calloc(len, sizeof(int));

	n = 0;
	_i = i;
	while (n < len)
	{
		if (_i == listsize)
			_i = 0;
		hold[n] = list[_i];
		n++;
		_i++;
	}
	_i = i;
	n--;
	while (n >= 0)
	{
		if (_i == listsize)
			_i = 0;
		list[_i] = hold[n];
		n--;
		_i++;
	}
}

int main()
{
	int *list;
	int inc;
	int size;
	int i;
	size_t len;
	_Node *input;

	input = fetch_by_word("input", " ,,", 1, &len);
	list = calloc(256, sizeof(int));

	len = 256;
	inc = 0;
	i = 0;
	while (i < len)
	{
		list[i] = i;
		i++;
	}
	i = 0;
	while (input != NULL)
	{
		extract_num(input->data, &size);
		if (size > 1 && size <= len)
			reverse(size, i, list, len);
		i += size + inc;
		while (i > len)
			i -= len;
		inc++;
		input = input->next;
	}
	printf("Solution : %d\n", list[0] * list[1]);
}
