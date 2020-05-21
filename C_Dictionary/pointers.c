#include <stdio.h>







/*-- POINTERS --*/

/*
	
	Pointers are also variables. They are used for several reasons, such as:

    - Strings
    - Dynamic memory allocation
    - Sending function arguments by reference
    - Building complicated data structures
    - Pointing to functions
    - Building special data structures (i.e. Tree, Tries, etc...)
	
	What are pointers?

	-> Pointers are more or less a simple integer variable which holds the memory address that points to a value (on the stack) rather than holding the value itself (like a normal variable)

*/


/*-- STRINGS AS POINTERS --*/

char * string_pointer = "String";

/*

	A string pointer or C-String does the following at runtime:

	1. Allocates a local (stack) variable called string_pointer, which is a pointer to a single char
	2. Places the string "String" into the allocated program memory following the memeory location of the first character in the string above^ (after compilation and execution)
	3. It initializes the string_pointer argument to point to where the first character "S" is stored which is then followed by the rest of the string in memory

	~ Because memeory is sequential we can assume with reasonable certanity (unless some funny buisness like buffer overflows are happening) that the next value after "S" in memeory will be the next character of the sting
	up until the null terminator \0 which accompanies every string

*/

/*-- DEREFRENCING --*/

/*
~"You've derefrenced a null pointer"
	

Dereferencing is the act of referring to where the pointer points, instead of the memory address. The * character is used to defrefrence a pointer.


*/

/*Define some variable*/

int variable = 1;

/* Define a pointer variable and point it to the variable declared above with &*/

int * pointer_to_variable = &variable;

/*We can derefrence a pointer to change its value*/

*pointer_to_variable += 1; //change the value of variable via a derefrenced pointer to vraiable
