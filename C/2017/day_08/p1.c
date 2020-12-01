#include "../../aoc.h"

typedef struct r_node
{
	char *name;
	int val;

	struct r_node *next;
}				Reg;

Reg *newreg(char *name)
{
	Reg *new;

	new = calloc(1, sizeof(Reg));
	new->name = name;
	new->val = 0;
	new->next = NULL;
	return new;
}

void get_max(Reg *reg)
{
	int max = reg->val;

	while (reg != NULL)
	{
		if (reg->val > max)
			max = reg->val;
		reg = reg->next;
	}
	printf("Solution: %d\n", max);
}

Reg *find(Reg *head, char *name)
{
	while (head != NULL)
	{
		if (!(strcmp(head->name, name)))
			return head;
		head = head->next;
	}
	return head;
}

static	void	_printrg(Reg *reg)
{
	while (reg != NULL)
	{
		printf("%s %d\n", reg->name, reg->val);
		reg = reg->next;
	}
}

bool condition(Reg *reg, char *condition)
{
	char *part;
	int cmp;

	extract_num(condition, &cmp);
	part = strtok(condition, " ");
	reg = find(reg, part);
	part = strtok(NULL, " ");

	if (!(strcmp(part, ">")) &&  reg->val > cmp)
		return true;
	else if (!(strcmp(part, ">=")) &&  reg->val >= cmp)
		return true;
	else if (!(strcmp(part, "<")) &&  reg->val < cmp)
		return true;
	else if (!(strcmp(part, "<=")) &&  reg->val <= cmp)
		return true;
	else if (!(strcmp(part, "==")) &&  reg->val == cmp)
		return true;
	else if (!(strcmp(part, "!=")) &&  reg->val != cmp)
		return true;

	if (part[0] == 'i')
		reg->val += cmp;
	else if (part[0] == 'd')
		reg->val -= cmp;
	return false;
}


int main()
{
	_Node *input;
	_Node *ihead;
	Reg *registers;
	Reg *head;
	size_t len;
	char *name;

	input = fetch_by_word("input", "\n", 1, &len);
	ihead = input;
	registers = newreg("start");
	head = registers;
	while (input != NULL)
	{
		name = join("", input->data);
		name = strtok(name, " ");
		if (find(head, name) == NULL)
		{
			registers->next = newreg(name);
			registers = registers->next;
		}
		input = input->next;
	}
	head = head->next;
	input = ihead;

	char *instruction;
	int val;
	while (input != NULL)
	{
		if (condition(head, input->data + extract_num(input->data, &val) + 4))
			condition(head, input->data);
		input = input->next;
	}
	get_max(head);
}
