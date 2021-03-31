#include "../../aoc.h"


int	main()
{
	int len;
	int sound;
	int reg[26] = {0};
	int i;
	int isnum;
	int num;
	char **input;

	len = fetch_input("input", &input, "\n");

	i = 0;
	while (1 && i >= 0 && i < len)
	{
		isnum = extract_num(input[i], &num);
		if (input[i][1] == 'n')
			sound = reg[input[i][4] - 97];
		else if (input[i][1] == 'e')
		{
			if (isnum)
				 reg[input[i][4] - 97] = num;
			else
				 reg[input[i][4] - 97] =  reg[input[i][6] - 97];
		}
		else if (input[i][1] == 'd')
		{
			if (isnum)
				 reg[input[i][4] - 97] += num;
			else
				 reg[input[i][4] - 97] +=  reg[input[i][6] - 97];
		}
		else if (input[i][1] == 'u')
		{
			if (isnum)
				 reg[input[i][4] - 97] *= num;
			else
				 reg[input[i][4] - 97] *=  reg[input[i][6] - 97];
		}
		else if (input[i][1] == 'o')
		{
			if (isnum)
				 reg[input[i][4] - 97] %= num;
			else
				 reg[input[i][4] - 97] %=  reg[input[i][6] - 97];
		}
		else if (input[i][1] == 'c')
		{
			if (reg[input[i][4] - 97] != 0)
			{
				printf("Solution : %d\n", sound);
				break ;
			}
		}
		else if (input[i][1] == 'g')
		{
			if (reg[input[i][4] - 97] > 0)
			{
				if (isnum)
					i += num;
				else
					i +=  reg[input[i][6] - 97];
			}
		}
		printf("i %d, input %s, num %d rg %d\n", i, input[i], num, isnum );
		i++;
	}

}
