# Bitshifting {C}

Bitshifting is the process that occurs in C when one of the shift operators is applied. The two shift operatros are:

+ `>>` Right shift 
+ `<<` Left shift

Shift operations are typically of use when attempting to seperate out a fixed number of bits from a bit string or to perform low level bit operations.

## Right Shift

Imagine you have a string of binary numbers say 

`001101`

then visualise a string being attatched to the right end of the number

`001101 ---->`

if we perform a right shift of 1, `>> 1` on our binary number we can think of this as pulling the string one binary numbers distance to the right, making it disappear into the ether. 

`(001101 >> 1) => 000110`

Above you can see that shifting one place to the right drops off the bit one place from the right and a trailing `0` bit is added to the left-hand side of the bit string. This behaviour is common to all right shift operations, where by the magnitude of the shift (the ammount shiffted by) corresponds to the number of bits dropped from the right-hand side of the bit string and the number of trailing 0 bits added to the left-hand side of the number.


### Diagrammatically

![Right Shift Diagram](./images/Rightshift_Diagram.svg)

## Left Shift

Once again a good approach here is to imagine the exact opposite of the above right shift layout. Instead a string is attatched to the far left-hand side of the bit string, when bits are shifted left they are deleted/removed from the left-hand side of the bit string and trailing `0` bits added from the right-hand side.

Using the same example as above with the binary string,

`001101`

being left shifted by one place, 

`<-- 001101`

becomes,

`(001101 << 1) => 011010`

which is esentially the inverse of the right shift process.

### Diagrammatically

![Left Shift Diagram](./images/LeftShift_Diagram.svg)

## Masking

An accompying topic for shifting is 'bitmasking'. Bitmasking is the process of eliminating or retrieving a specific number or segment of bits from a bit string. It is typically done by creating a fixed string of bits referred to as a mask which is then combined with a bit operation like `OR` or `AND` to retrive the desired bits from an input bit string.

Consider a scenario where you want to retrive the first 4 bits from a 8 bit string. For a real world context this may be done to retrive the opcode from an assembly instruction for a emulator. Lets say the bit string is,

`10110101`

to retrive the first 4 bits we can employ a 4 bit mask of `1111` bits as follows. Let's look at the result of performing a `AND` (`&` in C) operation on our incident bit string and the bit mask.


![Masking Diagram](./images/Bitmask_Diagram.svg)

The resultant bit string will now only contain bits where to `1` bits were anded together. If we want to remove the trailing `0` bits left behind after the operation we can perform a right shift of 4, leaving us with `1011` as our final binary number.

### Programmatically 

```
// Crude bitmasking example

// 000...1011010 
int incident_bit_string = 0xb5;

// 000...1111
int mask = 0xf0;

// store the result
int result = 0;

result = incident_bit_string & mask;
printf("%x\n", result);

result >>= 4;
// print result in hex
printf("%x\n", result);	// 1011 
```


