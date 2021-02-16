#include <stdio.h>



/* -- RECURSION -- */


/*

Recursion occurs when a function contains within it a call to itself. It can be used to simplify complex iterations that would be difficult to implement iterably. 
However if implimented incorrectly or the recusion depth is to great it can eat up an incredible amount of memory. 

*/

/*
	Recursion consits of two main parts:

	~ A terminating case that indicates when the recursion will finish
	~ A self call that must progress towards the terminating case
*/

/* MULTIPLYING BY RECURSIVE ADDING */



#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y)
{
    if (x == 1)
    {
        /* Terminating case */
        return y;
    }
    else if (x > 1)
    {
        /* Recursive step */
        return y + multiply(x-1, y);
    }

    /* Catch scenario when x is zero */
    return 0;
}

int main() {
    printf("3 times 5 is %d", multiply(3, 5));
    return 0;
}

