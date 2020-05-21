#include <stdio.h>

int main(int argc, char **argv)
{
	/* -- BASIC CONDITIONALS -- */

	int condition_target = 10;

	if (condition_target == 10){
		printf("The condition was true \n");
	}

	/* -- CONDITIONAL OPERATORS -- */

	if (condition_target < 10){printf("The condition_target was less than 10\n");} // Less than <

	if (condition_target > 10){printf("The condition_target was greater than 10\n");} // greater than >

	if (condition_target == 10){printf("The condition_target was equal to 10\n");} // equal to ==

	if (condition_target < 10 && condition_target > 4){printf("The condition_target was less than 10 and greater than 4 \n");} //&& and 

	if (condition_target < 10 || condition_target > 4){printf("The condition_target was less than 10 or greater than 4 \n");} //|| or

	if (condition_target != 10){printf("The condition_target was not equal to 10 \n");} //!= not equal to 
 

	/* -- ELSE/IF BLOCK -- */

	if (condition_target == 10)
	{
		printf("The target was 10\n");
	} else {
		printf("The target was not 10\n");
	}

	return 0;
}
