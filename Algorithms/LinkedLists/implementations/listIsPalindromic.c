
#include "list.h"

bool listIsPalindromic(List l) {
	
	// pinch the list by traversing first
	// and last at the same time
	//Node fst, lst;
	Node fst, lst;

	for (fst = l->first, lst = l->last; lst != fst; fst = fst->next, lst = lst->prev) {
		if (fst->value != lst->value)
			return false;
	}

	return true;
}

