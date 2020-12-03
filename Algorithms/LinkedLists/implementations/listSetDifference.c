
#include "list.h"

static int notIn(List l2, int candidate) {

	for (Node curr = l2->head; curr; curr = curr->next) {
		if (curr->value == candidate)
			return 0;
	}

	return 1;
}

List listSetDifference(List l1, List l2) {

	List diff = newList();

	for (Node curr = l1->head; curr; curr = curr->next) {

		if (notIn(l2, curr->value)) {
			Node n = newNode(curr->value);
			n->next = diff->head;
			diff->head = n;
		}
	}


	return diff;
}

