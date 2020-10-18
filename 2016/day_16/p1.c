#include "../aoc.h"

char *strrev(char *str)
{
	int i, len;
	char *cpy;

	cpy = join("",str); //Not a fan of the extra allocation here
	i = 0;
	len = strlen(str) - 1;
	while (len >= 0)
	{
		str[i] = cpy[len];
		i++;
		len--;
	}
	return str;
}

void replace(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		if (str[i] == '1')
			str[i] = '0';
		else
			str[i] = '1';
		i++;
	}
}

void checksum(char *str)
{
	int i;
	int n;
	while (strlen(str) %2 == 0)
	{
		n = 0;
		i = 1;
		while (i < strlen(str))
		{
			if (str[i] == str[i - 1])
				str[n] = '1';
			else
				str[n] = '0';
			n++;
			i += 2;
		}
		str[n] = '\0';
	}
}

char *fill()
{
	char *a;
	char *b;
	int end;

	end = 272;
	a = join("", "10001001100000001");

	while (strlen(a) < end)
	{
		b = strrev(strdup(a));
		replace(b);
		a = join(join(a, "0"), b);
	}
	a[end] = '\0';
//	printf("a :%s\n", a);
	return a;
}

int main()
{
	char *result;

	result = fill();
	checksum(result);

	printf("Result %s\n", result);
}

