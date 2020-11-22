#include <stdio.h>

/* -- BINARY TREES -- */

/*

	Binary trees are a special type of k'aray tree whoes nodes have at most two children. Meaning k is 2.

	Binary trees are used to implement a number of higher level data structures such as:

	- Binary search trees
	- Binary heaps

	and are alseo used for efficent searching and sorting. 

	There are three general operations that can be performed on binary trees:

	- insertion
	- deletion
	-traversal

	depending on weather the tree is balanced and or the nodes are leaf nodes ofr branch nodes.

	In a balanced tree the depth of the left and right subtrees differ by 1 or less. This allows for a predictable depth also known as height.

	Depth/height -> The measure of a node from root to leaf where root is 0 and sebsequent nodes are (1,2, .. ,n) [This can be expressed as the integer part of log2(n), where n is the number of nodes in the tree]  



	    g                  s                  9
       / \                / \                / \
      b   m              f   u              5   13
     / \                    / \                /  \
    c   d                  t   y              11  15


	- SEARCHING BINARY TREES -

	All operations on binary trees require searching. There are two main methods of searching binary trees:

	- Depth first search
		->  pre-order 
			
			- visit, left, right

		->  in-order 

			- left, visit, right

		-> post-order 

			- left, right, visit

	- Breadth first search
		
		-> In level-order, where we visit every node on a level before going to a lower level.


*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node * left;
  struct node * right;
} node_t;

void insert(node_t * tree, int val);
void print_tree(node_t * current);
void printDFS(node_t * current);

int main()
{
  node_t * test_list = (node_t *) malloc(sizeof(node_t));
  /* set values explicitly, alternative would be calloc() */
  test_list->val = 0;
  test_list->left = NULL;
  test_list->right = NULL;

  insert(test_list,5);
  insert(test_list,8);
  insert(test_list,4);
  insert(test_list,3);

  printDFS(test_list);
  printf("\n");
}

void insert(node_t * tree, int val)
{
  if (tree->val == 0)
  {
    /* insert on current (empty) position */
    tree->val = val;
  }
  else
  {
    if (val < tree->val)
    {
      /* insert left */
      if (tree->left != NULL)
      {
        insert(tree->left, val);
      }
      else
      {
        tree->left = (node_t *) malloc(sizeof(node_t));
        /* set values explicitly, alternative would be calloc() */
        tree->left->val = val;
        tree->left->left = NULL;
        tree->left->right = NULL;
      }
    }
    else
    {
      if (val >= tree->val)
      {
        /* insert right */
        if (tree->right != NULL)
        {
          insert(tree->right,val);
        }
        else
        {
          tree->right = (node_t *) malloc(sizeof(node_t));
          /* set values explicitly, alternative would be calloc() */
          tree->right->val = val;
          tree->right->left = NULL;
          tree->right->right = NULL;
        }
      }
    }
  }
}

/* depth-first search */
void printDFS(node_t * current)
{
  /* Pre-order*/
  if (current == NULL)         return;   /* security measure */
  if (current != NULL)         printf("%d ", current->val); //-> CURRENT
  if (current->left != NULL)   printDFS(current->left); // -> LEFT
  if (current->right != NULL)  printDFS(current->right); // -> Right
}

/*

	//In-order

  	if (current == NULL)         return;
  	if (current->left != NULL)   printDFS(current->left); // -> LEFT
  	if (current != NULL)         printf("%d ", current->val); //-> CURRENT
  	if (current->right != NULL)  printDFS(current->right); // -> Right



	//Post order

  	if (current == NULL)         return;
  	if (current->left != NULL)   printDFS(current->left); // -> LEFT
  	if (current->right != NULL)  printDFS(current->right); // -> Right
  	if (current != NULL)         printf("%d ", current->val); //-> CURRENT
  
*/