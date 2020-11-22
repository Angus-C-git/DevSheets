#include <stdio.h>

/* -- UNIONS -- */

/*
	
	Unions are very similar to structures in syntax and usage. The diffrence is that unions are stored as a single entity in memory, rather than each variable (like in a struct) ocupying its own memeory address.
	In this way the 'names' (variables) can treat the memory as diffrent types. To do this the unions size is made to be that of the largest 'data type' in that union along with padding where necessary.   

*/

/* -- EXAMPLE USECASE -- */

/*
	Say we wanted to read the bytes of an integer one at a time. We could define the following union.
*/

union intParts{
	int integer_value;
	char bytes[sizeof(int)];
};

/*In doing so we can avoid the need to perform pointer arithmetic*/

union intParts parts;
parts.integer_value = 6789889; // Greater than one byte 

printf("The integer is %i\nThe bytes in the integer are [%i, %i, %i, %i]\n", parts.integer_value, parts.bytes[0], parts.bytes[1],  parts.bytes[2], parts.bytes[3]);


/*Vs Pointer arithmetic*/

int theInt = parts.theInt;
printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
theInt, *((char*)&theInt+0), *((char*)&theInt+1), *((char*)&theInt+2), *((char*)&theInt+3));

/*alternate pointer arithmetic syntax */

printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
    theInt, ((char*)&theInt)[0], ((char*)&theInt)[1], ((char*)&theInt)[2], ((char*)&theInt)[3]);


/* -- COMBINING STRUCS & UNIONS -- */

/*Structures and unions can be combined to create useful data structures which can hold multiple diffrent data types (doubles, floats, ints, etc)*/

struct operator {
    int type;
    union {
      int intNum;
      float floatNum;
      double doubleNum;
    } types;
};

/*Such a combined structure is accessed as a 'tagged' union meaning that the name of the struct must be refrenced then the element of the union that we wish to interact with.*/

operator op;
op.type = 0;
op.types.intNum = 352;

/*Alternatively if we don't tag the union in the struct we can access its elements directly from the struct as members.*/

struct operator {
    int type;
    union {
        int intNum;
        float floatNum;
        double doubleNum;
    }; //untagged union
};

operator op;
op.type = 0; // int
// intNum is part of the union, but since it's not named you access it directly off the struct itself
op.intNum = 352;


/* -- OTHER USECASES -- */

/* Another, perhaps more useful feature, is when you always have multiple variables of the same type, and you want to be able to use both names (for readability) and indexes (for ease of iteration), in that case you can do something like this: */

union Coins {
    struct {
        int quarter;
        int dime;
        int nickel;
        int penny;
    }; // anonymous struct acts the same way as an anonymous union, members are on the outer container
    int coins[4];
};


/* since the union makes the variables share the same memory the coins array matches with each int in the struct (in order): */

union Coins change;
for(int i = 0; i < sizeof(change) / sizeof(int); ++i)
{
    scanf("%i", change.coins + i); // Dangerous unprotected scanf could lead to buffer overflows POC only.
}
printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
    change.quarter, change.dime, change.nickel, change.penny); // By doing this we can convinently change the value of an input amount to the diffrent bases


/* -- PRINTING OUT CHARS FROM A SET OF INTEGERS EXAMPLE -- */


#include <stdio.h>
  
/* define the union here */
union integerCharacters {
	
    int integer[6];
    char chars[sizeof(integer)];
};
  
  
int main() {
    
   	// initializer lists like this are assigned to the first member of the union/struct!
        // There are 6 ints here so...
    union integerCharacters intCharacters = {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};
     

    /* testing code */
    printf("[");
    // only go to 18 because 1 byte is for the terminating 0 and we don't print the last in the loop
    for(int i = 0; i < 19; ++i)
        printf("%c, ", intCharacters.chars[i]);
    
    printf("%c]\n", intCharacters.chars[19]);
    
    printf("%s\n", intCharacters.chars);
}