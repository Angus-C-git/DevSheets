
#include "list.h"

static int intersects(List s2, int candidate) {

	for (Node crt = s2->head; crt; crt = crt->next) {
		if (crt->value == candidate)
			return 1;
	}

	return 0;
}

List listSetIntersection(List s1, List s2) {
	
	List intersect = newList();

	//Node intCur = intersect->head;
	for (Node crt = s1->head; crt; crt = crt->next) {
		if (intersects(s2, crt->value)) {
			Node n = newNode(crt->value);
			n->next = intersect->head;
			intersect->head = n;
		}
	}

	return intersect;
}

