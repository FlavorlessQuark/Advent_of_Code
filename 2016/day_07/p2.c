#include "../../aoc.h"

int skipHyperNet(char *ip, int start)
{
	int i;

	i = start;
	while (ip[i] && ip[i] != ']')
		i++;
	return i + 1;
}

int searchIp(char *ip, char *sequence)
{
	int i;

	i = 0;
	while (ip[i] && ip[i + 1] && ip[i + 2])
	{
		// printf("Here at %d\n", i);
		// printf("Current is %c %c %c\n", ip[i], ip[i + 1], ip[i + 2]);
		if (ip[i + 2] == '[')
		{
			// printf("Hypernet here %d\n", i + 2);
			i = skipHyperNet(ip, i + 2);
		}
		else
		{
			// printf("Current is %c %c %c\n", ip[i], ip[i + 1], ip[i + 2]);
			if (ip[i] == sequence[0] && ip[i + 1] == sequence[1] && ip[i + 2] == sequence[2])
				return TRUE;
			i++;
		}
	}
	return FALSE;
}

int searchHypernet(char *ip, int index)
{
	int i;
	char sequence[3];

	i = index;
	while (ip[i] && ip[i + 1] && ip[i + 2] && ip[i + 2] != ']')
	{
		if (ip[i] == ip[i + 2] && ip[i] != ip[i + 1])
		{
			sequence[0] = ip[i + 1];
			sequence[1] = ip[i];
			sequence[2] = ip[i + 1];
			printf("Found %c %c %c\n", ip[i], ip[i + 1], ip[i + 2]);
			if (searchIp(ip, sequence))
				return TRUE;
		}
		i++;
	}
	return FALSE;
}

int findHyperNet(char *ip, int offset)
{
	int i;

	i = offset + 1;
	while (ip[i])
	{
		if (ip[i] == '[')
		{
			// printf("Here %d %c\n", i, ip[i]);
			return i;
		}
		i++;
	}

	return -1;
}

int main()
{
	_Node *input;
	size_t len;
	int offset;
	int total;
	input = fetch_by_word("input", "\n", 1, &len);

	total = 0;
	offset = -1;
	while (input)
	{
		printf("\n\nSearching %s\n", input->data);
		while (((offset = findHyperNet(input->data, offset)) >= 0))
		{
			// printf("Offset %d\n", offset);
			// printf("Found hypernet at %d\n", offset);
			if (searchHypernet(input->data, offset))
			{
				total++;
				printf("Supports SSL %s\n", input->data);
			}
		}
		input = input->next;
	}
	printf("Total : %d\n", total);
	// ______\0___\0___
}
