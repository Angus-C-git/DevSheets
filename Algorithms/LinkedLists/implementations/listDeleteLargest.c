
#include "list.h"

int listDeleteLargest(List l) {

	// list never empty
	if (!l->head) return -1;

	// if list contains one item
	// return head
	Node biggestNode = l->head;
	
	for (Node curr = l->head; curr; curr = curr->next) {	
		biggestNode = (biggestNode->value < curr->value) ? curr : biggestNode;
	}

	int largest = biggestNode->value;

	if (biggestNode == l->head) {
		l->head = l->head->next;
	} else {
		Node pred = l->head;
		while (pred->next != biggestNode) {
			pred = pred->next;
		} pred->next = pred->next->next;
	}

	free(biggestNode);
	return largest;
}
