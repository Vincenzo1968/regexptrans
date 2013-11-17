#ifndef SYMTAB_H
#define SYMTAB_H

#define HT_SIZE 251
/*
#define HT_SIZE 509
#define HT_SIZE 1021
#define HT_SIZE 2039
#define HT_SIZE 4093
#define HT_SIZE 8191
#define HT_SIZE 16381
#define HT_SIZE 32749
*/

typedef struct tagHashTable
{
	char *Key;
	char szFrom[8];
	char szTo[8];
	struct tagHashTable *next;
} HashTable;

HashTable* htNewNode(char *Key, char *szFrom, char *szTo);
int htFind(HashTable **pHashTable, char *Key, HashTable **pDati);
int htInsert(HashTable **pHashTable, char *Key, char *szFrom, char *szTo);
void htFreeList(HashTable* first);
void htFree(HashTable** pHashTable);

#endif /* SYMTAB_H */
