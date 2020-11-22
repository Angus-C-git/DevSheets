#include <stdio.h>


/* -- FUNCTION ARGUMENTS BY REFERENCE --*/


/* Since by default variables in C are passed by value we can use pointers to gain pass by refrence functionality */


/*PASS BY VALUE vs PASS BY REFRENCE*/


/*PASS BY VALUE*/

void addone(int n){
	n++;
}


int n;
addone(n);
printf("%d\n", n); //Prints 1
addone(n);
printf("%d\n", n); // Will print the same value ~1 since the function resets after it executes, that is it is popped from the stack 


/*PASS BY REFRENCE*/

void addone(int * n){
	(*n)++;
}

int n;
addone(&n); //we must pass a refrence varaible of n instead of n itself
printf("%d\n", n); //Prints 1
addone(&n);
printf("%d\n", n); //Prints 2, since the pointer is used to update the value in memeory (on the stack)


/* -- POINTERS TO STRUCTURES -- */


/*Define point structure, with members x, y (ints)*/
typedef struct {
	int x;
	int y;
} point;


/*Define a function move which takes a pointer to the point structure*/
void move(point * p){
	(*p).x++;
	(*P).y++;
}

/*This concept has a shorthad syntax since it is a common operation*/

/*Define a function move which changes the internal variables of a point object, alternative to method above*/

void move(point * p){
	
	p->x++; //Derefrence point obj p and access internal member x
	y->++;  //Derefrence point obj p and access internal member x
}