#include "../../aoc.h"



int main()
{
	char *programs;
	char *dance;
	int i, n;
	_File file;

	file = fetch_file("input", 1);
	programs = join("", "abcde");
	dance = strtok(file.content, "\n");

	while (dance != NULL)
	{
		if (dance[0] == 's')
			strshift(atoi(dance + 1), programs);
		else if (dance[0] == 'x')
			swap(&programs[atoi(dance + 1)], &programs[atoi(strrchr(dance, '/') + 1)]);

		// else if (dance[0] == 'p')
		dance = strtok(NULL, "\n");
	}
	printf("%s %d %d\n", programs, i, n);
}
