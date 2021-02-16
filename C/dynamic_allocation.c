#include <stdio.h>



/* -- DYNAMIC ALLOCATION OF MEMORY -- */


/*

	Memory managment in C is of critical importance , dynamic allocation of memeory is thus very importatn in order to build efficent complex data structures like linked lists.
	It is also necessary to efficently handel data that we do not intially know the size of.

*/

/*
	We can allocate a chunk of memory dynamically using malloc and then storing it in a pointer. We can then use that pointer to access the memory chunk and also to free the memory once we finish using it. 

*/


/*Example*/

typedef struct {
	char * name;
	int age;
} person;

/*We dynamically allocate the memory for a person object in the following way*/

person * person_obj_var = (person *) malloc(sizeof(person)); //Malloc will only allocate the memory necessary to store the structure (parsed parameter), or person object, in memory

/*Note here the sizeof keyword is not actually a function since it gets translated by the compiler into a number representitive of the bit size of the person structure/object*/

/*-- ACCESSING MEMBERS --*/

/* We can access members in the following fashion with the -> syntax*/

person_obj_var->name = "Bill";
person_obj_var->age = 25;

/*-- FREEING MEMORY --*/

free(person_obj_var);