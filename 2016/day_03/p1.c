#include "../aoc.h"


int main()
{
	_File input;
	int total;
	int x, y, z;
	int i;
	char *str;

	i = 1913;
	total = 0;
	input = fetch_file("input", 1);

	x = atoi(str = strtok((char *)input.content, " "));
	y = atoi(str = strtok(NULL, " "));
	z =  atoi(str = strtok(NULL, " \n"));
	((x + z) > y && (y + z) > x && (x + y) > z) ? (total += 1) : (NULL);
	
	while (i-- > 0) // Checking if str == NULL fails. I must be misunderstanding strtok
	{
		x = atoi(str = strtok(NULL, " "));
		y = atoi(str = strtok(NULL, " "));
		z =  atoi(str = strtok(NULL, " \n"));
		((x + z) > y && (y + z) > x && (x + y) > z) ? (total += 1) : (NULL);
	}
	printf("%d %s\n", total, str);
}
