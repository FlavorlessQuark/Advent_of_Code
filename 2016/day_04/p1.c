#include "../aoc.h"

int compareChecksums(int *expected, char *given)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if ((expected[i] + 97) != given[i])
			return FALSE;
		i++;
	}
	return TRUE;
}

void buildChecksum (int *dest, int *alphabet)
{
	int i;
	int current;
	int hold;

	i = 0;
	memset(dest, 0, sizeof(int));
	current = 0;
	while (i < 5)
	{
		hold = 0;
		current = 0;
		while (current < 26)
		{
			if (alphabet[current] && alphabet[current] > alphabet[hold])
			{
				hold = current;
			}
			current++;
		}
		dest[i] = hold;
		alphabet[hold] = 0;
		i++;
	}
	i = 0;
	printf("Sector ID : [");
	while (i < 5)
	{
		printf("%c", dest[i] + 97);
		i++;
	}
	printf("]\n");
}

int isRealRoom(char *str)
{
	int alphabet[26];
	int Checksum[5];
	int i;

	i = 0;
	memset(alphabet, 0, 26 * sizeof(int));
	while (str[i] != '[')
	{
		if (isalpha(str[i]))
			alphabet[str[i] - 97]++;
		i++;
	}

	buildChecksum(Checksum, alphabet);
	return compareChecksums(Checksum, str + i + 1);
}

int main()
{
	char *room;
	_Node *lines;
	size_t fileLen;
	int total;
	int SectorId;

	total = 0;
	lines = fetch_by_word("input", "\n", 1, &fileLen);
	while (lines)
	{
		printf("%s\n", lines->data);
		if (isRealRoom(lines->data) == TRUE)
		{
			printf("Real room\n");
			extract_num(lines->data, &SectorId);
			printf("Adding sector ID %d ...\n\n", SectorId);
			total += SectorId;
		}
		else
			printf("Fake room\n\n");
		lines = lines->next;
	}
	printf("Total is %d\n", total);
	return 0;
}
