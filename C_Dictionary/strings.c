#include <stdio.h>

int main(int argc, char **argv)
{
	
	/* -- DECLARING STRING VARIABLES -- */

	char * string = "A string"; //Assigns a string by assigning a char array to the string on the RHS

	char string[] = "A string"; //Assings a character array the length of the string on the RHS, this is the same as specifying the length
	

	/* -- FORMATING STRINGS WITH PRINTF -- */ 

	/* ~NEVER USE PRINTF WITH USER INPUT --> FORMAT STRING VULRABILITIES */

	char * name = "Dave";
	int age = 33;

	printf("%s is %d years old.\n", name, age); // We use the flags %s for string %d for digit to place the paramters at the end in order into the printed string

	/* -- STRING FUNCTIONS -- */

	char * name = "David Bowie";

	/* STRING LENGTH */

	int str_length = strlen(name); //Gets the length of a string as an integer
	printf("%d\n", str_length);
	
	/* STRING COMPARISON */

	char * string_to_compare = "I'm getting compared";

	if (strncmp(string_to_compare, "I'm getting compared", 20) == 0){ //
		printf("The strings were the same so the compare function returns 0 and validates the if statement \n");
	}

	/* STRING CONCATENATION  */

	char destination[20] = "Hello";
	char source[20] = "World";

	strncat(destination, source,3);
	
	
	
	return 0;
}
