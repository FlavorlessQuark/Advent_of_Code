#include "../aoc.h"

int main()
{
	node 	*input;
	_V2		pos;

	int 	len;
	int 	n;
	char 	keypad[5][5] = {{'5','X', '2','X','1'}, {'X','6', 'X','3','X'}, {'A','X','7','X','4'},{'X','B', 'X','8','X'},{'D','X', 'C','X','9'}};

	pos.x = 0;
	pos.y = 0;
	input = fetch_by_word("input", "\n", 1, &len);
	while (input->next)
	{
		n = 0;
		while(*(char *)&input->data[n])
		{
			if (*(char *)&input->data[n] == 'U')
			{
				if(pos.x + 1 <= 4 && pos.y - 1 >= 0 && keypad[pos.y + 1][pos.x + 1] != 'X')
				{
					pos.x++;
					pos.y--;
				}
			}
			else if (*(char *)&input->data[n] == 'L')
			{
				if(pos.x - 1 >= 0 && pos.y - 1 >= 0 && keypad[pos.y - 1][pos.x - 1] != 'X')
				{
					pos.x--;
					pos.y--;
				}
			}
			else if (*(char *)&input->data[n] == 'D')
			{
				if(pos.x - 1 >= 0 && pos.y + 1 <= 4 && keypad[pos.y + 1][pos.x + 1] != 'X')
				{
					pos.x--;
					pos.y++;
				}
			}
			else
			{
				if(pos.x + 1 <= 4 && pos.y + 1 <= 4 && keypad[pos.y + 1][pos.x + 1] != 'X')
				{
					pos.x++;
					pos.y++;
				}
			}
			n++;
		}
			printf("%c\n", keypad[pos.y][pos.x]);
		input = input->next;
	}
}
