#include "../../aoc.h"

int find_str(char *passports)
{
	char *traits[] = {"byr", "eyr", "iyr", "hgt", "hcl", "ecl", "pid"};
	char *eclr[] = {"amb", "blu", "brn", "gry", "grn", "hzl", "ot"};
	int i;
	char *s;

	if ((s = strstr(passports, traits[0])) != NULL)
	{
		extract_num(s, &i);
		if (i < 1920 || i > 2002)
			return 0;
	}
	else return 0;

	if ((s = strstr(passports, traits[1])) != NULL)
	{
		extract_num(s, &i);
		if (i < 2010 || i > 2020)
			return 0;
	}
	else return 0;

	if ((s = strstr(passports, traits[2])) != NULL)
	{
		extract_num(s, &i);
		if (i < 2020 || i > 2030)
			return 0;
	}
	else return 0;

	if ((s = strstr(passports, traits[3])) != NULL)
	{
		s += extract_num(s, &i);
		if (strstr(s, "cm") && (i < 150 || i > 193))
			return 0;
		else if (strstr(s, "in") && (i < 59 || i > 76))
			return 0;
		if (s == NULL)
			return 0;
	}
	else return 0;

	if ((s = strstr(passports, traits[4])) != NULL)
	{
		extract_num(s, &i);
		if (s[4] == '#')
	}
	else return 0;

	if ((s = strstr(passports, traits[0])) != NULL)
	{
		extract_num(s, &i);
		if (i <1920 || i > 2002)
			return 0;
	}
	else return 0;
	if ((s = strstr(passports, traits[0])) != NULL)
	{
		extract_num(s, &i);
		if (i <1920 || i > 2002)
			return 0;
	}
	else return 0;
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
