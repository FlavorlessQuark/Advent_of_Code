#include "../../aoc.h"

//Reminiscent of the gates day in 2015...

# define OFFSET_TO_LOW_TARGET 14
# define OFFSET_TO_HIGH_TARGET 13

typedef struct s_bot
{
	int high;
	int low;
}				bot;

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
	// if (bot->low == )
}

int execValueInstruction(char *instruction, bot *bots)
{
	int botNumber;
	int value;

	printf("Excuting value instruction \n");
	instruction += extract_num(instruction, &value);
	extract_num(instruction, &botNumber);
	printf("before bot %d (low %d high %d)\n", botNumber, bots[botNumber].low, bots[botNumber].high);
	giveValToBot(value, &bots[botNumber]);
	// if (MAX(bots[botNumber].low, value) == value)
	// 	bots[botNumber].high = value;
	// else
	// {
	// 	bots[botNumber].high = bots[botNumber].low;
	// 	bots[botNumber].low = value;
	// }
	printf("after bot %d (low %d high %d)\n", botNumber, bots[botNumber].low, bots[botNumber].high);

	return TRUE;
}

int execBotInstruction(char *instruction, bot *bots, int *outputs)
{
	int botNumber;
	int lowTarget;
	int highTarget;
	int lowOffset;
	int highOffset;

	printf("Excuting bot instruction\n");
	lowOffset = extract_num(instruction, &botNumber) + OFFSET_TO_LOW_TARGET;
	highOffset= extract_num(instruction + lowOffset, &lowTarget) + lowOffset + OFFSET_TO_HIGH_TARGET;
	extract_num(instruction + highOffset, &highTarget);
	// printf("giver is bot %d (low %d high %d)\n", botNumber, bots[botNumber].low, bots[botNumber].high);
	if (bots[botNumber].low == -1 || bots[botNumber].high == -1)
		return FALSE;

	if (instruction[lowOffset] == 'b')
	{
		// printf("Low target is bot %d, gets value %d\n", lowTarget, bots[botNumber].low);
		giveValToBot(bots[botNumber].low, &bots[lowTarget]);
		bots[botNumber].low = -1;
	}
	else
	{
		// printf("Low target is output %d, gets value %d\n", lowTarget, bots[botNumber].low);
		outputs[lowTarget] = bots[botNumber].low;
		bots[botNumber].low = -1;
	}
	if (instruction[highOffset] == 'b')
	{
		// printf("high target is bot %d, gets value %d\n", highTarget, bots[botNumber].high);
		giveValToBot(bots[botNumber].high, &bots[highTarget]);
		bots[botNumber].high = -1;
	}
	else
	{
		// printf("high target is output %d, gets value %d\n", highTarget, bots[botNumber].high);
		outputs[highTarget] = bots[botNumber].high;
		bots[botNumber].high = -1;
	}
	return TRUE;
}

int execInstruction(char *instruction, bot *bots, int *outputs)
{
	int hold;
	int holdExtra;

	printf("exec %s\n", instruction);
	if (instruction[0] == 'v')
	{
		execValueInstruction(instruction, bots);
		return TRUE;
		// return execValueInstruction(instruction, bots);
	}
	else {
		return execBotInstruction(instruction, bots, outputs);
	}
}

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

int main()
{
	_Node *instructions;
	_Node *skip;
	_Node *head;
	bot *bots;
	int *outputs;
	size_t len;
	int maxNum;

	instructions = fetch_by_word("test", "\n", 1, &len);
	head = instructions;

	maxNum = getMaxNumber(instructions);
	bots = malloc(maxNum * sizeof(bot));
	outputs = calloc(maxNum,  sizeof(int));
	memset(bots, -1, maxNum * sizeof(int) * 2);

	printf("Max bot is %d and %d\n", maxNum, bots[3]);
	int i= 0;
	while (len)
	{
		if (instructions == NULL)
		{
			printf("\n\nUsing skipped instructions \n");
			instructions = head;
		}
		if (!execInstruction(instructions->data, bots, outputs))
		{
			printf("Couldnt execute\n");
			if (skip == NULL)
			{
				skip = instructions;
				head = skip;
			}
			else
			{
				skip->next = instructions;
				skip = skip->next;
			}
		}
		else {
			printf("Sucess\n");
			len--;
		}
		i = 0;

		printf("Instructions left %d\n\n", len);
		instructions = instructions->next;
	}
	len = 0;
	while (len < maxNum)
	{
		printf("Bot %d: (%d, %d) \t Output %d : %d\n", len, bots[len].low, bots[len].high, len, outputs[len] );
		len++;
	}

}
