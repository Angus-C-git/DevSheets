#include <stdio.h>

/* -- BIT MASKING -- */

/*
	Bit masking is simply the process of storing data truly as bits, as opposed to storing it as chars/ints/floats. It is incredibly useful for storing certain types of data compactly and efficiently.
	Bit maksing is based on boolean logic.


	In computing, one of these true/false values is a bit. Primitives in C (int, float, etc) are made up of some number of bits, where that number is a multiple of 8. For example, an int may be at least 16 bits in size, where a char may be 8 bits. 8 bits is typically referred to as a byte. 
	C guarantees that certain primitives are at least some number of bytes in size. The introduction of stdint.h in C11 allows the programmer to specify integer types that are exactly some number of bytes, which is extremely useful when using masks.

	Bit masks are often used when setting flags. Flags are values that can be in two states, such as 'on/off' and 'moving/stationary'.
*/

/* -- SYNTAX NOTES -- */

exponent << base; // Syntax for powers

|= //OR operator

&= //AND operator

~ //Not operator

^= //XOR operator

/* -- SETTING A BIT N -- */

/*Setting bit n is done by ORing the value of the storage variable with the value 2^n.*/

storage |= 1 << n;

/* -- CLEARING A BIT N -- */

/*Clearing bit n is the result of ANDing the value of the storage variable with the inverse (NOT) of the value 2^n:*/

storage &= ~(1 << n);

/* -- FLIPPING A BIT N -- */

/*Flipping bit n is the result of XORing the value of the storage variable with 2^n:*/

storage ^= 1 << n;

/* -- CHECKING BIT N -- */

/*Checking a bit is ANDing the value of 2^n with the bit storage:*/

bit = storage & (1 << n);