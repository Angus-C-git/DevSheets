# Terms Glossary

## Contents

► [Critical Region](#Critical%20Region)   
► [Deadlock](#Deadlock)   
► [Thread](#Thread)  
► [Lock](#Lock)   
► [Process](#Process)  
► [Race Condition](#Race%20Condition)  
► [Spinlock](#Spinlock) 

## Terms

### Atomic

* Something that operates as an indivisible unit. That is all parts of an atomic process execute as if they were one operation. In this way they are uninterubtable or divisible by any 


### Bitmap

* A data structure stored on disk to manage free disk blocks
* The use of a bitmap can simplify the task of allocating a contiguous range of disk blocks
* The bitmap reduces the disk capacity avaliable to be used for files 

### Critical Region

* A region in a program that modifies a shared resource

### Deadlock

* When one or more processes depending on another process which is depending on one of those processes to carry out a particular operation creating a unsoluble loop of dependence. This is the state of deadlock.

* A set of processes is deadlocked if each process in the set is waiting for an event that only another process in the set can cause

### External Fragmentation

* External fragmentation typically occurs in contiguous allocation schemes where as files are freed/deleted free space becomes avalible in small chunks between areas of allocated memeory. Since these chunks are often to small to be used by the majority of new files the space is wasted.
* Space is wasted externally to the allocated memory regions

### Internal Fragmentation

* Internal fragmentation typically arises in dynamic space allocation strategies where space is allocated in fixed sized blocks as needed. This means that if a process allocated to a particular block does not require/use all that space the block will be partially full and thus space is wasted.
* Space is wasted internally to the allocated memory partition

### Thread

* A unit of execution which can be traced and belongs to a process

### Thrashing

* Thrashing is the starvation of processes as memory avalibility becomes scarce due to the number of processes executing concurrently in a system.

### Livelock

* Livelocked processes are not blocked, change state regularly,
but never make progress

### Lock


### Mutual Exclusion (Mutex)

* Mutual exclusion is the ensurance that no two processes can simultaneously be in their critical regions


### Process

### PCB

* A processes’ information is stored in a process control block (PCB)
* The PCBs form a process table
* Reality can be more complex (hashing, chaining, allocation bitmaps,...)


### Race Condition

* A race condition is a scenario introduced by poor concurrency managment, I.E absance or lack of synchronisation, where multiple processes/threads compete to modify a shared resource

### Spinlock


### Starvation 

* A process never receives the resource it is waiting for, despite the resource (repeatedly) becoming free, the resource is always allocated to another waiting process
* Can be resolved with a first come first served policy


### Working Set

* The pages/segments required by an application in a time
window (&) is called its memory working set.
* Working set is an approximation of a programs’ locality
    - if & too small will not encompass entire locality.
    - if &  too large will encompass several localities.
    - if de&& = infinity will encompass entire program.

* &'s size is an application specific tradeoff
* System should keep resident at least a process’s
working set
