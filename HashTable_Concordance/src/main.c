/*
 *  main.c
 *
 *  Created on: Mar 2, 2015
 *  CS261-400 Program 6: Hash Tables
 *  Author: Susan Kuretski (kuretsks@onid.oregonstate.edu)
 *  Program reading a file in and hashing the words in the file.
 */


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"


char* getWord(FILE *file);

int main (int argc, const char * argv[]) {
	const char* filename;
	struct hashMap *hashTable;
	int tableSize = 10;
	clock_t timer;
	FILE *fileptr;
    /*
     This part can use command line arguments.

     If no command line arguments, then manually input the filename and path
     in the else case.

     */
    if(argc == 2)
        filename = argv[1];
    else
        filename = "input1.txt"; /*input text file here*/

    printf("opening file: %s\n", filename);

	timer = clock();

	hashTable = createMap(tableSize);

    /*... concordance here ...*/
	fileptr = fopen(filename, "r");
	if(fileptr == NULL)
	{
		fprintf(stderr, "Cannot open %s\n", filename);
	}
	else
	{
		char *word = getWord(fileptr);
		while(word != 0){
			ValueType* count = 0;
			int count2 = 0;
			count = atMap(hashTable, word);
			if(count == 0)
			{
				insertMap(hashTable, word, 1);
			}
			else
			{
				count2 = (int)(count + 1);
				insertMap(hashTable, word, count2);
			}
			word = getWord(fileptr);
		}
	}
	fclose(fileptr);
	/*... concordance ends here ...*/
	printMap(hashTable);
	timer = clock() - timer;
	printf("\nconcordance ran in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
	printf("Table emptyBuckets = %d\n", emptyBuckets(hashTable));
    printf("Table count = %d\n", size(hashTable));
	printf("Table capacity = %d\n", capacity(hashTable));
	printf("Table load = %f\n", tableLoad(hashTable));

	printf("Deleting keys\n");

	removeKey(hashTable, "and");
	removeKey(hashTable, "me");
	removeKey(hashTable, "the");
	printMap(hashTable);

	deleteMap(hashTable);
	printf("\nDeleted the table\n");
	return 0;
}

/*
 * Function to pretty print the value v.
 */
void printValue(ValueType v) {
	printf("Value:%d", v);
}

/*
 This function takes a FILE pointer and returns a string which is the next
 word in the IN file. Words are defined as characters or numbers separated by
 periods, spaces, or newlines.

 When there are no more words in the IN file, this will return NULL.
 */
char* getWord(FILE *file)
{
	int length = 0;
	int maxLength = 16;
	char character;

	char* word = malloc(sizeof(char) * maxLength);
	assert(word != NULL);

	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   character == 39) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}

	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}
