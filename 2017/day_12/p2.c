#include "../../aoc.h"

void try_recurse(bool *coms, char **programs, char *tmp)
{
	int pid;

	// printf("----- Try for %s -------\n", tmp);
	tmp = strchr(tmp, '>') + 1;
	while (tmp[0] != '\0')
	{
		tmp += extract_num(tmp, &pid);
		if (pid < 0 || pid > 1999)
			continue;
		if (coms[pid] == false)
		{
			// printf("Recusring with %d\n", pid);
			coms[pid] = true;
			try_recurse(coms, programs, join("", programs[pid]));
			// printf("Recursion of %d done\n", pid);
		}
	}
}

int countbool(bool *list, size_t len)
{
	size_t i;
	int count;

	count = 0;
	while (i < len)
	{
		if (list[i] == true)
			count++;
		i++;
	}
	return count;
}

void inloop(bool *coms, char **programs, size_t len)
{
	char *tmp;
	size_t i;
	int pid;

	i = 0;
	while (i < len)
	{
		tmp = join("", programs[i]);
		extract_num(tmp, &pid);
		if (coms[pid] == true)
		{
			// printf("\n\tStarting from: %d\n", pid);
			try_recurse(coms, programs, tmp);
			// printf("\tEnding from: %d\n\n", pid);
		}
		i++;
	}
}

int main()
{
	_Node *input;
	char **programs;
	char *tmp;
	size_t len;
	size_t i;
	int pid;
	int groups;
	bool *coms;

	groups = 0;
	input = fetch_by_word("input", "\n", 1, &len);
	coms = calloc(len, sizeof(bool));
	programs = malloc(len * sizeof(programs));

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
		if (coms[i] == false)
		{
			// printf("coms id %zu\n", i);
			groups++;
			coms[i] = true;
			inloop(coms, programs, len);
		}
		i++;
	}
	// _printbool(coms, len);
	printf("Solution %d\n", groups);
}
