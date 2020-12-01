# include "../aoc.h"

int main()
{
	int found, i, count;
	char pass[8] = {'-'};
	char *input;
	char *encode;


	input = join("", "abbhdwsy");
	encode = calloc(32, 1);
	count = 0;
	get_new_hash(input, encode);

	while (1)
	{
		i = strspn(encode, "0");
		if (i >= 5)
		{
			if (isdigit(encode[5]) && encode[5] - 48 < 8 && pass[encode[5] - 48] == '-')
			{
				pass[encode[5] - 48] = encode[6];
				found++;
			}
		}
		if (found == 8)
			break ;
		get_new_hash(join(input, itoa(count)), encode);
		count++;
	}
	printf("Result : %s\n", pass);
}
