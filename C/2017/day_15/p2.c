#include "../../aoc.h"

long getval(long input, int mult, int key)
{
	while ((input = ((input * key) % 2147483647)) % mult)
	;
	return input;
}

int main()
{
	_File file;
	long A;
	long B;
	int a;
	int b;
	int pairs;
	size_t i;
	file = fetch_file("input", 1);

	i = 0;
	pairs = 0;
	extract_num(file.content + extract_num(file.content, &a), &b);
	A = a;
	B = b;
	while (i < 5000000)
	{
		A = getval(A, 4, 16807);
		B = getval(B, 8, 48271);
		if ((short)A == (short)B)
			pairs++;
		i++;
	}
	printf("Solution : %d\n", pairs);
}
