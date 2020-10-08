#include "../aoc.h"

//Refactor note;

// Not really efficient. Twice as much memory as should be used
// Might need to add a "fetch_by_array"  and "fetch_by_list"


int main()
{
	int a,b,c,d, len, i, val;
	char **str;
	_Node *list;

	list = fetch_by_word("input", "\n", 1, &len);
	a = 0;
	b = 0;
	c = 1;
	d = 0;

	str = malloc(len);
	i = 0;
	while (list != NULL)
	{
		str[i] = list->data;
		list = list->next;
		i++;
	}

	i = 0;

	while (i < len && i >= 0)
	{
		if (str[i][0] == 'c')
		{
			(isdigit(str[i][4])) ? (val = atoi(str[i] + 4)) : ((str[i][4] == 'a') ? (val = a) : ((str[i][4] == 'b') ? (val = b) : ((str[i][4] == 'c') ? (val = c) : (val = d))));
			((str[i][strlen(str[i]) - 1] == 'a') ? (a = val) : ((str[i][strlen(str[i]) - 1] == 'b') ? (b = val) : ((str[i][strlen(str[i]) - 1] == 'c') ? (c = val) : (d = val))));
			i++;
		}
		else if (str[i][0] == 'j')
		{
			val = atoi(str[i] + 6);
			if (isdigit(str[i][4]))
				(atoi(str[i] + 4)) != 0 ? (i += val) : (i += 1);
			else
				(str[i][4] == 'a') ? ((a != 0) ? (i += val) : (i += 1)) : ((str[i][4] == 'b') ? ((b != 0) ? (i += val) : (i += 1)) : ((str[i][4] == 'c') ? ((c != 0) ? (i += val) : (i += 1)) : ((d != 0) ? (i += val) : (i += 1))));
		}
		else
		{
			(str[i][0] == 'i') ? (val = 1) : (val = -1);
			(str[i][4] == 'a') ? (a += val) : ((str[i][4] == 'b') ? (b += val) : ((str[i][4] == 'c') ? (c += val) : (d += val)));
			i++;
		}
	}
	printf("a : %d b: %d c: %d d: %d i: %d\n\n", a, b, c, d, i);
}
