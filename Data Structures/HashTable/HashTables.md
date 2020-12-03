# Hash Tables

## Overview

Hash tables are used to facilitate key operations for hashing, an approach to adaptive indexing, they offer extremly fast element lookups and insertion.

## ADT

### Main Functions

+ Create a new empty hash table of size n

    `HashTable newHashTable(int)`

+ Insert an item into collection
    `void HashInsert(HashTable, Item)`
+ Find item with key
    `Item *HashGet(HashTable, Item)`
+ Delete an item with the given key
    `void HashDelete(HashTable, Key)`
+ Free the memory associated with the given hash table
    `void dropHashTable(HashTable)`

### C Implementation

```
typedef struct HashTableRep {
    Item **items; // array of (Item *)
    int N;        // size of array
    int nitems;   // # Items in array
} HashTableRep;

HashTable newHashTable(int N) {
    HashTable new = malloc(sizeof(HashTable Rep));
    new->items = malloc(N * sizeof(Item *));
    new->N = N;
    new->nitems = 0;
    for (int i = 0; i < N; i++) 
        new->items[i] = NULL;
    return new;
}

void HashInsert(HashTable ht, Item it) {
   int h = hash(key(it), ht->N);
   // assume table slot empty!?
   ht->items[h] = copy(it);
   ht->nitems++;
}

Item *HashGet(HashTable ht, Key k) {
   int h = hash(k, ht->N);
   Item *itp = ht->items[h];
   if (itp != NULL && equal(key(*itp),k))
      return itp;
   else
      return NULL;
}

void HashDelete(HashTable ht, Key k) {
   int h = hash(k, ht->N);
   Item *itp = ht->items[h];
   if (itp != NULL && equal(key(*itp),k)) {
      free(itp);
      ht->items[h] = NULL;
      ht->nitems--;
   }
}

void dropHashTable(HashTable ht) {
   for (int i = 0; i < ht->N; i++) {
      if (ht->items[i] != NULL) free(ht->items[i]);
   }
   free(ht);
}

```

