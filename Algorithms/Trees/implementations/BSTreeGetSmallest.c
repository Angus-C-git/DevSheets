
#include "BSTree.h"

#include <stdlib.h>
#include <stdio.h>

BSTree BSTreeGetSmallest(BSTree t) {
	
	if (!t) return NULL;

	BSTree currentNode = t;
	BSTree candiate = t;

	while (currentNode) {
		int key = currentNode->value;
		
		if (key <= candiate->value)
			candiate = currentNode;
			
		currentNode = (key <= candiate->value) ? currentNode->left : currentNode->right;
	}

	return candiate;
}

