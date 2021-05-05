# Operating Systems

![](./images/OS_Diagram.svg)

## Contents

► [Overview](#Overview)    
► [Glossary of Terms](./TermsGlossary)    
► [OS/161 Case Study OS](./os_161)   
► [Processes and Threads](./Processes_Threads)  
► [Concurrency and Synchronisation](./Concurrency_Synchronisation)   
► [Deadlock](./Deadlock)  
► [System Calls](./Syscalls)   
► [Memory Hierachy and Caching](./MemoryHierachy)   
► [File Managment](./FileManagment)   
► [Memory Managment](./MemoryManagment)   
► [Virtual Memory](./VirtualMemory)   
► [Multiprocessors](./Multiprocessors)   
► [Scheduling](./Scheduling)   
► [I/O](./IO)

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