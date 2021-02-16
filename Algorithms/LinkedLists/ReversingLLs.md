# Reversing Linked Lists

## Singly Linked Lists

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

## Doubly Linked Lists

1. Continually swap the previous node with the next node
2. Swap the head and tail of the list

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