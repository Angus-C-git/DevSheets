# Files {C}

## Libary Overview

The majority of functions for interacting with files are contained in the `stdio.h` libary which is apart of the standard C libary collection.

`#include <stdio.h>`

## Opening Files

To open a file on disk the typical approach is to use the command:

`FILE *file_pointer = fopen("file_name", "mode");`

### Opening Modes

`*Note multiple mode arguments can be supplied at a time`

| Mode Argument  | Purpose                     | Additional                                   |  
|--------------- |---------------------------- | -------------------------------------------- |
| `r`            | Open a file for reading     | Returns NULL on error                        |
| `w`            | Open a file for writing     | File will be created or existing overwritten |
| `a`            | Append to the end of a file | If file does not exist it will be created    |
| `b`            | Binary mode modifier        |                                              |

### Usage 

```
// open a file for reading, error on fopen returns NULL

// open a file in read mode 
FILE *file_ptr = fopen("file.txt", "r");

// if the file doesn't exist or another error 
// (such as permissions) occurs print to stderror
// and exit.
if (!file_ptr) {
    perror("file.txt");
    exit(0);
}

```

## Closing Files

Once an operation has finished on a file pointer it is good practice to flush the file pointer uisng the `fclose()` function.

### Usage

`fclose(file_ptr);`

## Reading Files

There are a wide variety of ways to read files in C that vary based on use case. The following covers a large majority (and most common) of these use cases.

### Reading Bytes

To read a file one byte at a time the `fgetc` function can be utilised. While fgetc has limited function it is good enough for the large majority of byte at a time file reads. The `fgetc` function reads a byte at a time as a unsigned integer, returns `EOF` if the end of file marker is reached.

The function is used in the following way.

```
# read the contents of a file until EOF
FILE *file_ptr = fopen("file.txt", "r");

int c;
while ((c = fgetc(file_ptr)) != EOF)
    printf("Read: %d\n", c);

// Flush the file as a good practice
fclose(file_ptr);
```

## Writing Files


## File Meta Data