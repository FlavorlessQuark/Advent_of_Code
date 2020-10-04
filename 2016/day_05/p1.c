# include "../aoc.h"
# include <openssl/md5.h>
// This is the same as 2015 ...?

int main()
{
	unsigned char input[] = "abbhdwsy";
	int found, i;
	char pass[8];
	unsigned char *result;

	result = malloc(MD5_DIGEST_LENGTH);

	i = 0;
	while (1)
	{
		strspn(MD5(input, 3, result), '0');
		if(sprintf(result, "%d%s", input,i) == 5)
		{
			pass[found] = result[6];
			found++;
		}
		if (found == 8)
			break ;
		i++;
	}
	print("Result : %s", pass);
}
