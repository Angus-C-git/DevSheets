#include <stdio.h>

int main(int argc, char **argv)
{
	
	/*FOR LOOPS*/

	/*Basic loop structure*/

	int threshold = 10;
	for (counter = 0; counter < threshold; counter++){  //Loop parameters
		
		/*LOOP BODY*/

		printf("%d\n", counter);
		//Loop body executed 10 times as per the threshold value
	}


	/*WHILE LOOPS*/

	/*Basic while loop structure*/

	int n = 0;
	while (condition == flag){ //Loop parmaters -> standard operators ||, &&, !=  --accepted

		/*LOOP BODY*/

		n++; //counter 

		if(n == 5){ //Check if the counter is 5

			/*While loops are unguarded loops they must contain a reachable 
			terminator to exit the loop body*/

			break; //Exit the loop when the counter reaches 5
		}
	}

	/* Boolean whiles */
 
	while (1){ //Boolean statments (TRUE/FALSE) and statments which evaluate to T/F can also be used as the loop conditional 

		/*LOOP BODY*/

		break;
	}

	return 0;
}
