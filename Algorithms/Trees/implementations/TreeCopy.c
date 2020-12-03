
#include "tree.h"

// Create new nodes in memory
static Tree newNode(int key) {
	Tree newTree = malloc(sizeof(*newTree));

	newTree->value = key;
	newTree->left = newTree->right = NULL;

	return newTree;
}

Tree TreeCopy(Tree t, int depth) {
	// Recurse until depth is 
	// less than 0 or tree is empty.
	if (depth < 0 || !t) 
		return NULL;

	// set root of tree to the 
	// same root as original
	Tree newTree = newNode(t->value);
	newTree->left = TreeCopy(t->left, depth - 1);
	newTree->right = TreeCopy(t->right, depth - 1);
	
	return newTree;
}

