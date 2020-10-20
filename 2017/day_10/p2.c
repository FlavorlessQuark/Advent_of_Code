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

void knot_hash(_Node *input, int *list, int *i, int *inc)
{
	int len = 256;
	int size;

	while (input != NULL)
	{
		extract_num(input->data, &size);
		if (size > 1 && size <= len)
			reverse(size, *i, list, len);
		*i += size + *inc;
		while (*i > len)
			*i -= len;
		*inc++;
		input = input->next;
	}
}

char *get_ascii(char *input)
{
	
}

int main()
{
	_File file;
	int *list;
	int inc;
	int size;
	int i;
	int round;
	size_t len;
	_Node *input;

	file = fetch_file("input", 1);
	input = fetch_words(file.content, " ,,", &len);
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
	round = 0;
	while (round < 64)
	{
		/* code */
	}


	printf("Solution : %d\n", list[0] * list[1]);
}
