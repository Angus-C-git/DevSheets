#include <stdio.h>

int main(int argc, char **argv)
{
	/* -- BASIC ARAYS -- */
	
	int numbers[10]; // Defines an integer array of 10 integers 

	/*Populating arrays */

	numbers[0] = 1; //Assigns the number 1 to the first index in the integer array


	/* -- MULTIDIMENSIONAL ARRAYS -- */

	/* Have structure: type name[size1][size2]...[sizeN]; */

	/*Define a two dimensional array with rows of length 4 (four columns) and 3 rows -- 3 * 4 matrix/table/array */

	int 2d_array[3][4] = {
		{0, 1, 2, 3},  //Max four integers across, R1
		{4, 5, 6, 7},  //R2
		{8, 9, 10, 11} //R3
	};

	int 2d_array[][4] = { // Can leave the rows specifier blank since the compiler can figure out how many rows there are 
		{0, 1, 2, 3},  //Max four integers across, R1
		{4, 5, 6, 7},  //R2
		{8, 9, 10, 11} //R3
	};

	/* Accessing Elements */

	int value = 2d_array[1][1]; //Will assign the value found at the index 1,1 in the 2d array, that is the first colum of the first row so 1


	return 0;
}
