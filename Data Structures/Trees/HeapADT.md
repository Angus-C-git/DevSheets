# Heap ADT

## C Implementation

```
typedef struct HeapRep {
   Item *items;  // array of Items
   int  nitems;  // #items in array
   int  nslots;  // #elements in array
} HeapRep;

typedef HeapRep *Heap;

Heap newHeap(int N) {
   Heap new = malloc(sizeof(HeapRep));
   Item *a = malloc((N+1)*sizeof(Item));
   assert(new != NULL && a != NULL);
   new->items = a;   // no initialisation needed
   new->nitems = 0;  // counter and index
   new->nslots = N;  // index range 1..N
   return new;
}

void HeapInsert(Heap h, Item it) {
   // is there space in the array?
   assert(h->nitems < h->nslots);
   h->nitems++;
   // add new item at end of array
   h->items[h->nitems] = it;
   // move new item to its correct place
   fixUp(h->items, h->nitems);
}

// force value at a[i] into correct position
void fixUp(Item a[], int i) {
   while (i > 1 && less(a[i/2],a[i])) {
      swap(a, i, i/2);
      i = i/2;  // integer division
   }
}

void swap(Item a[], int i, int j) {
   Item tmp = a[i];
   a[i] = a[j];
   a[j] = tmp;
}


Item HeapDelete(Heap h) {
   Item top = h->items[1];
   // overwrite first by last
   h->items[1] = h->items[h->nitems];
   h->nitems--;
   // move new root to correct position
   fixDown(h->items, 1, h->nitems);
   return top;
}

```

