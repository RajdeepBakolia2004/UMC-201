#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dict.h"

// Create an empty Dict
Dict make_dict() {
    TrieNode *dict = (TrieNode *) malloc(sizeof(TrieNode));
    if (dict == NULL) {
	return NULL;
    }
    dict->value = 0;
    for (int i = 0; i < ALPHABET; i++) {
	dict->children[i] = NULL;
    }
    return (Dict) dict;
}

// Free up all memory allocated to a Dict (including char* keys)
void free_dict(Dict dict_adt) {
    if (dict_adt != NULL) {
	TrieNode *dict = (TrieNode *) dict_adt;
	    for(int i = 0; i < ALPHABET; i++) {
		if (dict->children[i] != NULL) {
		    free_dict((Dict) dict->children[i]);
		}
	
	}
	free(dict_adt);
    }
}

// Get a pointer to the value associated with key
// (returns NULL if no such value exists)
int *get(Dict dict_adt, const char *key) {
    if (dict_adt == NULL) {
	return NULL;
    }
    TrieNode *dict = (TrieNode *) dict_adt;
    for (int i = 0; i < strlen(key); i++) {
	int index = key[i] - 'a';
	if (dict->children[index] == NULL) {
	    return NULL;
	}
	dict = dict->children[index];
    }


    return &(dict->value);
}

// Set the value associated with key to value
// while maintaining insertion order
// (returns 1 if successful, 0 if not)
int set(Dict dict_adt, const char *key, int value) {
    if (dict_adt == NULL) {
	return 0;
    }
    TrieNode *dict = (TrieNode *) dict_adt;
    for (int i = 0; i < strlen(key); i++) {
	int index = key[i] - 'a';
	if (dict->children[index] == NULL) {
	    dict->children[index] = (TrieNode *) malloc(sizeof(TrieNode));
	    if (dict->children[index] == NULL) {
		return 0; //additional heap memory can't be allocated
	    }
	    dict->children[index]->value = 0;
	    for (int j = 0; j < ALPHABET; j++) {
		dict->children[index]->children[j] = NULL;
	    }
	}
	dict = dict->children[index];
    }
    dict->value = value;
    return 1;
}

// Print the contents of the dictionary
void print_dict(Dict dict_adt){
	if (dict_adt == NULL) {
		return;
	}
	TrieNode *dict = (TrieNode *) dict_adt;
	char buffer[101];
	print_dict_helper(dict, buffer, 0);
}

// Helper function to print the contents of the dictionary
void print_dict_helper(Dict dict_adt, char *buffer, int index) {
	TrieNode *dict = (TrieNode *) dict_adt;
	for (int i = 0; i < ALPHABET; i++) {
		if (dict->children[i] != NULL) {
			buffer[index] = i + 'a';
			print_dict_helper(dict->children[i], buffer, index + 1);
		}
	}
	buffer[index] = '\0';
	if(dict->value != 0){
		printf("%s: %d\n", buffer, dict->value);
	}
	
}
