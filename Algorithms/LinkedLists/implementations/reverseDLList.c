
#include "list.h"

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

