#ifndef AOC_H
# define AOC_H

# include <CommonCrypto/CommonDigest.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>
# include <string.h>
# include <assert.h>
# include <stddef.h>
# include <math.h>
# include <ctype.h>

// #include <regex.h> Not sure where this file is or where to get it.
// I suspect that it is simply not available on WSL, but I would need to check on a VM
// In the meantime I will do without

# define ABC_U	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define ABC_L	"abcdefghijklmnopqrstuvwxyz"
# define MATHC	"()x*"
# define NUMS	"0123456789"
# define NMATHC	"0123456789-+()x*=/ "
// Structs here

typedef struct	s_list
{
	struct s_list *next;
	void *data; // Conversion to char * does not seem to work. atoi() considers this a void * even when cast to char *
}				_Node;

typedef struct	data
{
	long filesize;

	char *content;
}				_File;

typedef struct	vect
{
	int x;
	int y;
}			_V2;

// Misc
# define MAX(x, y)\
	({__typeof__ (x) _x} = (x);\
	({__typeof__ (y) _y} = (y);\
	_x < _y ? _y : _x;})

char	*join(char *s1, char *s2){ char* str = malloc(strlen(s1) + strlen(s2) + 1); return strcat(strcpy(str, s1), s2);}

int		count(char *str, char c){int count = 0; while (str++) {count += (*str == c) ? 1 : 0;} return count;}

int		numlen(int num){int len; if (num == 0) {return 1;}len = log10(abs(num)) + 1; return (num < 0) ? (len + 1) : (len);}

char	*itoa(int number){char *str; str = malloc(numlen(number) + 1); sprintf(str,"%d", number); return str;}

int		extract_num(char *str, int *number) {int spn = strcspn(str, NUMS); *number = atoi(str + spn); return spn + numlen(*number);}
//Not very efficient but works for current purposes

// List functions

//Returns a new node;
_Node *new_node() {_Node *node; node = malloc(1 * sizeof(_Node)); return node;}

// Parsing functions

// Returns a list of words from str, separated by delimiters
_Node *fetch_words(char  *str, char *delimeters, int *len)
{
	_Node *list;
	_Node *head;

	head = new_node();
	list = head;

	str = strtok(str, delimeters);
	while (str != NULL)
	{
		*len += 1;
		list->data = (void *)str;
		str = strtok(NULL, delimeters);
		list->next = new_node();
		list = list->next;
	}
	list->next = NULL;
	return head;
}


// Reads file into _File struct.
_File fetch_file(char *filename, int trim)
{
	FILE	*file;
	_File	data;

	file = fopen(filename, "r");
	fseek(file, 0L , SEEK_END);

	data.filesize = ftell(file);
	data.content = calloc(data.filesize + 1, 1);

	rewind(file);
	fread(data.content, data.filesize - trim, 1, file);
	fclose(file);
	return data;
}

// Need to use an int trim if the input has unwanted newlines... Though it might not be necessary
// int *len needed to retrive the number of words without having to traverse the list

// Reads input file into a list of words. Words are sperated by *delimeter
_Node *fetch_by_word(char *filename, char *delimeters, int trim, int *len)
{
	_File	data;
	_Node	*list;
	char	*str;

	*len = 0;
	data = fetch_file(filename, trim);

	list = fetch_words(data.content, delimeters, len);

	return list;
}

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

void get_new_hash(char *input, char *hash)
{
	unsigned char result[CC_MD5_DIGEST_LENGTH];

	CC_MD5(input, strlen(input), result);
	format_hash(result, hash);
}
// void	fetch_by_grid(char *filename, char *delimiter, int trim)
// {
// 	_File file;
// 	int len;

// 	file = fetch_by_word(filename, delimiter, )

// }

#endif
