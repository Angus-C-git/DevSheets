#include <stdio.h>



/* -- POINTER ARITHMETIC -- */

/*Various mathematical operations can be performed on pointers which can be desirable */

/* -- INCREMENTING & DECREASING A POINTER -- */

/*Similarly with variables we can use the ++ syntax to increment a pointer, what this is actually doing is advancing the memory address up the stack (or down depending on endiness)*/



#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[3]; //point to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 4th element

    intpointer++; //now increase the pointer's address so it points to the 5th elemnt in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

    return 0;
}


/*we can decrease the address pointed-to by one using the decrement operator (--).*/


#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[4]; //point to the 5th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

    intpointer--; //now decrease the point's address so it points to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 4th element

    return 0;
}

/* -- ADDING POINTERS -- */

/*We can add integer values to pointerswith the regular + syntax*/

#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value: %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[1]; //point to the 2nd element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 2nd element

    intpointer += 2; //now shift by two the point's address so it points to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the addres of the 4th element

    return 0;
}

/* -- SUBTRACTING POINTERS -- */

#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value: %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[4]; //point to the 5th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

    intpointer -= 2; //now shift by two the point's address so it points to the 3rd element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 3rd element

    return 0;
}

/* -- OTHER OPERATIONS -- */

/*
	Other operations that can be perfomed on variables are also possible on pointers, comparisons are also possible. The only diffrence is that we are working with memory.
*/

/* -- EXAMPLE OPERATION -- */

/*

Copy last three addresses of intarray into parray which is an array of pointers to an int.

*/

#include <stdio.h>
	
    int main() {
    	int intarray[5] = {10,20,30,40,50};
        //-----------------------^
        int *pointer = &intarray[2];

        // Array of 3 pointers
        int *parray[3];

        // Copy last three addresses of intarray into parray
        // Use parray and pointer
        int i;
        for (i = 0; i < 3; i++) {
            // Insert code here
            parray[i] = pointer +i;
        }

        // Test code
        for (i = 0; i < 3; i++) {
            if (parray[i] == &pointer[i]) {
                printf("Matched!\n");
            } else {
                printf("Fail\n");
            }
        }

        return 0;
    }