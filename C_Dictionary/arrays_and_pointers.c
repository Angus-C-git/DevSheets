#include <stdio.h>

/* -- ARRAYS & POINTERS --*/

/*In C the name of an array (the variable name) is iteslf a (constatn) pointer to the first element of that array. That is `vowels`, &vowels[0], and vowels + 0, are all equivlent syntax which point to the same memeory location. That location being the first entity in the array*/

char vowels[] = {'A', 'E', 'I', 'O', 'U'};
char *pvowels = &vowels;
int i;

// Print the addresses
for (i = 0; i < 5; i++) {
    printf("&vowels[%d]: %u, pvowels + %d: %u, vowels + %d: %u\n", i, &vowels[i], i, pvowels + i, i, vowels + i); //Will print the memory address of each vowel rather then the character
}

// Print the values
for (i = 0; i < 5; i++) {
    printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i)); //Will print each character rather than the memory location, since we derefrence the pointer (which is the array name itself)
}


/* -- DYNAMIC MEMORY ALLOCATION OF ARRAYS -- */

/*We can also use block pointers in combination with the pointers we use to traverse the array to dynamically alocate array memory*/

/*Allocate memory to store 5 characters*/

int num_size = 5;

char * pvowels = (char *) malloc(n * sizeof(char));
int i;

pvowels[0] = 'A';
pvowels[1] = 'E';
*(pvowels + 2) = 'I';
pvowels[3] = 'O';
*(pvowels + 4) = 'U';

for (i = 0; i < num_size; i++) {
    printf("%c ", pvowels[i]);
}

printf("\n");

free(pvowels);


/*MULTIDIMENSIONAL ARRAYS*/

/* For multidimensional arrays we require a pointer to a pointer construct to implement the same logic as for 1D arrays*/

int nrows = 2;
int ncols = 5;
int i, j;

// Allocate memory for nrows pointers
char **pvowels = (char **) malloc(nrows * sizeof(char *)); //Pointer to pointer **

// For each row, allocate memory for ncols elements
pvowels[0] = (char *) malloc(ncols * sizeof(char));
pvowels[1] = (char *) malloc(ncols * sizeof(char));

pvowels[0][0] = 'A';
pvowels[0][1] = 'E';
pvowels[0][2] = 'I';
pvowels[0][3] = 'O';
pvowels[0][4] = 'U';

pvowels[1][0] = 'a';
pvowels[1][1] = 'e';
pvowels[1][2] = 'i';
pvowels[1][3] = 'o';
pvowels[1][4] = 'u';

for (i = 0; i < nrows; i++) {
    for(j = 0; j < ncols; j++) {
        printf("%c ", pvowels[i][j]);
    }

    printf("\n");
}

// Free individual rows
free(pvowels[0]);
free(pvowels[1]);

// Free the top-level pointer
free(pvowels);


/*EXAMPLE */

/*

The first seven rows of Pascal's triangle are shown below. Note that row i contains i elements. Therefore, to store the numbers from the first three rows, one would require 1 + 2 + 3 = 6 memory slots.

    1

    1 1

    1 2 1

    1 3 3 1

    1 4 6 4 1

    1 5 10 10 5 1

    1 6 15 20 15 6 1

Complete the skeleton code given below to store the numbers from the first three rows of Pascal's triangle in a two-dimensional "array" using dynamic memory allocation. Note that you must allocate exactly six memory slots to store those six numbers. No extra memory should be allocated. At the end of your program, free all the memory blocks used in this program.

*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    /* TODO: define the 2D pointer variable here */
	int **pnumbers;
    
    /* TODO: complete the following line to allocate memory for holding three rows */
    pnumbers = (int **) malloc(3 * sizeof(int *));

    /* TODO: allocate memory for storing the individual elements in a row */
    pnumbers[0] = (int *) malloc(1 * sizeof(int));
	pnumbers[1] = (int *) malloc(2 * sizeof(int));
    pnumbers[2] = (int *) malloc(3 * sizeof(int));
                               
    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        /* TODO: free memory allocated for each row */
        free(pnumbers[i]);
    }

    /* TODO: free the top-level pointer */
    free(pnumbers);

  return 0;
}