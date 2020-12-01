# include "../aoc.h"
# include <CommonCrypto/CommonDigest.h> //Only for OSX

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

int	count_sequence(int occurence, char c, char *str)
{
	int i;

	i = 0;
	while (1)
	{
		if (!(str = strchr(str, c)))
			return 0;
		if ((i = strspn(str, &c)) == occurence)
			return 1;
		str += i;
	}
	return 0;
}

int check_triple(char *str, char *c)
{
	for (size_t i = 1; i < 32; ++i)
	{
		if (str[i] == str[i - 1]  && str[i] == str[i + 1])
		{
			*c = str[i];
			return 1;
		}
	}
	return 0;
}

void get_new_hash(int hash_num, char *hash)
{
	char *tmp;
	char input[] = "abc";
	unsigned char result[CC_MD5_DIGEST_LENGTH];

	tmp = join(input, itoa(hash_num));
	CC_MD5(tmp, strlen(tmp), result);
	format_hash(result, hash);
}

void stretch_hash(char *hash)
{
	unsigned char result[CC_MD5_DIGEST_LENGTH];

	for (size_t i = 0; i < 2017; i++)
	{
		CC_MD5(hash, strlen(hash), result);
		format_hash(result, hash);
	}
}

int check_next(char c, int hash_num, char *hash)
{
	int i;

	i = 1;
	while (i < 1001)
	{
		get_new_hash(hash_num + i, hash);
		if (count_sequence(5, c, hash) == 1)
			return 1;
		i++;
	}
	return 0;
}


int main()
{
	int  i, hash_num;
	char c;
	char *hash;

	hash = calloc(32, 1);
	hash_num = 0;
	i = 0;

	while (i < 64)
	{
		get_new_hash(hash_num, hash);
		stretch_hash(hash);
		if (check_triple(hash, &c))
			i += check_next(c, hash_num, hash);
		hash_num++;
	}

	printf("Result : %d %sn", hash_num - 1,  hash);
}
