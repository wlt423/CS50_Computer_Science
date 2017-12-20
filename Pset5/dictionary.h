/**
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

// declare globals
unsigned int counter;
unsigned int hash;
int len;

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// hash table size
#define TABLE_SIZE 27 

// define node data type for linked list
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;
    
// declare the hash table
node* hash_table[TABLE_SIZE];

#include <stdbool.h>

/**
 *  hashes a word
 */

unsigned int hashf(const char*, int);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

#endif // DICTIONARY_H
