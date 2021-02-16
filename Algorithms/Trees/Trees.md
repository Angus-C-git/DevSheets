Trees
=====

## BSTs

### Supporting ADTs

1. [BSTTree ADT](./Data%Structures/Trees/BSTree.c)


### Searching

#### Pseudo Code

#### Recursively
```
def search_recursively(key, node):

    if node == None or node.key == key:

        return node

    if key < node.key:

        return search_recursively(key, node.left)

    if key > node.key:

        return search_recursively(key, node.right)

```

#### Iteratively

```
def search_iteratively(key, node):

    current_node = node

    while current_node != None:

        if key == current_node.key:

            return current_node

        if key < current_node.key:

            current_node = current_node.left

        else:  # key > current_node.key:

            current_node = current_node.right

    return current_node

```


#### C Code

```


```


### Insertion

#### C Code

~> [Full Implementation](./BSTreeInsert.c)

```
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

```

### Deletion

### Balancing

### Height

### Depth Of A Node

### K Smallest Element

#### C Code

~> [Full Implementation](./BSTreeKth.c)

```

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

```
