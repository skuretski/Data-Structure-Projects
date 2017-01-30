/*
 * hashMap.c
 *
 *  Created on: Mar 2, 2015
 *  Author: Susan Kuretski (kuretsks@onid.oregonstate.edu)
 *  CS261-400 Program 6: Hash Tables
 *  Implementation of hash table
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"



/*First hashing function*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*Second hashing function*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* Initialize hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* Allocate memory and initialize a hash map.
 * Uses function _initMap.
 */

hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Freeing up a hashLink and freeing the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{
	assert(ht->tableSize != 0);
	struct hashLink *current, *next;
	for(int i = 0; i < ht->tableSize; i++)
	{
		current = ht->table[i];
		while(current != 0){
			next = current->next;
			free(current->key);
			current->value = 0;
			free(current);
			current = next;
		}
	}
	free(ht->table);
	ht->count = 0;
	ht->table = 0;
	ht->tableSize = 0;
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/*
Resizes the hash table to be the size newTableSize
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	struct hashLink **oldTable = ht->table;
	int oldSize = ht->tableSize;
	struct hashLink *current, *last;
	_initMap(ht, 2 * oldSize);
	for(int i = 0; i < oldSize; i++)
	{
		current = oldTable[i];
		while(current != 0)
		{
			insertMap(ht, current->key, current->value);
			last = current;
			current = current->next;
			free(last);
		}
	}
	free(oldTable);
}

/*
 Insert values into hashLink.
 1. First confirms key is not already in table.
 2. If hashLink exists, then replace it by freeing up the old memory pointed to by
    hashLink->value and then pointing to hashLink->value to value v.
 3. If size is greater than LOAD_FACTOR_THRESHOLD, then map is resized by
 	to double the size by function _setTableSize().
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
	int duplicate = 0;
	int hashIndex = stringHash2(k) % ht->tableSize;
	if(hashIndex < 0) hashIndex += ht->tableSize;

	struct hashLink *current = ht->table[hashIndex];
	while(current != 0)
	{
		if(strcmp(current->key, k) == 0){
			current->value = v;
			duplicate = 1;
			break;
		}
		current = current->next;
	}
	if(duplicate == 0)
	{
		struct hashLink *newLink = malloc(sizeof(struct hashLink));
		assert(newLink != 0);
		newLink->value = v;
		newLink->key = k;
		newLink->next = ht->table[hashIndex];
		ht->table[hashIndex] = newLink;
		ht->count++;
		if((tableLoad(ht) > LOAD_FACTOR_THRESHOLD))
		_setTableSize(ht, 2 * ht->tableSize);
	}
}

/*
 This returns the value (which is void*) stored in a hashLink specified by the key k.

 If the user supplies the key "taco," you should find "taco" in the hashTable, then
 return the value member of the hashLink that represents "taco."

 If the supplied key is not in the hashtable, return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{
	struct hashLink *temp;
	int hashIndex = (int)(abs(stringHash2(k)%ht->tableSize));
	temp = ht->table[hashIndex];
	if(temp == 0)
		return 0;
	while(temp != 0){
		if(strcmp(temp->key, k) == 0){
			return (int*)temp->value;
		}
		temp = temp->next;
	}
	return NULL;
}

/*
 A simple 1/0 if the key is in the hashtable.
 0 is no (false), all other values are yes (true).
 */
int containsKey (struct hashMap * ht, KeyType k)
{
	int hash = stringHash2(k);
	int hashIndex = (int)(abs(hash)%ht->tableSize);
	struct hashLink *current;
	current = ht->table[hashIndex];
	while(current != 0)
	{
		if(current->key == k)
			return 1;
		current = current->next;
	}
	return 0;
}

/*
 Find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink.
 It is not an error to be unable to find the hashlink; if it
 cannot be found, the function does not result in anything.
 */
void removeKey (struct hashMap * ht, KeyType k)
{
	int hash = stringHash2(k);
	int hashIndex = (int)(abs(hash)% ht->tableSize);
	struct hashLink *current, *last;
	assert(ht->tableSize != 0);
	if(ht->table[hashIndex] == 0){
		return;
	}
	else{
		current = ht->table[hashIndex];
		last = ht->table[hashIndex];
		while(current != 0)
		{
			if(strcmp(current->key, k) == 0){
				if(current == ht->table[hashIndex]){
					ht->table[hashIndex] = current->next;
				}
				else{
					last->next = current->next;
				}
				free(current);
				ht->count--;
				return;
			}
			else{
				last = current;
				current = current->next;
			}
		}
	}
}

/*
 Returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{
	return ht->count;
}

/*
 Returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{
	return ht->tableSize;
}

/*
 Returns the number of empty buckets in the table; these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{
	assert(ht->tableSize != 0);
	struct hashLink *temp;
	int count = 0;
	for(int i = 0; i < ht->tableSize; i++)
	{
		temp = ht->table[i];
		if(temp == 0)
		{
			count++;
		}
	}
	return count;
}

/*
 Returns the ratio of: (number of hashlinks) / (number of buckets)

 This value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks than buckets (hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{
	return (float)ht->count/(float)ht->tableSize;
}

/* Void function which prints the hashMap by bucket and then values,
 * and continues this iteration with each bucket.
 */
void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {
			printf("\nBucket Index %d -> ", i);
		}
		while(temp != 0){
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;
		}
	}
}


