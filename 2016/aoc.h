#ifndef AOC_H
# define AOC_H

// # include <CommonCrypto/CommonDigest.h>
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

#define TRUE 1
#define FALSE 0
// Structs here

typedef struct	s_list
{
	struct s_list *next;
	void *data;
}				_Node;

typedef struct	data
{
	size_t filesize;
	char *content;
}				_File;

typedef struct	vect
{
	int x;
	int y;
}			_V2;

/////------------ Macros ------------\\\\\

# define MAX(x, y)\
	({__typeof__ (x) _x} = (x);\
	({__typeof__ (y) _y} = (y);\
	_x < _y ? _y : _x;})

# define MIN(x, y)\
	({__typeof__ (x) _x} = (x);\
	({__typeof__ (y) _y} = (y);\
	_x > _y ? _y : _x;})

# define POW2(x)\

/////----------- Sortung Functions -----------\\\\

int sortAscending(void *a, void *b) {return *(int *)a - *(int *)b;};
int sortDescending(void *a, void *b) {return *(int *)b - *(int *)a;};


/////------------ Numbers functions------------\\\\\

int		numlen(int num){int len; if (num == 0) {return 1;}len = log10(abs(num)) + 1; return (num < 0) ? (len + 1) : (len);}

char	*itoa(int number){char *str; str = malloc(numlen(number) + 1); sprintf(str,"%d", number); return str;}

int		extract_num(char *str, int *number) {int spn = strcspn(str, NUMS); *number = atoi(str + spn); return spn + numlen(*number);}
//Not very efficient but works for current purposes

/////------------ String functions ------------\\\\\

//Joins two strings together
char	*join(char *s1, char *s2)
{
	size_t len = strlen(s1) + strlen(s2) + 1;
	char* str;
	str = calloc(len, 1);
	snprintf(str, len,  "%s%s", s1,s2);
	return str;
}

//Counts occurences of a char within a string
int		count(char *str, char c){int count = 0; while (*str++) {count += (*str == c) ? 1 : 0;} return count;}

//Rotates string left (negative shift) or right (positive shift)
void strshift(int shift, char *str)
{
	char last;
	size_t i,len;
	int step;

	step = (shift >= 0) ? 1 : -1;
	while (shift != 0)
	{
		(step == 1) ? (last = str[len - 1], i = len - 2) : (last = str[0], i = 1);
		while (i >= 0 && i <= len)
		{
			str[i + step] = str[i];
			i -= step;
		}
		shift--;
	}
	(step == 1) ? (str[0] = last) : (str[len - 1] = last);
}

/////------------ Sorting algorithms ------------\\\\\

//Merge two sorted lists.
_Node *_lstSort(_Node *h1, _Node *h2)
{
	_Node head;
	_Node *list;

	list = &head;
	list->next = NULL;
	while (1)
	{
		if(h1 == NULL)
		{
			list->next = h2;
			break ;
		}
		if (h2 == NULL)
		{
			list->next = h1;
			break ;
		}
		if (atol(h1->data) <= atol(h2->data))
		{
			list->next = h1;
			h1 = h1->next;
		}
		else
		{
			list->next = h2;
			h2 = h2->next;
		}
		list = list->next;
	}
	return head.next;
}

//List Merge Sort
_Node *lstMsort(_Node *head, int len)
{
	_Node *h1;
	_Node *h2;
	int i;

	h1 = head;
	i = 0;
	if (len >= 2)
	{
		while (h1->next != NULL && i < (len / 2) - 1)
		{
			h1 = h1->next;
			i++;
		}
		h2 = h1->next;
		h1->next = NULL;
		h1 = head;

		h1 = lstMsort(h1,(len / 2));
		h2 = lstMsort(h2, (len / 2));
		head = _lstSort(h1, h2);
	}
	return head;
}

/////------------ List functions ------------\\\\\

//Returns a new node;
_Node *new_node() {_Node *node; node = calloc(1 , sizeof(_Node)); return node;}

void _printlst(_Node *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", lst->data);
		lst = lst->next;
	}
}

// char *strrev(char *str, int start, int end)
// {
// 	if (end == NULL)
// 		end = strlen(str);
// 	while (start < end)
// 	{
// 		swapi(&str[start], &str[end]);
// 		start++;
// 		end--;
// 	}
// 	return str;
// }
/////------------ Parsing functions ------------\\\\\

// Returns a list of words from str, separated by delimiters
_Node *fetch_words(char  *str, char *delimeters, size_t *len)
{
	_Node *list;
	_Node *head;

	head = new_node();
	list = head;

	str = strtok(str, delimeters);
	while (1)
	{
		*len += 1;
		list->data = (void *)str;
		str = strtok(NULL, delimeters);
		if (str == NULL)
			break ;
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

// Reads input file into a list of words. Words are sperated by *delimeter
_Node *fetch_by_word(char *filename, char *delimeters, int trim, size_t *len)
{
	_File	data;
	_Node	*list;
	char	*str;

	*len = 0;
	data = fetch_file(filename, trim);
	list = fetch_words(data.content, delimeters, len);
	return list;
}

/////------------ MD5 functions ------------\\\\\

// void format_hash(unsigned char hash[16], char *final)
// {
// 	int n = 0;
// 	char str[3];

// 	for (size_t i = 0; i < 16; ++i)
// 	{
// 		sprintf(str,"%.2x", hash[i]);
// 		final[n] = str[0];
// 		n++;
// 		final[n] = str[1];
// 		n++;
// 	}
// }

// void get_new_hash(char *input, char *hash)
// {
// 	unsigned char result[CC_MD5_DIGEST_LENGTH];

// 	CC_MD5(input, strlen(input), result);
// 	format_hash(result, hash);
// }

#endif
