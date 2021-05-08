# File Management

![File Management Topic Map](./images/FileManagement.svg)

## Overview

* File systems provide an abstraction between low level hardwear interations required to retrive data from disk
* They provide a way to represent diffrent kinds of files like directories and binaries to the user while still being highly efficent at searching and storage size minimisation

## The File System

![File System Stack Diagram](./images/FileSystemStackDiagram.svg)


## i-nodes

* Stores meta data about a file useful for allocation and organisation
* They also store refrences to 

    - Direct Blocks 
    - Single indirect blocks
    - Double indirect blocks
    - Tripple indirect blocks

![Inode contents](./images/i-node.svg)

### Files Under i-nodes

* Files associated with a inode number
* If the file is small it will generally fit within the i-nodes direct blocks, thus stored in the i-node itself
* Larger files will make use of the single, double and, tripple indirect blocks stored in the i-node
* If a i-nodes reference count is 0 no names exist for that i-node and it is lost/unreachable adn can be deleted

### Directories Under i-nodes

* Directories are a special kind of file that translate names to i-node numbers
*  A directory entry contains only a name for the associated file and a pointer to the file itself, this pointer is an i-node number