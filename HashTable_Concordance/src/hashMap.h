/*
 * hashMap.h
 *
 *  Created on: Mar 2, 2015
 *  Author: Susan Kuretski (kuretsks@onid.oregonstate.edu)
 *  CS261-400
 *  Program 6: Hash Tables
 */


# ifndef HashMap
# define HashMap

# define KeyType char*
# define ValueType int

/*
	This define will utilize hashing function 1 or 2, depending on which
	is specified.
 */
# define HASHING_FUNCTION 2

# define LOAD_FACTOR_THRESHOLD 0.75

struct hashLink
{
   KeyType key;
   ValueType value;
   struct hashLink *next;
};

typedef struct hashLink hashLink;

struct hashMap
{
    hashLink ** table; /*array of pointers to hashLinks*/
    int tableSize; /*number of buckets in the table*/
    int count; /*number of hashLinks in the table*/
};

typedef struct hashMap hashMap;

/* First hashing function */
int stringHash1(char * str);

/* Second hashing function */
int stringHash2(char * str);

//Init functions
void _initMap (struct hashMap * ht, int tableSize);
struct hashMap *createMap(int tableSize);

//Cleanup functions
void _freeMap (struct hashMap * ht);
void deleteMap(struct hashMap *ht);

//Insertion, remove, and key functions
void insertMap (struct hashMap * ht, KeyType k, ValueType v);
ValueType* atMap (struct hashMap * ht, KeyType k);
int containsKey (struct hashMap * ht, KeyType k);
void removeKey (struct hashMap * ht, KeyType k);

//Size, capacity, load, functions
int size (struct hashMap *ht);
int capacity(struct hashMap *ht);
int emptyBuckets(struct hashMap *ht);
float tableLoad(struct hashMap *ht);

//Printing functions
void printMap (struct hashMap * ht);
void printValue(ValueType v);


# endif
