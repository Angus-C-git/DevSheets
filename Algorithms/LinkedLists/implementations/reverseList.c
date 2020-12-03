
#include "list.h"

void listReverse(List l) {
	
	/**
	* <---
		1. Keep inserting at the head of the list
		2. Set the head of the orignial head to the updated one
	  -->
	*/

	Node current, prev, 
	Node tmp = current;

	for (current = l->head, prev = NULL; current; tmp = current) {
		
		current = current->next;
		tmp->next = prev;
		prev = tmp;

	} l->head = prev;
}

