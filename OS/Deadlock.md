# Deadlock

![Deadlock Topic Map](./images/Deadlock.svg)

## Overview

When one or more processes depending on another process which is depending on one of those processes to carry out a particular operation creating a unsoluble loop of dependence. This is the state of deadlock.

► [Conditions For Deadlock](#Conditions%20For%20Deadlock)   
► [Mitigating Deadlock](#Mitigating%20Deadlock)   

## Conditions For Deadlock

In general deadlock arises when processes are granted exclusive access to devices, locks, tables or other resources.

This can happens when the following four conditions are present:

1. Mutual exclusion 
    
    - Each resource can only be assigned to one process 
    - The resource must be finite

2. Hold and wait condition

    - A process holding a resource needs to request another resource
    - Thus the process is holding a resource while it waits for another 

3. No preemption condition

    - Previously granted resources cannot be forcibly taken away, or reaped by the OS
    - Resources granted to a process cannot be reclaimed forcibly, the process must release them

4. Circular wait condition

    - There exists a circular chain of 2 or more processes
    - Each process waits for a resource held by the next member of the chain


## Mitigating Deadlock

There are four general approaches to deadlock that have been adopted in operating systems programming and design:

1. Outright ignoring the problem and sacrificing relability amoung other issues
2. Prevention by negating one of the conditions necessary for deadlock
3. Detection and recovery
4. Dynamic avoidance via careful resource allocation


### Approach #1 :: Ignore

* Only makes sense if

    - Deadlock occurs rarely in the system
    - Cost of deadlock prevent in the system is high

* It is used in extremely complex resource relations where it is easier (more conviniet) to ignore it than handle it

### Approach #2 :: Prevent

* The OS inforces rules for resource allocation which specifically prevent one of the four deadlock conditions from occuring.

#### 1. Targeting mutex

    - In general this is not a feasible approach since we often implement mutex to tackle concurrency issues
    - Often devices/resources are not intrinsically shareable

#### 2. Targeting hold and wait

- Require processes to request resources upfront before executing
- A process need never wait for a particular resource since it will be avaliable when it starts

##### Issues

- It is not always possible to know what resources will be required before starting
- Means that resources are more commonly unavailable to other processes that could be using it

##### Variations

* Process must give up (release) all resources if it would block while holding a resource
* The process then requests all immediately needed resources
* Prone to livelock, never actually get to hold the needed resources

#### 3. Targeting no preemption

* In general not a viable option
* Jobs may frequently fail to complete
* The job failing may have a huge performance hit

    - Printer job gets terminated halfway ... 

#### 4. Targeting circular wait

* This is generally the best approach and most commonly implemented
* Numerically order the acquiring of resources relative to each process
* That is the resources are acquired in a pre-determined, programically enforced order universally


### Approach #3 :: Detection and Recovery

* Detect that deadlock is occuring in the system and thus need a method to determine if a system is deadlocked
* If deadlock is detected a recovery mechanism executes to restore progress to the system
* If the system is represented as a graph, detection of cycles can be used to signify deadlock
* Need more complex data structures to represent resources that consist of more than a single unit


#### Detection Algorithm 

Assume two matrices:

- A current allocations matrix :: C 
- A requests matrix :: R

1. Look for an unmarked process Pi, for which the i-th row of R is less than or equal to A
2. If found, add the i-th row of C to A, and mark Pi. Go to step 1
3. If no such process exists, terminate

The remaining processes are deadlocked.


#### Recovery

* **Preemption**

    - Take a resource from some other process
    - Varied performance based on nature of the resource

* **Rollback**

    - Checkpoints of a process are stored periodically
    - On deadlock rollback to this saved state
    - Restart the process from this state
    - There is still a possibility for the process to deadlock again

* **Kill**

    - A simple but crude way to break deadlock
    - Simply kill one of the processes in the deadlock cycle
    - Restart it after the other processes obtains the resource

### Approach #4 :: Deadlock Avoidance

* Avoid deadlock entirely 
* Relies on having a great deal of information available about the system in advance including the maximum number of each resource required by a process
* Uses the notion of safe and unsafe states to make decisions

#### Safe and Unsafe States


##### Safe State

* A safe state is a state when the system is not deadlocked. There exists a scheduling order that results in every process running to completion, even if they all request their maximum resources immediately 

##### Unsafe State

* An unsafe state does not necessarily that the system will result in deadlock, it could be lucky and complete with out an issue. We can however not guarantee that the system will complete (not deadlock)

* A deadlock avoidance algorithm in essence only adds processes that will ensure a safe status 

#### Bankers Algorithm

* Keep the system (bank) in a safe state
* Processes are only allowed to proceed if there are enough resources to accommodate their maximum possible request. Otherwise they have to wait for other processes to return resources before continuing. 
* Although the bankers algorithm will prevent a deadlock it is impractical to know the maximum number of resources required in advance. 
* Not commonly used in practice


