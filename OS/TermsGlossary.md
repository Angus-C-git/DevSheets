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

### Critical Region



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


### Livelock

* Livelocked processes are not blocked, change state regularly,
but never make progress

### Lock


### Mutual Exclusion (Mutex)

* Mutual exclusion is the ensurance that no two processes can simultaneously be in their critical regions


### Process



### Race Condition

* A race condition is a scenario introduced by poor concurrency managment, I.E absance or lack of synchronisation, where multiple processes/threads compete to modify a shared resource

### Spinlock


### Starvation 

* A process never receives the resource it is waiting for, despite the resource (repeatedly) becoming free, the resource is always allocated to another waiting process
* Can be resolved with a first come first served policy