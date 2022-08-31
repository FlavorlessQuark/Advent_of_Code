#include "../../aoc.h"


typedef struct s_bot
{
	int high;
	int low;
	int given;
	char *instruction;
}				bot;

int getMaxNumber(_Node *list)
{
	char *instruction;
	int offset;
	int max;
	int number;

	max = 0;
	while (list)
	{
		instruction = list->data;
		offset = 0;
		while (instruction[offset] != '\0')
		{
			offset += extract_num(instruction + offset, &number);
			max = MAX(max, number);
		}
		list = list->next;
	}
	return max;
}

void giveValToBot(int val, bot *bot)
{
	if (MAX(bot->high, val) == val)
	{
		bot->low = bot->high;
		bot->high = val;
	}
	else
	{
		bot->high = MAX(bot->low, bot->high);
		bot->low = val;
	}
}

_Node *formatBotsAndInstructions(_Node *instructions, bot *bots)
{
	_Node *head;
	_Node *valInstructions;
	int botID;

	head = NULL;
	while (instructions)
	{
		printf("??? %p %p\n",instructions, instructions->next);
		if (((char *)instructions->data)[0] =='v')
		{
			if (!head)
			{
				head = instructions;
				valInstructions = head;
			}
			else
			{
				valInstructions->next = instructions;
				valInstructions = valInstructions->next;
			}
		}
		else
		{
			extract_num(instructions->data, &botID);
			bots[botID].instruction = instructions->data;
			bots[botID].low = -1;
			bots[botID].high = -1;
			bots[botID].given = 0;
		}
		instructions = instructions->next;
	}
	valInstructions->next = NULL;
	return head;
}

int main()
{
	_Node *instructions;
	bot *bots;
	_Node *valueInstructions;
	int *outputs;
	size_t len;
	int maxNum;

	instructions = fetch_by_word("test", "\n", 1, &len);

	maxNum = getMaxNumber(instructions);
	bots = malloc(maxNum * sizeof(bot));
	outputs = calloc(maxNum,  sizeof(int));

	valueInstructions = formatBotsAndInstructions(instructions, bots);

	while(valueInstructions)
	{
		printf("%s\n", valueInstructions->data);
		valueInstructions = valueInstructions->next;
	}
	int i = 0;
	while(i < maxNum)
	{
		printf("Bot %d : %s  | output %d %d\n", i, bots[i].instruction, i , outputs[i]);
		i++;
	}
}
