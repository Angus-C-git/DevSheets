# MIPS & SPIM Assembler Cheat Sheet

## SPIM && MIPS Instructions 

### Bitwise Operations

| SPIM Instruction | MIPS Instruction | Example              | Notes                              |
| ---------------- | ---------------- | -------------------- | -----------------------------------|
| ADD Rd, Rs, Rt   | ADD Rd, Rs, Rt   | 



### Move && Load


| SPIM Instruction | MIPS Instruction | Example              | Notes/Description                                                                            |
| ---------------- | ---------------- | -------------------- | ---------------------------------------------------------------------------------------------|
| move Rd, Rs      |                  | move $s1, $v0        | 'Copy' the value stored in the register (memeory) on the right into the register on the left |
| mfhi Rd          | mfhi Rd          | mfhi $s1             |  Set a register equal to the high value in memory                                            |
| mflo Rd          | mflo Rd          | mflo $s1             |  Set a register equal to the low value in memeory                                            |
| la Rd, Addr      |                  | la $a0, prompt       |  Load an address into a register, could be a label or register                               |
| li Rd, imm       | lui	Rd, Imm   | li $v0, 4            |  Load a value immediately into a register, usable registers are 0..15, 16..31                |
| lb Rd, Addr      |                  | lb $s1, label        |  Load a byte at a particular mememory location                                               |
| lw Rd, Addr      |                  | lw $s1, x            |  Load a word at a particular mememory location                                               |
| sb Rs, Addr      |                  | sb $t1, y            |                                                                                              |


### Branches