#include "../../aoc.h"

int find_str(char *passports)
{
	char *traits[] = {"byr", "eyr", "iyr", "hgt", "hcl", "ecl", "pid"};
	int i;

	i = 0;
	while(i < 7)
	{
		if (strstr(passports, traits[i]) == NULL)
			return 0;
		i++;
	}
	return 1;
}



int	main()
{
	int len;
	int l;
	_File file;
	char **input;
	int start;
	int count;

	file = fetch_input_raw("input", 1);
	l = 1;

	start = 0;
	count = 0;
	while(l < file.filesize)
	{
		if(file.content[l] == '\n' && file.content[l - 1] == '\n')
		{
			file.content[l] = '\0';
			count += find_str(file.content + start);
			start = l + 1;
		}
		l++;
	}
	count += find_str(file.content + start);
	printf("Solution : %d\n", count);
}
