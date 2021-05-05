# Operating Systems

![OS Cover Diagram](./images/OS_Diagram.svg)

## Contents

► [Overview](#Overview)    
► [Glossary of Terms](./TermsGlossary.md)    
► [OS/161 Case Study OS](./os_161.md)   
► [Processes and Threads](./Processes_Threads.md)  
► [Concurrency and Synchronisation](./Concurrency_Synchronisation.md)   
► [Deadlock](./Deadlock.md)  
► [System Calls](./Syscalls.md)   
► [Memory Hierachy and Caching](./MemoryHierachy.md)   
► [File Management](./FileManagement.md)   
► [Memory Management](./MemoryManagement.md)   
► [Virtual Memory](./VirtualMemory.md)   
► [Multiprocessors](./Multiprocessors.md)   
► [Scheduling](./Scheduling.md)   
► [I/O](./IO.md)

## Overview

* The Operating System OS is a fundemental base for the large majority of softwear
* Losely speaking Operating Systems have two broad goals


### Roles

#### Abstract Machine

* To be effective as a platform on which to build other software it must provide highlevels of abstraction while exposing an interface to many common and useful operations for applications to use


#### Resource Manager

* To run any number of useful programs the OS must be able to efficently manage the allocation of resources to users and processors
* It must also dispatch and recall processes fairly and efficently to achive this
* It must also enforce resource policies and permissions