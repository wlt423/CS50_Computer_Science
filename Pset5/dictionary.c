/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 * Walter Thornton
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

/**
 *  hashes a word using Berstein's multiplicative hash function
 */

unsigned int hashf(const char* key, int len)
{
    hash = 5381;
    for(int i = 0; i < len; ++i)
    {  
        hash = 33 * hash + key[i];
    }
    return hash % TABLE_SIZE;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // hash the text word
    len = strlen(word);
    hash = hashf(word, len);
    
    // create a cursor
    node* ptr = hash_table[hash];
    
    // compare the words
    while (ptr != NULL)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }   
        ptr = ptr->next;
    }
    return false;       
}


/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    counter = 0;
   
    // open dictionary
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return 1;
    }
    
    // loop through each dictionary word
    while (!feof(fp))
    {
        
        // create new node
        node* new_node = malloc(sizeof(node));
        
        // check for NULL
        if (new_node == NULL)
        {
            exit(1);
        }
        
        new_node->next = NULL;
        
        // read in dictionary word
        fscanf(fp, "%s", new_node->word);
        if (feof(fp))
        {
            fclose(fp);
            free(new_node);
            return true;
        }
        
        // increment dictionary word count
        counter++;
        
        // hash dictionary word
        len = strlen(new_node->word);
        
        hash = hashf(new_node->word, len);
        
        // insert word into hash table
        new_node->next = hash_table[hash];
        hash_table[hash] = new_node;
        
    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (counter != 0)
    {
        return counter;
    }
    else
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // loops through hash table
    for(hash = 0; hash <= (TABLE_SIZE - 1); hash++)
    {
        
        
        // create  cursor
        node* ptr = hash_table[hash];
        
        // loops through linked lists
        while (ptr != NULL)
        {
            node* previos = ptr;
            ptr = ptr->next;
            free(previos);
        }
        free(ptr);
        
    }
    return true;
}
