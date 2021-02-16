
#include <stdlib.h>

#include "tree.h"

int TreeSumOdds(Tree t) {
	
	if (!t)
		return 0;
	else if ( (t->value % 2) != 0) // ~> Odd 
		return t->value + TreeSumOdds(t->left) + TreeSumOdds(t->right);
	else 
		return TreeSumOdds(t->left) + TreeSumOdds(t->right);
}

