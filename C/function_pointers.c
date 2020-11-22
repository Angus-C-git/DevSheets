#include <stdio.h>


/* -- FUNCTION POINTERS --*/

/* We can also have pointers that point to a function and thus use pointers to call functions*/

/*SYNTAX*/


void (*fp)(int); //void -> function return type, *fp -> pointer to the function, (int) -> The type of the argument parsed to the function


/*with pointer values*/

char* (*pf)(int*); 

/* -- EXAMPLE -- */

#include <stdio.h>
void someFunction(int arg)
{
    printf("This is someFunction being called and arg is: %d\n", arg);
    printf("Whoops leaving the function now!\n");
}

main()
{
    void (*pf)(int);
    pf = &someFunction;
    printf("We're about to call someFunction() using a pointer!\n");
    (pf)(5);
    printf("Wow that was cool. Back to main now!\n\n");
}


/* -- QSORT EXAMPLE -- */

#include <stdio.h>
#include <stdlib.h> //for qsort()

int compare(const void* left, const void* right)
{
    return (*(int*)right - *(int*)left); // http://www.cplusplus.com/reference/cstdlib/qsort/
}
main()
{
    int (*cmp) (const void* , const void*); //Function pointer syntax
    cmp = &compare;

    int iarray[] = {1,2,3,4,5,6,7,8,9};
    qsort(iarray, sizeof(iarray)/sizeof(*iarray), sizeof(*iarray), cmp);

    int c = 0;
    while (c < sizeof(iarray)/sizeof(*iarray))
    {
        printf("%d \t", iarray[c]);
        c++;
    }
}

/* -- EXAMPLE 2 -- */

/*Complete the array of pointers to functions and call each function using its pointer from the array.*/

    #include <stdio.h>

    void f1(int var)
    {
            printf("this is f1 and var is: %d\n", var);
    }

    void f2(int var)
    {
            printf("this is f2 and var is: %d\n", var);
    }

    void f3(int var)
    {
            printf("this is f3 and var is: %d\n", var);
    }

    int main()
    {
                /* define an array full of function pointers 
                to the above functions, that take an `int` as 
                their only argument */
        void (*pf[])(int) = {f1, f2, f3};


		int c = 0;
		while(c < 3)
		{
  
			pf[c](c);
			++c;
		}

	  return 0;
    }