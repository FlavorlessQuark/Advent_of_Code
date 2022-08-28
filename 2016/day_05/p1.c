# include "../aoc.h"
// This is the same as 2015 ...?


int main()
{
	int found, i, count;
	char pass[8];
	char *input;
	char *encode;

	input = join("", "abc");
	encode = calloc(32, 1);
	count = 0;
	get_new_hash(input, encode);
	while (1)
	{
		i = strspn(encode, "0");
		if (i == 5)
		{
			pass[found] = encode[5];
			found++;
		}
		if (found == 8)
			break ;
		get_new_hash(join(input, itoa(count)), encode);
		count++;
	}
	printf("Result : %s\n", pass);
}
