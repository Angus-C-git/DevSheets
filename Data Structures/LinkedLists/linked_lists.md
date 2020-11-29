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

## Doubly Linked List


### Searching

### Reversing