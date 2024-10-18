#ifndef DICT_H
#define DICT_H

#include "dict_adt.h"

#define ALPHABET 26

/*typedef struct dict_entry {
    char *key;
    int value;
} dict_entry;

typedef struct array_dict {
    dict_entry entries[DICT_SIZE];
    int size;
} array_dict;
*/

typedef struct TrieNode{
	int value;
	struct TrieNode *children[ALPHABET];
}TrieNode;

void print_dict_helper(Dict , char *, int ); 

#endif
