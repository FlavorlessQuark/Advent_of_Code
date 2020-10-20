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
# include <stdbool.h>
# include <math.h>
# include <regex.h>

# define ABC_U	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define ABC_L	"abcdefghijklmnopqrstuvwxyz"
# define MATHC	"()x*"
# define NUMS	"-0123456789"
# define NMATHC	"0123456789-+()x*=/ "

/////------------ Structs ------------\\\\\

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
	({__typeof__ (x) _x = (x);\
	__typeof__ (y) _y = (y);\
	_x < _y ? _y : _x;})

# define MIN(x, y)\
	({__typeof__ (x) _x = (x);\
	__typeof__ (y) _y = (y);\
	_x > _y ? _y : _x;})

# define POW2(x)\

# define SWAP(x, y)\


/////------------ Number functions------------\\\\\

// ADD count numbers for : list, char *;

static inline void	_printnum(int *list, size_t len){size_t i; i = 0; while (i < len) {printf("%d ", list[i]); i++;} putchar('\n');}

static inline int	numlen(int num){int len; if (num == 0) {return 1;}len = log10(abs(num)) + 1; return (num < 0) ? (len + 1) : (len);}

static inline char	*itoa(int number){char *str; str = malloc(numlen(number) + 1); sprintf(str,"%d", number); return str;}

static inline int	extract_num(char *str, int *number) {int spn = strcspn(str, NUMS); *number = atoi(str + spn); return spn + numlen(*number);}

/////------------ String functions ------------\\\\\

static inline char	*join(char *s1, char *s2){ size_t len = strlen(s1) + strlen(s2) + 1; char* str; str = calloc(len, 1);snprintf(str, len,  "%s%s", s1,s2);return str;}

static inline int	count_occurence(char *str, char c){int count = 0; while (*str++) {count += (*str == c) ? 1 : 0;} return count;}

//Rotates string left (negative shift) or right (positive shift)
static inline void	strshift(int shift, char *str)
{
	char last;
	size_t i,len;
	int step;

	len = strlen(str);
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
static _Node		*_lstSort_(_Node *h1, _Node *h2)
{
	_Node head, *list;

	list = &head;
	list->next = NULL;
	while (1)
	{
		if (h1 == NULL) {list->next = h2;break ;}
		if (h2 == NULL) {list->next = h1;break ;}
		if (atol(h1->data) <= atol(h2->data)) {list->next = h1;h1 = h1->next;}
		else {list->next = h2; h2 = h2->next;}
		list = list->next;
	}
	return head.next;
}

//List Merge Sort
static inline _Node *lstMsort(_Node *head, int len)
{
	_Node	*h1, *h2;
	int		i;

	h1 = head;
	i = 0;
	if (len >= 2)
	{
		while (h1->next != NULL && i < (len / 2) - 1){h1 = h1->next;i++;}
		h2 = h1->next;
		h1->next = NULL;
		h1 = head;

		h1	 =	lstMsort(h1,(len / 2));
		h2	 =	lstMsort(h2, (len / 2));
		head =	_lstSort_(h1, h2);
	}
	return head;
}

/////------------ List functions ------------\\\\\

//List search

//Returns a new node;
static inline	_Node	*new_node() {return (_Node *)calloc(1 , sizeof(_Node));}

static inline	_Node	*get_last(_Node *head) {while(head->next != NULL)head = head->next;return head;}

static	_Node			*search_list(_Node *list, char *str)
{
	while (list != NULL)
	{
		if (!strcmp(list->data, str))
			return list;
		list = list->next;
	}
	return NULL;
}

static	void			_printlst(_Node *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", lst->data);
		lst = lst->next;
	}
}


/////------------ Conversion functions ------------\\\\\

//Here : list to array | arra to list by type : char *, int *, char **, int**;

static char *convert_intstr(int *array, size_t len, char *separator)
{
	size_t i;
	char *str;

	i = 0;
	str = "";
	while (1)
	{
		str = join(str, itoa(array[i]));
		i++;
		if (i >= len)
			break ;
		str = join(str, separator);
	}
	return str;
}

// static char			*strrev(char *str, int start, int end)
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
static _Node		*fetch_words(char  *str, char *delimeters, size_t *len)
{
	_Node *list;
	_Node *head;

	head = new_node();
	list = head;

	if (str == '\0')
		return NULL;
	str = strtok(str, delimeters);
	if (str == NULL)
		return NULL;
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
static _File		fetch_file(char *filename, int trim)
{
	FILE	*file;
	_File	data;

	file = fopen(filename, "r");
	fseek(file, 0L , SEEK_END);

	data.filesize	= ftell(file);
	data.content	= calloc(data.filesize + 1, 1);

	rewind(file);
	fread(data.content, data.filesize - trim, 1, file);
	fclose(file);
	return data;
}

// Reads input file into a list of words. Words are sperated by *delimeter
static _Node		*fetch_by_word(char *filename, char *delimeters, int trim, size_t *len)
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

static	void		format_hash(unsigned char hash[16], char *final)
{
	int n = 0;
	char str[3];

	for (size_t i = 0; i < 16; ++i)
	{
		sprintf(str,"%.2x", hash[i]);
		final[n] = str[0];
		final[n + 1] = str[1];
		n += 2;
	}
}

static inline void	get_new_hash(char *input, char *hash)
{
	unsigned char result[CC_MD5_DIGEST_LENGTH];
	CC_MD5(input, strlen(input), result);
	format_hash(result, hash);
}

#endif
