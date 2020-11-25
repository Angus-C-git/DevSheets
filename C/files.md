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

### Reading Lines

It is a relatively common use case to want to read a line (or some number of bytes) of a file at a time and for this reason a number of functions exist within the file libary to do so. It is important however to note that not all of these functions are safe due to the way they copy data into a buffer. Un-guarded buffer copies in general create a higher probability of malcious users being able to create buffer overflows or users accidently supplying overtly large input files which crash the application. Hence it is prefered, and standard, to use guarded functions which force the programmer to specify how much data the application expects to copy at most. 

One of the most common functions for this is `fgets`. The function takes in 3 arguments in the following order. 

`fgets(buffer, size, file_pointer);`

Example usage is as follows.

```
FILE *file_ptr = fopen("file.txt", "r");

char buff[200];

// copy at most 199 bytes from
// supplied file.
fgets(buff, 200, file_ptr);
```

### Reading Binary Data

To read blocks of memory another read function is supplied by the `stdio` libary, `fread`. The function has the following arguments.

`fread(buffer, sizeof(elements), number_of_elements, file_ptr);`

Typically usage might look as follows.

```
FILE *file_ptr = fopen("file.txt", "r");

char bytes[BUFSIZE];

while (1) {
    size_t bytes_read = fread(bytes, sieof(char), 1, file_ptr);

    if (bytes_read <= 0)
        break;
}

fclose(file_ptr);
```

## Writing Files

For nearly every read function there is a accompanying write function. Again these vary on the use case.

### Write One Byte At Time

To write a a file one byte at a time the `fputc` function can be used. It takes two arguments in the following syntax.

`fputc(byte, file_pointer);`

The function can be used in the following way.

```
# write the number 42 into a file
FILE *file_ptr = fopen("file.txt", "w");

fputc(42, file_ptr);


// Flush the file as a good practice
fclose(file_ptr);
```

### Writing Lines

Similarly to reading a line the best practice here is to use a guarded write function, namely `fputs`. This function has the following syntax.

`fputs("string", file_pointer);`

The function can be used as follows.

```
# write an arbitary line to a file

FILE *file_ptr = fopen("the_fox.txt", "w");

fputs("The quick brown fox, you know the rest ...", file_ptr);

fclose(file_ptr);
```

### Writing Binary Data

A near copy of the read equivilent `fwrite` is one function used to write binary data. The function has the following arguments.

`size_t fwrite(buffer, size_t size_of_elements, size_t number_of_elements, FILE *file_pointer);`

```
# write the hex data 0x42 into a file

FILE *file_ptr = fopen("file.txt", "r");

char bytes[BUFSIZE] = 0x42;

fwrite(bytes, sizeof(char), 1, file_ptr);

fclose(file_ptr);
```

## Traversing Files

Other than reading through a file one byte at a time or x number of bytes at a time there are a few other ways to move through files namely:

+ `fseek`
+ `lseek` (not covered)

these functions allow us to easily skip through files based on a selection of metrics.

### fseek

This function allows us to accelerate the file pointer of a given file stream to a given offset.

`int fseek(file_pointer, offset, whence)`

+ offset: number of bytes from whence
+ whence: the position (from a selection) from which to offset

| Whence     | Description                          |
| -----------| -------------------------------------|
| `SEEK_SET` | Beginning of a file                  |
| `SEEK_CUR` | Current position of the file pointer |
| `SEEK_END` | End of file                          |


## File Meta Data

Another large and important part of file manipulation are the set of functions related to reading file metadata. On unix like operating sytems this kind of file 'header' information is stored in a data structure called INODES. There are many inbuilt functions in the C standard libary for accesing this meta data, the most important of these are:

+ `#include <sys/stat.h>`
+ `#include <sys/types.h>`

### Stat && The Stat Struct

Perhaps the most useful function in this section is the `stat` function which returns the stat struct for a given file. The function has the following syntax.

`stat(file_path, &stat_struct);`

To use the function the second argument must be declared as a `struct stat`, the stat structure contains the following feilds.

```
struct stat {
    dev_t       st_dev;         /* ID of device containing file */
    ino_t       st_ino;         /* Inode number */
    mode_t      st_mode;        /* File type and mode */
    nlink_t     st_nlink;       /* Number of hard links */
    uid_t       st_uid;         /* User ID of owner */
    gid_t       st_gif;         /* Group ID of owner */
    dev_t       st_rdev;        /* Device ID (if special file) */
    off_t       st_size;        /* Total size, in bytes */
    blksize_t   st_blksize;     /* Block size for filesystem I/O */
    blkcnt_t    st_blocks;      /* Number of 512B blocks allocated */

    struct timespec st_atim;    /* Time of last access */
    struct timespec st_mtim;    /* Time of last modification */
    struct timespec st_ctim;    /* Time of last status change */
};
```

Since the stat function can error on a wide array of issues including permissions and file existance it is important to catch errors from the function call in the following fashion.

```
if (stat(file_path, &s) != 0) {
    perror(pathname);
    exit(1);
}
```

By way of example we can print out all the fields in the struct with their corresponding type format flags.

```

printf("stat(\"%s\", &s)\n", pathname);

struct stat s;
if (stat(pathname, &s) != 0) {
    perror(pathname);
    exit(1);
}

printf("ino =  %10ld # Inode number\n", s.st_ino);
printf("mode = %10o # File mode \n", s.st_mode);
printf("nlink =%10ld # Link count \n", (long)s.st_nlink);
printf("uid =  %10u # Owner uid\n", s.st_uid);
printf("gid =  %10u # Group gid\n", s.st_gid);
printf("size = %10ld # File size (bytes)\n", (long)s.st_size);

printf("mtime =%10ld # Modification time (seconds since 1/1/70)\n",
        (long)s.st_mtime);

```


### File Macros

The libaries also include a number of diffrent macros which can be used to determine basic information about a file.

#### S_ISDIR

The `S_ISDIR` macro is one of the most useful of these macros and is used to determine if the provided mode constitutes a directory. It is used in the following fashion.

```
if(S_ISDIR(stat_struct.st_mode))
    /* dir actions */
```

#### Permission Macros

The set of permission macros can be used with `&` operations to determine if a file, based on its mode, pertains to certain properties namely:

+ Readablity
+ Writability 
+ Executiblity

for each of the three permission sets on UNIX like operating sytems. These three groups are.

| Group | Description                                          | Macro Pattern  |
| ----- | ---------------------------------------------------- |----------------|
| User  | The user resbonsible for the creation of the file.   | `S_I*USR`      |
| Group | The permissions associated with the files user group.| `S_I*GRP`      |
| Other | The other users on the system, global permissions.   | `s_I*OTH`      |

The three options for `*` are:

+ `R` for read permissions
+ `W` for write permissions
+ `X` for execute permissions

##### Usage

To utilise the macros the `st_mode` field from the stat struct is needed the mode is then anded with the corresponding macro returning `1` if the permission is set and `0` if the permission is not set.

```
// print the the permission fields for each 
// set of users for a given file

// char for present, - if the permission is not set

printf("%s", (S_IRUSR & st.st_mode) ? "r" : "-" );
printf("%s", (S_IWUSR & st.st_mode) ? "w" : "-" );
printf("%s", (S_IXUSR & st.st_mode) ? "x" : "-" );
printf("%s", (S_IRGRP & st.st_mode) ? "r" : "-" );
printf("%s", (S_IWGRP & st.st_mode) ? "w" : "-" );
printf("%s", (S_IXGRP & st.st_mode) ? "x" : "-" );
printf("%s", (S_IROTH & st.st_mode) ? "r" : "-" );
printf("%s", (S_IWOTH & st.st_mode) ? "w" : "-" );
printf("%s", (S_IXOTH & st.st_mode) ? "x" : "-" );
```

### Modifying File Metadata && OS Calls

#### Make Directory

A directory can be created with the following syntax.

```
if (mkdir(dir_name, permission) != 0) {
    perror(argv[arg]);  // prints why the mkdir failed
    return 1;
}
```


#### List Directory

By using a `DIR` pointer which is very similar to a `FILE` pointer we can traverse through directories.

```
// List the contents of a directory

for (int arg = 1; arg < argc; arg++) {
    DIR *dirp = opendir(argv[arg]);
    if (dirp == NULL) {
        perror(argv[arg]);  // prints why the open failed
        return 1;
    }

    struct dirent *de;

    while ((de = readdir(dirp)) != NULL) {
        printf("%ld %s\n", de->d_ino, de->d_name);
    }

    closedir(dirp);
}
```
