
#include "list.h"

bool listIsOrdered(List l) {
	
	// Empty list case
	if (!l->head) return true;

	// ascending order check
	int ascending = 1;

	for (Node current = l->head; current->next; current = current->next) {

		if (current->value > current->next->value) {
			ascending = 0;
			break;
		}
	}

	// check here that the list wasn't ascending
	if (ascending) return true;

	
	for (Node current = l->head; current->next; current = current->next) {
		if (current->value < current->next->value)
			return false;
	}

	return true;
}

