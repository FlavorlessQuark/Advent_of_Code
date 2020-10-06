#include "../aoc.h"

// int eval_chunk(char *str, int len)
// {
// 	size_t i;
// 	char c;

// 	c = str[0];
// 	i = 1;
// 	while (i < len)
// 	{
// 		if (str[i] != c)
// 			c = str[i];
// 		else
// 		{
// 			if (i + 1 == len)
// 				return 0;
// 			if (i > 1 && str[i - 2] == str[i + 1] && str[i + 1] != c)
// 				return 1;
// 		}
// 		i++;
// 	}
// 	return 0;
// }

// int calc_chunk(char *str)
// {
// 	int len;
// 	int eval;
// 	int chunk;
// 	eval = 0;

// 	chunk = 0;
// 	while (len != 0)
// 	{
// 		len = strspn(str,ABC_L);

// 		chunk++;
// 		if (eval_chunk(str, len))
// 			eval = 1;
// 		if (len == strlen(str))
// 			return eval;
// 		str += len + 1;

// 		chunk++;
// 		len = strspn(str,ABC_L);

// 		if (eval_chunk(str, len))
// 			return 0;
// 		str += len + 1;
// 	}
// 	chunk++;
// 	len = strlen(str);
// 	if (eval_chunk(str, len))
// 		eval = 1;
// 	return eval;
// }

int main()
{
	_File file;
	int total;
	// char *str;
	node *list;
	node *head;

	file = fetch_file("test", 1);
	list = get_words((char *)file.content, "[,],\n", &total);

	// Note to self for the inevitabe day when I have to fix this :
	
	// Adress of (some nodes of)list was incomplete once printed... Why? I don't have a single clue...
	// ""Fix""" was to move the void * in node struct below node *, and I said fix with a lot of air quotes
	// Doesn't segfault anymore but memory leak still, will probably lead to corrupted memory down the line..
	// Fsanitize says it's in newnode() but I'm not doing anything fishy over there
	// Something something void *?

	while (list->next != NULL)
	{
		printf("word %s\n" , (char *)list->data, list->next);
		list = list->next;
	}
	// str = strtok(file.content, "\n");
	// total = 0;
	// while (str != NULL)
	// {
	// 	total += calc_chunk(str);
	// 	str = strtok(NULL, "\n");
	// }
	// printf("%d\n",total);
}
