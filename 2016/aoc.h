#ifndef AOC_H
# define AOC_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>
# include <string.h>

// #include <regex.h> Not sure where this file is or where to get it.
// I suspect that it is simply not available on WSL, but I would need to check on a VM
// In the meantime I will do without

# define ABC_U "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define ABC_L "abcdefghijklmnopqrstuvwxyz"

// Structs here

struct list;
typedef struct list node;

typedef struct	list
{
	void *data; // Conversion to char * does not seem to work. atoi() considers this a void * even when cast to char *
	node *prev;
	node *next;
}				node;

typedef struct
{
	long filesize;

	char *content;
}				_File;

typedef struct
{
	int x;
	int y;
}			_V2;

// List functions


node *new_node() {node *node; node = calloc(1, sizeof(node)); return node;}

// Parsing functions

int count(char *str, char c){ int count = 0; while (str++) {count += (*str == c) ? 1 : 0;}}

node *get_words(char  *str, char *delimeters, int *len)
{
	node *list;
	node *head;

	head = calloc(1, sizeof(node));
	list = head;

	str = strtok(str, delimeters);
	while (str != NULL)
	{
		*len++;
		list->data = (void *)str;
		list->next = new_node();
		list->next->prev = list;
		list = list->next;
		str = strtok(NULL, delimeters);
	}
	list->next = NULL;
}

// Reads file into _File struct.

_File fetch_file(char *filename, int trim)
{
	FILE	*file;
	_File	data;

	file = fopen(filename, "r");
	fseek(file, 0L , SEEK_END);
	// printf("good here \n");

	data.filesize = ftell(file);
	data.content = calloc(data.filesize + 1, 1);

	rewind(file);
	fread(data.content, data.filesize - trim, 1, file);
	fclose(file);
	return data;
}

// Reads input file into a list of words. Words are sperated by *delimeter
// Need to use an int trim if the input has unwanted newlines... Though it might not be necessary
// int *len needed to retrive the number of words without having to traverse the list

node *fetch_by_word(char *filename, char *delimeters, int trim, int *len)
{
	_File	data;
	node	*list;
	char	*str;

	*len = 0;
	data = fetch_file(filename, trim);

	list = get_words(((char *)data.content), delimeters, len);

	return list;
}


// void	fetch_by_grid(char *filename, char *delimiter, int trim)
// {
// 	_File file;
// 	int len;

// 	file = fetch_by_word(filename, delimiter, )

// }

#endif
