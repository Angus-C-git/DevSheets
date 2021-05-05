# Concurrency and Synchronisation

![Concurrency and Synchronisation Diagram](./images/Concurrency_Synchronisation_Mindmap.svg)

## Overview

* When multiple threads or processes modify a resource/variable/element shared between them they are accessing the global item concurrently
* This leads to timing control issues where natively it cannot be ensured which process/thread will modify the shared element when
* Proccesses which compete to modify a shared element introduce race conditions which lead to the behaviour of a system becoming unpredictable and thus useless
* It is for this reason synchronisation exists to handle concurrency effectively

► [Overview](#Overview)   
► [Critical Regions](#Critical%20Regions)   
► [Mutual Exclusion](#Mutual%20Exclusion)  
► [Synchronisation Primitives](#Synchronisation%20Primitives)   
► [Producer Consumer Problems](#Producer%20Consumer%20Problems)    
► [Dining Philosophers Problem](#Dining%20Philosophers%20Problem)


## Critical Regions

* A critical region is a segment within a program that modifies a shared resource 

    - Global Variables
    - Files
    - Memory

* If access to these shared resources is not properly controlled or the process is allowed to freely interact with the resource then race conditions will be introduced

### Race Conditions

* A race condition is a scenario introduced by poor concurrency managment, I.E absance or lack of synchronisation, where multiple processes/threads compete to modify a shared resource

### Managing Critical Regions


* To effectively prevent race condtions access to shared resources must be strictly managed programically
* For this we require mutal exclusion and careful synchronisation of critical regions in the program
* For any solution the following conditions are necessary

1. Mutal exclusion
2. No assumptions made about processor speeds or numbers
3. The solution must allow progress of other proceses outside of its crital regions
4. The solution must eventually enter its critical region (bounded)

## Mutual Exclusion

* Mutual exclusion is the ensurance that no two processes can simultaneously be in their critical regions


### Approaches To Mutal Exclusion

* **Mutual Exclusion By Taking Turns**

    - Relies on strict alternation between each process taking turns
    - Often leads to busy waiting

* **Mutal Exclusion By Disabling Interrupts**

    - Disable interrupts on critial region entry
    - Renable interrupts upon leaving the critical region
    - Simple to implement
    - Only avaliable in the kernel
    - Fails on a multiprocessor

* **Mutual Exclusion With Test-and-Set**

    - A hadwear supported approach that guarantees that an instruction will be executed atomically thus insuring mutex
    - Often implemented as a assembly instruction known as `TLS`
    - Simple to prove works
    - Avaliable at user-level
    - Leads to busy waiting A.K.A spinlocks


## Synchronisation Primitives

* The following are diffrent methods to ensuring mutal exclusion and synchronisation
* Each has its own pros, cons and common applications


### Locks

* A simple mechanism for mutal exclusion wherin a process aquires a lock before it enters a critical region and releases it at the end of the critcal region
* Issues arrise when locks fail to be released or multiple locks are acquired in diffrent orders accross a programs scope
* Incorrect ussage of locks leads to deadlock


```c
// os/161 lock implementation

/*
 * Simple lock for mutual exclusion.
 *
 * When the lock is created, no thread should be holding it. Likewise,
 * when the lock is destroyed, no thread should be holding it.
 *
 * The name field is for easier debugging. A copy of the name is
 * (should be) made internally.
 */
struct lock {
        char *lk_name;
        HANGMAN_LOCKABLE(lk_hangman);   /* Deadlock detector hook. */
        struct wchan *lk_wchan;
        struct spinlock lk_lock;
        struct thread *volatile lk_holder;
};

struct lock *lock_create(const char *name);
void lock_destroy(struct lock *);

/*
 * Operations:
 *    lock_acquire - Get the lock. Only one thread can hold the lock at the
 *                   same time.
 *    lock_release - Free the lock. Only the thread holding the lock may do
 *                   this.
 *    lock_do_i_hold - Return true if the current thread holds the lock;
 *                   false otherwise.
 *
 * These operations must be atomic. You get to write them.
 */
void lock_acquire(struct lock *);
void lock_release(struct lock *);
bool lock_do_i_hold(struct lock *);

```

### Semaphores

* A collection of two sub-primitives:

    - P() :: Proberen (test)
    - V() :: Verhogen (increment)

* If a resource is not available, the corresponding semaphore blocks any process waiting for the resource
* Blocked processes are put into a process queue maintained by the semaphore which prevents busy waiting
* When a process releases a resource, it signals this by means
of the semaphore
* Signalling will resume a blocked process if there is one in the queue
* P and V are atomic operations
* Chaining multiple semaphores can achive complex coordnation

```c
// os/161 semaphore implementation


struct semaphore {
        char *sem_name;
        struct wchan *sem_wchan;
        struct spinlock sem_lock;
        volatile unsigned sem_count;
};

struct semaphore *sem_create(const char *name, unsigned initial_count);
void sem_destroy(struct semaphore *);

/*
 * Operations (both atomic):
 *     P (proberen): decrement count. If the count is 0, block until
 *                   the count is 1 again before decrementing.
 *     V (verhogen): increment count.
 */
void P(struct semaphore *);
void V(struct semaphore *);

```

### Condition Variables 

* Condition variables (CVs) are primarily useful when blocking while waiting for an event, while aslo providing mutal exclusion
* Esentially a wrapper for monitors
* They allow a process to wait within a monitor 
* CVs make use of two operations:

    - Wait :: the process calling the operation is suspended until another process calls the wait function, this allows another thread to enter the monitor while the other is sleeping
    - Signal :: Resumes one suspended process, if no process is suspended the signal is meaningless



```c
// os/161 CVs

/*
 * Condition variable.
 *
 * Note that the "variable" is a bit of a misnomer: a CV is normally used
 * to wait until a variable meets a particular condition, but there's no
 * actual variable, as such, in the CV.
 *
 * These CVs are expected to support Mesa semantics, that is, no
 * guarantees are made about scheduling.
 *
 * The name field is for easier debugging. A copy of the name is
 * (should be) made internally.
 */

struct cv {
        char *cv_name;
        struct wchan *cv_wchan;
        struct spinlock cv_wchanlock;
};

struct cv *cv_create(const char *name);
void cv_destroy(struct cv *);

/*
 * Operations:
 *    cv_wait      - Release the supplied lock, go to sleep, and, after
 *                   waking up again, re-acquire the lock.
 *    cv_signal    - Wake up one thread that's sleeping on this CV.
 *    cv_broadcast - Wake up all threads sleeping on this CV.
 *
 * For all three operations, the current thread must hold the lock passed
 * in. Note that under normal circumstances the same lock should be used
 * on all operations with any particular CV.
 *
 * These operations must be atomic. You get to write them.
 */
void cv_wait(struct cv *cv, struct lock *lock);
void cv_signal(struct cv *cv, struct lock *lock);
void cv_broadcast(struct cv *cv, struct lock *lock);

```

## Producer Consumer Problems

* Also reffered to as the bounded buffer problem
* A scenario where a producer is producing data items and storing them in a bounded buffer
* A consumer takes the items out of the buffer and consumes them
* These two operations (consumption, production) are seperate and concurrent
* This leads to the challenge of keeping an accurate count of elements in the buffer as they are added and removed concurrently


### Producers Perspective

* Needs to sleep when the buffer is full since cannot add anything else
* Needs to wakeup when there is empty space in the buffer
* Will signal consumer when the first item is added to the buffer


```c
int count = 0;
#define N 4 /* buf size */
prod() {
    while(TRUE) {
        item = produce()
        if (count == N)
            sleep(prod);
        
        insert_item();
        count++;
        
        if (count == 1)
            wakeup(con);
    }
}

```

### Consumers Perspective

* Needs to sleep when the buffer is empty
* Needs to wakeup when there are items avaliable in the buffer
* Will signal producer to wakeup when the buffer is empty


```c
con() {
    while(TRUE) {
        if (count == 0)
            sleep(con);
        
        remove_item();
        count--;

        if (count == N-1)
            wakeup(prod);
    }
}
```

### The Challenge

* Need to avoid the counter and buffer being modified concurrently in order to maintain accuracy in the overall procedure

### Non-Solutions

* Using test and set (TSL) fails since the action of sleeping and checking a condition needs to be atomic
* The lock is held while asleep and thus the count can never change to trigger the wakeup of the process

### Soltuion

* Semaphores provide the requirments we need for an effective solution

#### Semaphore Delecration

```c

#define N = 4

semaphore mutex = 1;
/* count empty slots */
semaphore empty = N;
/* count full slots */
semaphore full = 0;

```

#### Producer 

```c
prod() {
    while(TRUE) {
        item = produce()
        wait(empty);
        wait(mutex);

        insert_item();
        
        signal(mutex);
        signal(full);
    }
}

```

#### Consumer 

```c
con() {
    while(TRUE) {
        wait(full);
        wait(mutex);

        remove_item();
        
        count--;

        signal(mutex);
        signal(empty);
    }
}
```

## Dining Philosophers Problem

**Let Philosophers be defined in the following way:**

* Philosophers eat/think
* Eating needs 2 forks
* Pick one fork at a time

* How can we avoid deadlock?

### Solution #1

```c
#define N       5 

#define LEFT (i+N-1) % N

#define RIGHT (i+1) % N  

#define HUNGRY 1

#define EATING 2

typedef int semaphore;

int state[N];

semaphore mutex = 1;
semaphore s[N];

void philosopher(int i)
{
    while (TRUE) {
        think();
        take_forks();
        eat();
        put_forks(i);
    }
}
```