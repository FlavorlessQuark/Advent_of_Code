# include "../aoc.h"
# include <CommonCrypto/CommonDigest.h> //Only for OSX
// This is the same as 2015 ...?

void format_hash(unsigned char hash[16], char *final)
{
	int n = 0;
	char str[3];

	for (size_t i = 0; i < 16; ++i)
	{
		sprintf(str,"%.2x", hash[i]);
		final[n] = str[0];
		n++;
		final[n] = str[1];
		n++;
	}
}

int main()
{
	int found, i, count;
	char pass[8];
	char *input;
	char *encode;
	char *tmp;
	char *countstr;

	unsigned char result[CC_MD5_DIGEST_LENGTH];
	CC_MD5_CTX context;


	input = join("", "abbhdwsy");
	encode = calloc(32, 1);
	count = 0;
	CC_MD5(input, strlen(input), result);
	format_hash(result, encode);

	pass[0] = '-';
	pass[1] = '-';
	pass[2] = '-';
	pass[3] = '-';
	pass[4] = '-';
	pass[5] = '-';
	pass[6] = '-';
	pass[7] = '-';

	while (1)
	{
		i = strspn(encode, "0");
		if (i >= 5)
		{
			if (isdigit(encode[5]) && encode[5] - 48 < 8 && pass[encode[5] - 48] == '-')
			{
				printf("encode %s %d\n", encode, count);
				pass[encode[5] - 48] = encode[6];
				found++;
			}
		}
		if (found == 8)
			break ;
		tmp = join(input, itoa(count));
		CC_MD5(tmp, strlen(tmp), result);
		format_hash(result, encode);

		count++;
	}
	printf("Result : %s\n", pass);
}
