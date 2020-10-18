#include "../../aoc.h"

int strrcmp(char *s1, char *s2) //Dont actually need this, string.h has a astrcmp
{
	while (s1 && s2)
	{
		if (*s1 != *s2)
			return 1;
		s1++;
		s2++;
	}
	return 0;
}

int main()
{
	_Node *input;
	_Node *phrase;
	_Node *p_next;
	size_t len;
	int _total, total;

	total = 0;
	input = fetch_by_word("input", "\n", 1, &len);
	while (input != NULL)
	{
		phrase = fetch_words(input->data, " ,\t", &len);
		_total = 1;

		while (phrase->next != NULL)
		{
			p_next = phrase->next;
			while (p_next != NULL)
			{
				if (!(strcmp(phrase->data, p_next->data)))
				{
					_total = 0;
					break ;
				}
				p_next = p_next->next;
			}
			if (_total == 0)
				break ;
			phrase = phrase->next;
		}
		if (_total > 0)
			total += 1;
		input = input->next;
	}
	printf("Solution : %d\n", total);
}
