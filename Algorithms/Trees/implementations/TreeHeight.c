
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

int TreeHeight(Tree t) {
    
    if (!t) return -1;

    int lHeight = TreeHeight(t->left);
    int rHeight = TreeHeight(t->right);

    int maxHeight = (lHeight > rHeight) ? lHeight : rHeight;

    return 1 + maxHeight;
}

