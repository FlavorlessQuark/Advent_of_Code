#include "../aoc.h"

void swapi(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swapl(char *str, char a, char b)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			str[i] = b;
		else if (str[i] == b)
			str[i] = a;
		i++;
	}
}

void move(char *str, int start, int end)
{
	char save;
	size_t i;
	int step;

	i = 0;
	save = str[start];
	(start < end) ? (step = -1) : (step = 1);
	i = start;
	while (i != end)
	{
		str[i] = str[i - step];
		i -= step;
	}
	str[end] = save;
}

char *strrev(char *str, int start, int end)
{

	while (start < end)
	{
		swapi(&str[start], &str[end]);
		start++;
		end--;
	}
	return str;
}

int main()
{
	char *input;
	_Node *operations;
	size_t len;
	int i = 0;

	input = join("", "abcdefgh");
	operations = fetch_by_word("input", "\n", 1, &len);

	while (operations != NULL)
	{
		if (*(char *)&operations->data [0]== 's')
		{
			if (*(char *)&operations->data[5] == 'p')
				swapi(&input[atoi(operations->data + 14)],&input[atoi(strrchr(operations->data, ' '))]);
			else
				swapl(input, *(char *)&operations->data[12], *(char *)&operations->data[26]);
		}
		else if (*(char *)&operations->data[0] == 'r')
		{
			if (*(char *)&operations->data[1] == 'e')
				strrev(input, atoi(operations->data + 18), atoi(strrchr(operations->data, ' ')));
			else if (*(char *)&operations->data[1] == 'o')
			{
				if (*(char *)&operations->data[7] == 'l')
					strshift(atoi(operations->data + 12) * -1, input);
				else if (*(char *)&operations->data[7] == 'r')
					strshift(atoi(operations->data + 12) * 1, input);
				else
				{
					len = strchr(input, *(char *)&operations->data[35]) - input;
					(len >= 4) ? (len += 2) : (len += 1);
					strshift(len, input);
				}
			}
		}
		else
		{
			move(input, atoi(operations->data + 14), atoi(strrchr(operations->data, ' ')));
		}

		printf("Line %d : %s\n", i, input);
		i++;
		operations = operations->next;
	}
}
