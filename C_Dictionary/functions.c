#include <stdio.h>



/*-- BASIC FUNCTIONS --*/

int foo(int bar){ //A function accepts either a fixed number of paramters or a variable number of arguments

	/* Function body */
	

	/* Functions can either return one value or no value (void functions) */
	return bar * 2; //Return the input parmater multiplied by 2
}


/*-- VOID FUNCTIONS --*/

/*Void functions don't return a value they */
void moo(){ 

	/*Function body*/

	printf("Perform some action\n");

	/*Don't return a value*/
}


/* Functions must be defined or declared & defined elsewhere (preferable) chronologically before they are used in the code, that is they must reside
above the line in the code that they are called. Alternativley they can be included as a header and be defined
in a seprate file */

int main(int argc, char **argv){



	/*Arguments are parsed by value in C, that means that the value of paramters cannot be altered by a 
	function outside of the function itself unless we use pointers*/

	foo(1); //Parse the parameter value of 1 to the function foo
	moo();
}
