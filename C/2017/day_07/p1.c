#include "../../aoc.h"

_Node *D_E_S_T_R_O_Y_bzzt(_Node *head)
{
	_Node *list;

	while ((strchr(head->data,'>')) == '\0')
		head = head->next;

	list = head;
	while (list != NULL)
	{
		if (list->next != NULL && (strchr(list->next->data,'>')) == '\0')
			list->next = list->next->next;
		list = list->next;
	}
	return head;
}

int main()
{
	_Node *head;
	_Node *namelist;
	_Node *mainlist;
	_Node *sublist;
	char *name;
	char *current;
	size_t len;
	bool found;

	head = fetch_by_word("input", "\n", 1, &len);
	head = D_E_S_T_R_O_Y_bzzt(head);
	mainlist = head;
	namelist = head;

	while(namelist!= NULL)
	{
		name = join("", namelist->data);
		name = strtok(name, " ");

		found = false;
		mainlist = head;
		while (mainlist != NULL)
		{
			current = join("", mainlist->data);
			sublist = fetch_words(strchr(current, '>'), ">, ,,", &len);
			if (search_list(sublist, name) != NULL)
			{
				found = true;
				break ;
			}
			mainlist = mainlist->next;
		}
		if (found == false)
		{
			printf("Solution : %s\n", name);
			break;
		}
		namelist = namelist->next;
	}
	return 0;
}
