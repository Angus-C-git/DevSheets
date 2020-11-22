#include <stdio.h>


/* -- STRUCTURES -- */

/*

	~ Structures are a kind of large variable which contain several named variables inside.
	~ Structures in C are the building blocks of objects and classes
	~ They are used to:
		- Serialise data
		- Passing multiple arguments in and out of functions through a single argument
		- Data structures such as linked lists, binary trees and others 
	
*/

/* --BASIC STRUCTS -- */

/* Points are the most basic type of struct, they define a single entity that contains two varaibles */


struct point { //coordinates

	int x;
	int y;

};

/* We can now define a point using our point struct*/


struct point p; //Define a variable p which is of type point (our structure)

/*We access members of a struct with the . character*/

p.x = 10; //Assign the memeber x of the point structure a value
p.y = 5;  //Assign the memeber y of the point structure a value

/*We can now pass our point object p as a single paramter which contains two sub values x, y*/

draw(p); //Hyperthetical function draw which takes an x,y value


/* We can shorten the decleration length of our objects using the typedef keyword */

typedef struct {
	int x;
	int y;
} point;


/*Now we can simply define a point object like: */

point p;

/* Structures can also be used to hold pointers, this allows for complex structures that point to other structures or hold strings */


typedef struct {
	
	char * brand;
	int model;

} vehicle;

/* We can then create objects of the struct and assign values like: */

vehicle mazda_mx5;

mazda_mx5.brand = "Mazda";
model = 2005;


