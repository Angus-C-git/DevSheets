
#include <stdlib.h>

#include "BSTree.h"

static int BSTreeSize(BSTree t) {
	if (!t) return 0;
	return 1 + BSTreeSize(t->left) + BSTreeSize(t->right);
}

int BSTreeGetKth(BSTree t, int k) {

	int lSubtreeSize = BSTreeSize(t->left);
	if (k == lSubtreeSize) {
		return t->value;
	} else if (k < lSubtreeSize) {
		// Explore the left subtree.
		return BSTreeGetKth(t->left, k);
	} else {
		// since the smallest element was not in the left
		// subtree subtract the height of the left subtree
		// to restore k then search the right subtree.
		return BSTreeGetKth(t->right, k - lSubtreeSize - 1);
	}
}

