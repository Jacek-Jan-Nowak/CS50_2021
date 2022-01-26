 // Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <cs50.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 5381;

// Hash table
node *table[N];
// Total number of words
int all_words = 0;
//Index in hash table
int hash_index = 0;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    hash_index = hash(word);
    node *cursor = table[hash_index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    // TODO 4
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO 2
    // djb2 hash from https://theartincode.stanis.me/008-djb2/ by Daniel J. Bernstein
    unsigned long hash = 5381;
    int c;
    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO 1
    //Open the dictionary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    // read one word at a time from the file
    char word[LENGTH + 1]; // Buffer for words
    while (fscanf(dict, "%s", word) != EOF)
    {
        //Reading worsd
        // Creating nodes
        node *node_new = malloc(sizeof(node));
        if (node_new != NULL)
        {
            //Copying word to the node
            hash_index = hash(word);
            strcpy(node_new->word, word);
            node_new->next = table[hash_index];
            table[hash_index] = node_new;
            all_words++;
        }
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO 3
    return all_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO 5
    // Free the linked list
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
