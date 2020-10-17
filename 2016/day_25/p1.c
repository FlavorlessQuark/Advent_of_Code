#include "../aoc.h"

int main()
{
	int a,b,c,d,i, val;
	size_t len;
	char reg;
	char **str;
	_Node *list;

	list = fetch_by_word("test", "\n", 1, &len);
	a = 1279;
	b = 0;
	c = 0;
	d = 0;

	str = malloc(len * sizeof(void *));
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
			(isdigit(str[i][4]) || isdigit(str[i][5])) ? (val = atoi(str[i] + 4)) : ((str[i][4] == 'a') ? (val = a) : ((str[i][4] == 'b') ? (val = b) : ((str[i][4] == 'c') ? (val = c) : (val = d))));
			((str[i][strlen(str[i]) - 1] == 'a') ? (a = val) : ((str[i][strlen(str[i]) - 1] == 'b') ? (b = val) : ((str[i][strlen(str[i]) - 1] == 'c') ? (c = val) : (d = val))));
			i++;
		}
		else if (str[i][0] == 'j')
		{
			reg = strrchr(str[i], ' ')[1];
			(isdigit(str[i][strlen(str[i]) - 1])) ? (val = atoi(strrchr(str[i], ' '))) : ((reg == 'a') ? (val = a) : ((reg == 'b') ? (val = b) : ((reg == 'c') ? (val = c) : (val = d))));
			if (val == 0)
				val = 1;
			if (isdigit(str[i][4]))
			{
				(atoi(str[i] + 4) != 0) ? (i += val) : (i += 1);
			}
			else
				(str[i][4] == 'a') ? ((a != 0) ? (i += val) : (i += 1)) : ((str[i][4] == 'b') ? ((b != 0) ? (i += val) : (i += 1)) : ((str[i][4] == 'c') ? ((c != 0) ? (i += val) : (i += 1)) : ((d != 0) ? (i += val) : (i += 1))));
		}
		else if (str[i][0] == 't')
		{
			(isdigit(str[i][4])) ? (extract_num(str[i], &val)) : ((str[i][4] == 'a') ? (val = a) : ((str[i][4] == 'b') ? (val = b) : ((str[i][4] == 'c') ? (val = c) : (val = d))));
			val += i;
			if (val >= len || val < 0)
			{
				i++;
				continue;
			}
			if (count(str[val], ' ') == 1)
			{
				if (str[val][0] == 'i')
					str[val] = join("dec", strrchr(str[val], ' '));
				else
					str[val] = join("inc", strrchr(str[val], ' '));
			}
			else
			{
				if (str[val][0] == 'j')
					str[val] = join("cpy", strchr(str[val], ' '));
				else
					str[val] = join("jnz", strchr(str[val], ' '));
			}
			i++;
		}
		else if (str[i][0] == 'o')
		{
			(isdigit(str[i][4])) ? (extract_num(str[i], &val)) : ((str[i][4] == 'a') ? (val = a) : ((str[i][4] == 'b') ? (val = b) : ((str[i][4] == 'c') ? (val = c) : (val = d))));
			printf("Out : %d\n", val);
			i++;
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
