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