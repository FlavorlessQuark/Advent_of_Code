#include "../aoc.h"

//Reminiscent of the gates day in 2015...

typedef struct s_bot
{
	int number;

	int high;
	int low;

	bot *next;
}				bot;

bot *new_bot()
{
	bot *new;
	new = malloc(sizeof(bot));
	new->next = NULL;
	new->high = -1;
	new->low = -1;
	return new;
}

void take(int num, bot *bot)
{
	(bot->high > num) ? (bot->low = num) : (bot->high = num);
}

bot *find_bot(int num, bot *blist)
{
	while (blist->next != NULL)
	{
		if (blist->number == num)
			break ;
		blist = blist->next;
	}
	return blist;
}

int read_instruction(bot *blist, _Node *list)
{
	int i;
	int botval;
	bot *head;

	head = blist;
	if (strlen(list->data) == 0)
		return 1;
	if (blist->data[0] == 'v')
	{
		botval = extract_num(list->data + 18, &botval);
		blist = find_bot(botval, head);
		if (blist->next == NULL && blist->number != botval)
		{
			blist->next = new_bot();
			blist = blist->next;
		}
		blist->number = botval;
		return 1;
	}
	else
	{
		botval = extract_num(list->data, &botval);
		if ((blist->next == NULL && blist->number != botval) || blist->low == -1 || blist->high == -1)
			return 0;
		blist = find_bot(botval, head);
		extract_num(list->data + 20 , &botval);
		take(blist->low, find_bot(botval,head));
		extract_num(list->data + 37, &botval);
		take(blist->high, find_bot(botval,head));
		return 1;
	}

	i++;
}

int run(_Node *list)
{
	bot *botlist;
	_Node *head;
	_Node *skiplist;

	botlist = NULL;

	while (1)
	{
		if (!read_instruction(botlist, list->next))
		{
			skiplist->next = list->next;
			list->next = list->next->next;
			list = list->next;
		}
		if (list->next == NULL || list = NULL)
		{
			list = skiplist;
			if (skiplist->next == NULL)
			{
				while (botlist->next != NULL)
				{
					if (botlist->low == 17 && botlist->high == 61)
					{
						printf("%d\n", botlist->number);
					}
				}
			}
			skiplist = new_node();
			skiplist->data = "";
		}
	}

}

int main()
{
	_Node *list;
	int len;

	list = fetch_by_word("test", "\n", 1, &len);

	run(list);
