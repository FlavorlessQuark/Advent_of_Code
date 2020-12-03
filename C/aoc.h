#ifndef AOC_H
# define AOC_H

# include <CommonCrypto/CommonDigest.h>
# include <regex.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>
# include <string.h>
# include <assert.h>
# include <stddef.h>
# include <math.h>
# include <ctype.h>
# include <math.h>

# define ABC_U	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define ABC_L	"abcdefghijklmnopqrstuvwxyz"
# define HEX_L	"0123456789abcdef"
# define HEX_U	"0123456789ABCDEF"
# define MATHC	"()x*"
# define NUMS	"-0123456789"
# define NMATHC	"0123456789-+()x*=/ "

# define _HIDDEN_ __attribute__((visibility("hidden")))
# define _INTERN_ __attribute__((visibility("internal")))

/////------------ Structs ------------\\\\\

typedef struct		s_list
{
	void			*data;

	struct s_list	*next;
}					_Node;

typedef struct	data
{
	size_t		filesize;
	char		*content;
}				_File;

typedef struct	vect
{
				int x;
				int y;
}				_V2;

void 	*_tmp_ptr;
int		_tmp_int;
/////------------ Utilities functions------------\\\\\

// ADD count numbers for : list, char *;

static inline void swap (char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static inline void	_printbool(bool *lst, size_t len){size_t i; i = 0; while (i < len) {printf("%d ", lst[i]);  i++;} putchar('\n');}

static inline void	_printnum(int *list, size_t len){size_t i; i = 0; while (i < len) {printf("%d ", list[i]); i++;} putchar('\n');}

static inline int	numlen(int num){int len; if (num == 0) {return 1;}len = log10(abs(num)) + 1; return (num < 0) ? (len + 1) : (len);}

static inline int	extract_num(char *str, int *number) {int spn = strcspn(str, NUMS); *number = atoi(str + spn); return spn + numlen(*number);}

static inline char	*join(char *s1, char *s2){ size_t len = strlen(s1) + strlen(s2) + 1; char* str; str = calloc(len, 1); snprintf(str, len,  "%s%s", s1,s2);return str;}

static inline int	count_occurence(char *str, char *c){int count = 0; while((str = strstr(str, c) != NULL){count++;} return count;}

# define _DEBUG_(msg, ...) fprintf(stderr, "\033[1;91m[LOG](%s:%d) >>\033[0m "msg"\n", __FILE__, __LINE__, ##__VA_ARGS__)

/////------------ Macros ------------\\\\\

# define MAX(x, y)\
	({__typeof__ (x) _x = (x);\
	__typeof__ (y) _y = (y);\
	_x < _y ? _y : _x;})

# define MIN(x, y)\
	({__typeof__ (x) _x = (x);\
	__typeof__ (y) _y = (y);\
	_x > _y ? _y : _x;})

void _intp_	(int *ptr, size_t len)	{size_t i; i = 0;while (i < len) {printf("%d\n", ptr[i]); i++;};}
void _boolp_(bool *ptr, size_t len)	{size_t i; i = 0;while (i < len) {ptr[i] == true ? printf("True\n") : printf("False\n"); i++;}}
void _vectp_(_V2 **ptr, size_t len)	{size_t i; i = 0; while (i < len) {printf("(%d,%d)\n", ptr[i]->x, ptr[i]->y); i++;}}
void _nodep_(_Node *ptr, size_t len){while (ptr != NULL){printf("%s\n", ptr->data);ptr = ptr->next;}}
void _defp_	(void *ptr, size_t len)	{_DEBUG_("PRINTING WITH UNDEFINED TYPE (likely char *, use printf you moron)");}


# define _PRINT_1D(array, size) _Generic((array),\
	int		*: _intp_ ((int  *)array, size),\
	bool	*: _boolp_((bool *)array, size),\
	_Node	*: _nodep_((_Node *)array, size),\
	_V2		**: _vectp_((_V2 **)array, size),\
	default	 : _defp_ (array, size))

/////------------ CMP functions ------------\\\\\

int		int_CmpLess		(void *a, void *b){return (int *)a < (int *)b;}
int		int_CmpLessEq	(void *a, void *b){return (int *)a > (int *)b;}
int		int_CmpGreater	(void *a, void *b){return (int *)a <= (int *)b;}
int		int_CmpGreaterEq(void *a, void *b){return (int *)a >= (int *)b;}
int		int_CmpEq		(void *a, void *b){return (int *)a == (int *)b;}

int		str_CmpLess		(void *a, void *b){return strcmp((char *)a, (char *)b);}
int		str_CmpGreater	(void *a, void *b){return strcmp((char *)a, (char *)b) * - 1;}


/////------------ String functions ------------\\\\\
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
		while (i >= 0 && i <= len) {str[i + step] = str[i];i -= step;}
		shift--;
	}
	(step == 1) ? (str[0] = last) : (str[len - 1] = last);
}

/////------------ Sorting algorithms ------------\\\\\

//Merge two sorted lists.
_HIDDEN_ static _Node		*_lstSort_(_Node *h1, _Node *h2, int(*cmp_func)(void *, void *))
{
	_Node head, *list;

	list = &head;
	list->next = NULL;
	while (1)
	{
		if (h1 == NULL) {list->next = h2;break ;}
		if (h2 == NULL) {list->next = h1;break ;}
		if (cmp_func(&h1->data, &h2->data) <= 0) {list->next = h1;h1 = h1->next;}
		else {list->next = h2; h2 = h2->next;}
		list = list->next;
	}
	return head.next;
}

//List Merge Sort
static inline _Node *lstMsort(_Node *head, int len, int(*cmp_func)(void *, void *))
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

		h1	 =	lstMsort(h1,(len / 2), cmp_func);
		h2	 =	lstMsort(h2, (len / 2), cmp_func);
		head =	_lstSort_(h1, h2, cmp_func);
	}
	return head;
}

/////------------ List functions ------------\\\\\

//List search

//Returns a new node;
static inline	_Node	*list_node() {return (_Node *)calloc(1 , sizeof(_Node));}

static inline	_Node	*list_last(_Node *head) {while(head->next != NULL)head = head->next;return head;}

static			_Node	*list_search(_Node *list, char *str)
{
	while (list != NULL)
	{
		if (!strcmp(list->data, str))
			return list;
		list = list->next;
	}
	return NULL;
}


/////------------ Conversion functions ------------\\\\\

//Here : list to array | arra to list by type : char *, int *, char **, int**;

/////------------ Parsing functions ------------\\\\\

// Returns a list of words from str, separated by delimiters

// Reads file into _File struct.
static _File		fetch_input_raw(char *filename, int trim)
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

static int			fetch_input(char *filename, char **dest)
{
	_File file;

	file = fetch_input_raw(filename, 1);
	_tmp_int = count_occurence(file.content, '\n');

	// *dest = malloc(sizeof(char) * _tmp_int + 1);
	//ARRAY ALLOC HERE
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
