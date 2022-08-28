#include "../../aoc.h"

char shiftLetter(char letter, int shiftAmount)
{
	int shiftedLetter;

	shiftedLetter = letter; // adding shift amount may cause overflow so we put the letter in an int
	shiftedLetter += shiftAmount;
	while (shiftedLetter > 'z')
		shiftedLetter -= 26;

	return shiftedLetter;
}

int decryptRoom(char *room, int sectorID)
{
	int shift;
	int i;
	int current;

	i = 0;
	shift = sectorID % 26;
	while (room[i])
	{
		if (room[i] == '-')
		{
			room[i] = ' ';
		}
		else {
			room[i] = shiftLetter(room[i], shift);
		}
		i++;
	}
}

int main() {
	_Node *lines;
	size_t filesize;
	int sectorID;

	lines = fetch_by_word("input", "\n", 1, &filesize);

	while (lines)
	{
		extract_num(lines->data, &sectorID);
		decryptRoom((char *)lines->data, sectorID);
		if (((char *)(lines->data))[0] == 'n')
			printf("%s | %d\n", lines->data, sectorID);
		lines = lines->next;
	}
}
