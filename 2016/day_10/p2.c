#include "../../aoc.h"

# define OFFSET_TO_LOW_TARGET 14
# define OFFSET_TO_HIGH_TARGET 13
typedef struct s_bot
{
	int high;
	int low;
	int given;
	char *instruction;
}				bot;


void execGiveInstruction(int botId, bot *bots, int * outputs);


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

void printBotsAndOutputs(bot *bots, int *outputs, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		printf("Bot %d (%d, %d) | output %d : %d\n", i, bots[i].low, bots[i].high, i, outputs[i]);
		i++;
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
			instructions->data +=  extract_num(instructions->data, &botID);
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

void checkBotAndExec(int botId, bot *bots, int * outputs)
{
	if (bots[botId].low > -1 && bots[botId].high > -1)
		execGiveInstruction(botId, bots, outputs);
}

void execValueInstruction(char *instruction, bot *bots, int *outputs)
{
	int value;
	int botId;

	instruction += extract_num(instruction, &value);
	extract_num(instruction, &botId);
	giveValToBot(value, &bots[botId]);
	checkBotAndExec(botId, bots, outputs);
}

void execGiveInstruction(int botId, bot *bots, int * outputs)
{
	int id;
	int offset;
	char *instruction;

	instruction = bots[botId].instruction;
	offset = extract_num(instruction, &id);

	printf("\nExec bot %d : %s\n", botId, instruction);
	if (instruction[OFFSET_TO_LOW_TARGET] == 'o')
		outputs[id] = bots[botId].low;
	else
	{
		giveValToBot(bots[botId].low, &bots[id]);
		checkBotAndExec(id, bots, outputs);
	}
	bots[botId].low = -1;


	instruction += offset;
	extract_num(instruction, &id);

	if (instruction[OFFSET_TO_HIGH_TARGET] == 'o')
		outputs[id] = bots[botId].high;
	else
	{
		giveValToBot(bots[botId].high, &bots[id]);
		checkBotAndExec(id, bots, outputs);
	}
	bots[botId].high = -1;
}

int main()
{
	_Node *instructions;
	bot *bots;
	_Node *valueInstructions;
	int *outputs;
	size_t len;
	int maxNum;

	instructions = fetch_by_word("input", "\n", 1, &len);

	maxNum = getMaxNumber(instructions) + 1;
	bots = malloc(maxNum * sizeof(bot));
	outputs = calloc(maxNum,  sizeof(int));

	valueInstructions = formatBotsAndInstructions(instructions, bots);

	while(valueInstructions)
	{
		printf("%s\n", valueInstructions->data);
		execValueInstruction(valueInstructions->data, bots, outputs);
		valueInstructions = valueInstructions->next;
	}
	printf("Value %d\n", outputs[0] * outputs[1] * outputs[2]);
}
