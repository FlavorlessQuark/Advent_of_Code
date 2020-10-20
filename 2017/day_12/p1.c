#include "../../aoc.h"

void try_recurse(bool *coms, char **programs, char *tmp)
{
	int pid;
	char *tmp;

	tmp = strchr(tmp, '>');
	while (tmp != '\0')
	{
		tmp += extract_num(tmp, &pid);
		if (coms[pid] == false)
		{
			coms[pid] = true;
			try_recurse(coms, programs, join("", programs[pid]));
		}
	}
}

int main()
{
	_Node *input;
	char **programs;
	char *tmp;
	size_t len;
	size_t i;
	size_t pid;
	bool *coms;

	input = fetch_by_word("input", "\n", 1, &len);
	coms = calloc(len, sizeof(bool));
	coms[0] = true;
	programs = malloc(len, sizeof(programs));

	i = 0;
	while (input != NULL)
	{
		programs[i] = input->data;
		i++;
		input = input->next;
	}

	i = 0;
	while (i < len)
	{
		tmp = join("", programs[i]);
		extract_num(tmp, &pid);
		if (coms[pid] == true)
		{
			try_recurse(coms, programs, tmp);
		}
		i++;
	}
}
