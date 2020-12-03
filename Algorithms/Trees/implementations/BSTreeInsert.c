#include <stdlib.h>

#include "BSTree.h"

BSTree newNode(int val) {

	BSTree newNode = malloc(sizeof(*newNode));
	newNode->value = val;
	newNode->left = newNode->right = NULL;

	return newNode;
}

BSTree BSTreeInsert(BSTree t, int val) {

	if (!t) 
		return newNode(val);
	else if (val == t->value)
		t->value = val; 
	else if (val < t->value)
		t->left = BSTreeInsert(t->left, val);
	else
		t->right = BSTreeInsert(t->right, val);

	return t;
}

