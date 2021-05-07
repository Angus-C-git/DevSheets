# Memory Management

![Memory Management Topic Map](./images/MemoryManagement.svg)


## Overview

OS Memory Management is the notion of keeping rack of what memory is in use and what memory is free to be used. It is the operating systems job to allocate free memory to processes when they need it and deallocate it when they are no longer using it. The memory manager is also responsible for transffering memory between RAM and disk.

## The Need For Memory Management

* The challenge is to keep track of how much free memory we have to allocate to process and to locate that free memory for them
* In order to have an efficient and effective OS we wish to maximise memory utilisation and CPU utilisation
* To do this we want to subdivide memory to run processes concurrently
* To do this we need memory management


## Fixed Partition Allocation Schemes

* Partitions start as one size and remain that size for system lifetime/uptime

### Equal Fixed Sized Partitions

* Divide memory into fixed equal size partitions
* Any process which will occupy less than the partition size can be loaded in
* Partitions are either free or busy (populated with a process)

**Cons**

* Any unused space in the partition is wasted

    - Internal Fragmentation

* Processes smaller than main memory but which exceed the partition size cannot be run

### Variable Size Fixed Partitions

* Memory is divided at boot time into an assortment of different sized partitions, may be based on some metric such as perceived workload
* Each partition has a queue

    - Processes queue for the smallest partition they fit in
    - Processes begin executing when the assigned partition is empty, and they are the head of the queue

**Cons**

* Many partitions likely to be idle since they are large, and the processes (jobs) small
* Knowledge of the workload at boot time is not likely to be known accurately


### Queue Strategy

* Single queue from which processes are added into (any [large/small]) partitions they will fit into

**Cons**

* Increased internal memory fragmentation


## Dynamic Partition Allocation Algorithms

* Partitions are of variable length and allocated on demand from ranges of available memory
* Processes are given the amount of memory they require/want

### Classic Approach / LLs

* Free memory is represented as a linked list
* Blocks of free memory in the list store

    - Base
    - Size
    - Other info (flags etc)

* Often kept in order of increasing size to simplify merging adjacent holes into larger holes


### First Fit

* Enumerate the list for the first entry that can fit a given process
* If the process is greater than the entry split the entry into allocated and free parts

#### Pros

* Often finds a match quickly

#### Cons

* Biases allocation to one end of memory
* Tends to preserve larger blocks at the end of memory

### Next Fit

* Enumerate the list from the last node that successfully stored a process
* If the process is greater than the entry split the entry into allocated and free parts

#### Pros

* Only hypothetical improvement: spread allocation more uniformly over entire memory to avoid skipping over small holes at start of memory

#### Cons

* Performs worse than first-fit as it breaks up the large free space at end of memory

### Best Fit

* Enumerate the list to find the block that is closest to the request

#### Pros

* Only hypothetical improvement: spread allocation more uniformly over entire memory to avoid skipping over small holes at start of memory

#### Cons

* Performs worse than first-fit
* Has to search complete list
* Since smallest block is chosen for a process, the smallest
  amount of external fragmentation is left
* Create lots of unusable holes


### Worst Fit

* Chooses the block that is largest (worst-fit)

#### Pros

* None, this is a ridiculous scheme

#### Cons

* Has to do more work (like best fit) to search complete list
* Does not result in significantly less fragmentation


## Fragmentation

### External Fragmentation

* External fragmentation typically occurs in contiguous allocation schemes whereas files are freed/deleted free space becomes available in small chunks between areas of allocated memeory. Since these chunks are often to small to be used by the majority of new files the space is wasted.

### Internal Fragmentation

* Internal fragmentation typically arises in dynamic space allocation strategies where space is allocated in fixed sized blocks as needed. This means that if a process allocated to a particular block does not require/use all that space the block will be partially full and thus space is wasted.


### Compaction

* Technique to reduce fragmentation
* Shuffle memory contents to place all free memory together in one large block
* Only works if we can relocate running programs and generally requires hardware support to save state


## Swapping

* A process can be swapped temporarily out of memory to a backing store, and then brought back into memory for continued execution

* Backing store is typically a fast disk large enough to accommodate copies of all memory images for all users
* Lower-priority process is swapped out so higher-priority process can be loaded and executed
* Major part of swap time is transfer time; total transfer time is directly proportional to the amount of memory swapped, thus it is slow
* Hence, the introduction of virtual memory