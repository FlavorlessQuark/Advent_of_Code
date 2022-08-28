#include "../../aoc.h"

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
	while (i < 40000000)
	{
		A = (A * 16807) % 2147483647;
		B = (B * 48271) % 2147483647;
		if ((short)A == (short)B)
			pairs++;
		i++;
	}
	printf("Solution : %d\n", pairs);
}
