# Linked Lists

## Overview


## Singly Linked Lists

### Searching

### Reversing

1. Keep inserting at the head of the list
2. Set the head of the orignial head to the updated one

```
void listReverse(List l) {

	Node current, prev, 
	Node tmp = current;

	for (current = l->head, prev = NULL; current; tmp = current) {
		
		current = current->next;
		tmp->next = prev;
		prev = tmp;

	} l->head = prev;
}

```

### Joining Without Duplicates

```
static int inList(List l, int value) {

	for (Node curr = l->head; curr; curr = curr->next) {
		if (curr->value == value)
			return 1;
	}
	return 0;
}


static void insertNode(List l, int value) {
	Node n = newNode(value);
	n->next = l->head;
	l->head = n;
}


List listSetUnion(List s1, List s2) {

	List unionL = newList();

	// add each element from s1 to unionList
	// if s1 is not an empty set
	// Node uCurr = unionL->head;
	for (Node current = s1->head; current && s1->head; current = current->next) {
		insertNode(unionL, current->value);
	} 
	
	// for every node in s2 which is not already in s1 insert
	for (Node current = s2->head; current && s2->head; current = current->next) {
		if(!inList(unionL, current->value))
			insertNode(unionL, current->value);
	} 

	return unionL;
}

```

## Doubly Linked List


### Searching

### Reversing


```
static void swap(Node *prev, Node *curr) {
	Node tmp = *prev;
	*prev = *curr;
	*curr = tmp;
}

void reverseDLList(List l) {

	for (Node curr = l->first; curr; ) {
		
		swap(&(curr->prev), &(curr->next));
		curr = curr->prev;
	
	} swap(&(l->first), &(l->last));
}
```