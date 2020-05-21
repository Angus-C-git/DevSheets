#include <stdio.h>


/* -- LINKED LISTS -- */

/*

	Linked lists are a data structure in C which heavily utilise pointers to create a kind of `dynamic` array which can be grown/shrank or manipulated from any index in the list. 
	
*/

/*LINKED LIST PROPERTIES*/

/*
	Linked lists have two primary desirable features:


	1. Entities can be added or removed from the middle of the list
	2. There is no requirment to define an inital size

	However they:

	1. Do not support random access
		a) Every index preceeding the desired index must be iterated over to reach the target index

	2. Create complicated code increasing seg fault risks and memory leaks 

	3. Have a large overhead
		a) Since items in the linked list are dynamically allocated which is less memeory efficent and each item in the list must store an additional pointer
*/

/*LINKED LIST OVERVIEW*/

/*
	
	A linked list is a set of dynamically allocated nodes, arranged in such a way that each node contains one value and one pointer. The pointer always points to the next member of the list. 
	If the pointer is NULL, then it is the last node in the list.

	A linked list is held using a local pointer variable which points to the first item of the list. If that pointer is also NULL, then the list is considered to be empty.


    ------------------------------              ------------------------------
    |              |             |            \ |              |             |
    |     DATA     |     NEXT    |--------------|     DATA     |     NEXT    |
    |              |             |            / |              |             |
    ------------------------------              ------------------------------


*/

/*LINKED LIST CODE*/


/*Define a node object/strcture to spawn new list entities*/

typedef struct node {
    int val;
    struct node * next; //Recursive model
} node_t;


/*Create the head variable which points to the first list entity*/

node_t * head = NULL; //define head variable to point to a NULL value
head = (node_t *) malloc(sizeof(node_t)); //Get the value of the `NEXT` entity in the list
if (head == NULL) { //Check that the next entity in the list is NULL (in this case it is the first variable)
    return 1;
}

head->val = 1;
head->next = NULL;


/*To append a variable to the end of the list we must advance the pointer*/


node_t * head = NULL;
head = (node_t *) malloc(sizeof(node_t));

head->val = 1; //Set first list index to 1
head->next = (node_t *) malloc(sizeof(node_t)); 

head->next->val = 2; //Set the next value to 2
head->next->next = NULL; //Set the value the the 'next' variable points to, to be null

/*-- ITERATING OVER LINKED LISTS -- */

/*To itterate over a linked list requires us to loop through it maintaing our current position in the list with a `counter` or position pointer*/

void push(node_t * head, int val) {
    node_t * current = head; //current keeps track of the current position in the list, updating after each step foward
    while (current->next != NULL) {
        current = current->next; //update current to the next member in the list
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

/*-- PUSHING TO LINKED LISTS -- */

/* 
	
	To add to the beginning of the list, we will need to do the following:

    	1. Create a new item and set its value
    	2. Link the new item to point to the head of the list
    	3. Set the head of the list to be our new item

This will effectively create a new head to the list with a new value, and keep the rest of the list linked to it.

Since we use a function to do this operation, we want to be able to modify the head variable. To do this, we must pass a pointer to the pointer variable (a double pointer) so we will be able to modify the pointer itself.

*/

void push(node_t ** head, int val) { //Parse a double pointer to the head variable
    node_t * new_node; //Spawn a new note object using our node structure 
    new_node = (node_t *) malloc(sizeof(node_t)); 

    new_node->val = val;
    new_node->next = *head; //Shift the head pointer
    *head = new_node;
}

/* -- POPPING ITEMS FROM LINKED LISTS -- */

/*

	To pop a variable, we will need to reverse the actions taken to push a node to the list:

    	1. Take the next item that the head points to and save it
    	2. Free the head item
    	3. Set the head to be the next item that we've stored on the side

*/

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

/* -- REMOVING THE LAST ENTITY IN THE LIST -- */

/*

Removing the last item from a list is very similar to adding it to the end of the list, but with one big exception - since we have to change one item before the last item, we actually have to look two items ahead and see if the next item is the last one in the list.

*/

int remove_last(node_t * head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) { //Iterate through the array looking two places foward from the current index for a NULL value indicating the end of the list
        current = current->next;
    }

    /* now current points to the second to last item, [-2:], of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL; 
    return retval;

}

/* REMOVING A SPECIFIC ITEM */

/*
	
	To remove a specific item from the list, either by its index from the beginning of the list or by its value, we will need to go over all the items, continuously looking ahead to find out if we've reached the node before the item we wish to remove. 
	This is because we need to change the location to where the previous node points to as well.
	

	Algorithm:

		1. Iterate to the node before the node we wish to delete
		2. Save the node we wish to delete in a temporary pointer
		3. Set the previous node's next pointer to point to the node after the node we wish to delete
		4. Delete the node using the temporary pointer

	~There are sevral edge cases that need to be considered such as the event that the list is empty or contains only one value 
*/

int remove_by_index(node_t ** head, int n) {
    int i = 0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) { //Check if the next value in the list is NULL (indicating that its the end of the list)
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;

}



/*Example remove by value complete code*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(node_t ** head, int val) {
	
    node_t *previous, *current;

    if (*head == NULL) {
        return -1;
    }

    if ((*head)->val == val) {
        return pop(head);
    }

    previous = current = (*head)->next;
    while (current) {
        if (current->val == val) {
            previous->next = current->next;
            free(current);
            return val;
        }

        previous = current;
        current  = current->next;
    }
    return -1;
}

void delete_list(node_t *head) {
    node_t  *current = head, 
            *next = head;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main(void) {
    node_t * test_list = (node_t *) malloc(sizeof(node_t));

    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
    delete_list(test_list);

    return EXIT_SUCCESS;
}