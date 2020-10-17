#include "../aoc.h"

int main()
{
	_File input;
	int total;
	int i;
	char *str;
	int x[3], y[3], z[3];

	i = 0;
	total = 0;
	input = fetch_file("input", 1);

	str = strtok((char *)input.content, "\n");

	while (i < 3)
	{
		str += extract_num(str, &x[i]);
		str += extract_num(str, &y[i]);
		str += extract_num(str, &z[i]);
		str = strtok(NULL, "\n");
		i++;
	}
	i = 0;
	((x[0] + x[1]) > x[2] && (x[2] + x[1]) > x[0] && (x[0] + x[2]) > x[1]) ? (total += 1) : (NULL);
	((y[0] + y[1]) > y[2] && (y[2] + y[1]) > y[0] && (y[0] + y[2]) > y[1]) ? (total += 1) : (NULL);
	((z[0] + z[1]) > z[2] && (z[2] + z[1]) > z[0] && (z[0] + z[2]) > z[1]) ? (total += 1) : (NULL);

	while (str != NULL) // Checking if str == NULL fails. I must be misunderstanding strtok
	{
		i = 0;
		while (i < 3)
		{
			str += extract_num(str, &x[i]);
			str += extract_num(str, &y[i]);
			str += extract_num(str, &z[i]);
			str = strtok(NULL, "\n");
			i++;
		}
		((x[0] + x[1]) > x[2] && (x[2] + x[1]) > x[0] && (x[0] + x[2]) > x[1]) ? (total += 1) : (NULL);
		((y[0] + y[1]) > y[2] && (y[2] + y[1]) > y[0] && (y[0] + y[2]) > y[1]) ? (total += 1) : (NULL);
		((z[0] + z[1]) > z[2] && (z[2] + z[1]) > z[0] && (z[0] + z[2]) > z[1]) ? (total += 1) : (NULL);
			i++;
		printf("__________________ %d\n", total);
	}
}
