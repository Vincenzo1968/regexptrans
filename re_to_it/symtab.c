#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "symtab.h"

HashTable* htNewNode(char *Key, char *szFrom, char *szTo)
{
	HashTable *n;
	int len;

	n = (HashTable*)malloc(sizeof(HashTable));

	if( n == NULL )
		return NULL;

	len = strlen(Key);
	n->Key = (char*)malloc(len + 1);
	if ( n->Key == NULL )
	{
		free(n);
		return NULL;
	}
	strncpy(n->Key, Key, len + 1);
	strncpy(n->szFrom, szFrom, 8);
	strncpy(n->szTo, szTo, 8);
	n->next = NULL;

	return n;
}

int htFind(HashTable **pHashTable, char *Key, HashTable **pDati)
{
	int index = 0;
	HashTable *t;
	int a = 31415;
	/* int b = 27183; */
	char *s = Key;
	
	*pDati = NULL;
	
	for(; *s != '\0'; s++)
		index = (a*index + *s) % HT_SIZE;
	if ( index < 0 )
		index *= -1;

	t = pHashTable[index];
	while ( t != NULL )
	{
		if ( strcmp(t->Key, Key) == 0 )
		{
			*pDati = t;
			return index;
		}
		t = t->next;
	}

	return -1;
}

int htInsert(HashTable **pHashTable, char *Key, char *szFrom, char *szTo)
{
	int index = 0;
	HashTable *t = NULL;
	int a = 31415;
	/* int b = 27183; */
	char *s = Key;
	
	for(; *s != '\0'; s++)
		index = (a*index + *s) % HT_SIZE;
	if ( index < 0 )
		index *= -1;

	t = pHashTable[index];	
	if ( t == NULL )
	{
		pHashTable[index] = htNewNode(Key, szFrom, szTo);
		if ( pHashTable[index] == NULL )
		{
			fprintf(stdout, "Errore: impossibile inserire la chiave '%s' nella hashtable\n", Key);
			return 0;
		}
		return 1;
	}

	while ( t != NULL )
	{
		if ( strcmp(t->Key, Key) == 0 )
		{
			fprintf(stdout, "Errore: La chiave %s e' gia' presente nella hashtable\n", Key);
			return 0;
		}
		if ( t->next == NULL )
		{
			t->next = htNewNode(Key, szFrom, szTo);
			if ( t->next == NULL )
			{
				fprintf(stdout, "Errore: impossibile inserire la chiave '%s' nella hashtable\n", Key);
				return 0;
			}
			return 1;
		}
		t = t->next;
	}
	
	return 1;
}

void htFreeList(HashTable* first)
{
	HashTable *n1 = first, *n2;
	while ( n1 != NULL )
	{
		n2 = n1->next;
		if ( n1->Key )
			free(n1->Key);
		free(n1);
		n1 = n2;
	}
}

void htFree(HashTable** pHashTable)
{
	int i;
	HashTable *n1, *n2;
	
	if ( pHashTable == NULL )
		return;
	
	for(i = 0; i < HT_SIZE; i++)
	{
		n1 = pHashTable[i];
		while ( n1 != NULL )
		{
			n2 = n1->next;
			if ( n1->Key )
				free(n1->Key);
			free(n1);
			n1 = n2;
		}
	}
	free(pHashTable);
}
