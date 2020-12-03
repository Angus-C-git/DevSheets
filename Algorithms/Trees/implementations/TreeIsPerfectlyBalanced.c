
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

/**
* A tree is perfectly balanced if, for every node, 
* the difference in size (i.e., number of nodes) between 
* its left and right subtrees does not exceed 1
*/

static int SubTreeHeight(Tree t) {
	if (!t) return 0;

    int lHeight = SubTreeHeight(t->left);
    int rHeight = SubTreeHeight(t->right);

    //int maxHeight = (lHeight >= rHeight) ? lHeight : rHeight;

    return 1 + lHeight + rHeight;
}

bool TreeIsPerfectlyBalanced(Tree t) {
	
	// Empty trees are prefectly
	// balanced.
	if (!t) return true;

	int lHeight = SubTreeHeight(t->left);
	int rHeight = SubTreeHeight(t->right);

	if (abs(lHeight - rHeight) <= 1 && 
		 TreeIsPerfectlyBalanced(t->left) && 
		 TreeIsPerfectlyBalanced(t->right)) {
			return true;
	}

	return false;

}

