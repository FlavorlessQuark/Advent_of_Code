# include "../aoc.h"
# include <CommonCrypto/CommonDigest.h> //Only for OSX

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


int check_next(char c, int hash_num, char *hash)
{
	int i;

	i = 1;
	while (i < 1001)
	{
		get_new_hash(oin("yjdafjpo", itoa(hash_num + i)), hash);
		if (count_sequence(5, c, hash) == 1)
			return 1;
		i++;
	}
	return 0;
}


int main()
{
	int		i;
	int		hash_num;
	char	c;
	char	*hash;

	hash = calloc(32, 1);
	hash_num = 0;
	i = 0;

	while (i < 64)
	{
		get_new_hash(join("yjdafjpo", itoa(hash_num)), hash);
		if (check_triple(hash, &c))
			i += check_next(c, hash_num, hash);
		hash_num++;
	}

	printf("Result : %d %sn", hash_num - 1,  hash);
}
