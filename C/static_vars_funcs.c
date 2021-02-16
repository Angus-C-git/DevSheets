#include <stdio.h>


/*-- STATIC VARIABLES --*/

int runner(){

	/*Static variables give them a file scope allowing them to persist in memory and be accessed anywhere in the file */

    static int count = 0; //Don't get popped from memory after the function executes
    count++; //Will increase each time the function is called
    return count; //Returns 1, 2 ... increasing for each function call
}

int main() {
    printf("%d ", runner()); 
    printf("%d ", runner());
    return 0;
}

/*-- STATIC FUNCTIONS --*/

/*By default functions in C have a global scope, static functions allow us to reduce the function scope 
to the file containing that function*/

static void localised_function(void){
	printf("Static functions help with readability and segragating parts of the codebase\n");
}