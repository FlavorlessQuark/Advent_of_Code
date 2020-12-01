#include <stdio.h>

int main()
{
	int i;
	int result;
	i = 0;

	result = 2387;
	while (result > 0)
	{
		if (result & 1)
			i++;
		result >>= 1;
	}
	printf("%d ", i);
}
