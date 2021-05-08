# Virtual Memory

![Virtual Memory Topic Map](./images/VirtualMemory.svg)

## Overview

Virtual memory is the collective abstraction of the hardwear, software and design that allows applications to have the view that main memory is a very large region of contiguous space.

It is the job of virtual memory managment to provide a mapping between virtual addresses, used by applications to refer to areas in memory, and physical addresses in main memory.


## Address Space Layout

![Typical Address Space Layout](./images/AddressSpaceLayout.svg)

### The 0th Page

* The 0th page is nearly always empty/null in any operating system
* This is to handle dereferencing a null pointer, when the program attempts to access this memory it will generate a fault and allow the VM to generate an error


## Page Based Virtual Memory

* Page based VM is the primary approach to providing the appearance that the machine has more memory than the size of physical memory would suggest 
* In this system memory is divided into equal sized pages (not always) 
* A mapping is provided which translates an address in a page to a physical frame address, or null if the physical address is not mapped
* Mappings are defined at runtime but change over the systems lifetime
* There is no requirment then for processes to have contiguous physical memory 

### Address Mapping

![Virtual Address Translation](./images/PageMapping.svg)

* In this way a process may only be partially resident in main memory 
* With parts of the program being stored on disk (non-resident)
* This saves memory by stashing infrequently used data and code sections from the program on disk
* When non-resident memory is accessed we generate a page fault
* The physical address space can be mapped to by multiple virtual address spaces

### Address Translation

* Since every memory address issued by the CPU is virtual it must be translated to a physical address to be used

    - Store
    - Load
    - Fetch

* For this we utilise translation hardwear
* In a paging system (discussed later), translation involved the replacment/conversion of the page number with/to a frame number

## Page Faults

* When a refrence to a virtual address which is not mapped (non-resident), or illegal (invalid/protected), occurs the virtual memory managment system generates a page fault
* A page fault is a kind of exception handled by the OS
* Broadly two kinds of page fault

    - Illegal address
    - Page not resident

### Illegal Address

* This means the referenced page does not exist or is not allowed to be accessed in some way
* This results in the process being signalled or killed 


### Page Non-Resident

* The page was not mapped to a physical address because it is stored on disk
* The handler will roughly

    - Find an empty frame
    - Laod the page from disk
    - Update the page table 
    - Restart the faulting instruction


## Page Tables

* A page table is a per-process data structure that stores a one-to-one mapping between virtual addresses and physical frame numbers
* Logically the page table is an array of frame numbers indexed by page number

![Simple One Level Page Table](./images/OneLevelPageTable.svg)

### Shared Pages

* It is possible to have processes share the same code regions in physical memory but with private data
* Consider the same program `gdb` used by multiple users 
* The code is the same for the program so it is shared in a read-only region
* The data region for each instance of the program however is private for that users instance

### Page Table Entries

* Stores further information about the nature of a page
* Typically the following is stored

    - Caching bit (Caching disabled ? y : n)
    - Referenced (Has the page been accessed, page out?)
    - Modified  (Should we page the entry out)
    - Protection (Read | Write | Execute)
    - Present / abset (is the mapping valid)
    - The page frame number (the physical frame address)

![PTE Diagram](./images/PTE.svg)


### Page Tables / Page Table Entries Per Process

* How many page table entries do we need for one process

    - Consider a 32-bit virtual address (4GB address space)
    - 4 Kbyte page size (for 32bit, 8 kByte for 64)

* `2^32 / 2^12 = 2^20` entires
* This is a huge address space for processes which are normally much smaler than this
* Enter multi-level page tables

* The number of page tables in the system is equal to the number of processes running in the system


### Multi-Level Page Tables

* Split the total bit range for the page table into two or more smaller bit ranges
* That is split the segment of the virtual address for the page table into more subdivisions
* Save space for sparsely populated process virtual address space (very common) by only allocating entries in the root page table that are mapped
* That is additional leaf page tables are only required when there exists a mapping in the base (root) page table
* Hence the overall size will be far smaller than the `2^20` entries calculated above (in the same conditions with a typical process)

### Two-Level Page Table

![Two Level Page Table Diagram](./images/TwoLevelPT.svg)

### Inverted Page Table (IPT)

* “Inverted page table” is an array of page numbers sorted (indexed) by frame number (it’s a frame table)
* Thus now we index by frame number to an entry which also contains the page number
* Because the performance hit of doing this normally would be large a hash table is used to speedup the translation

* Algorithm

1. Compute hash of page number
2. Extract index from hash table
3. Use this to index into inverted page table
4. Match the PID and page number in the IPT entry
5. If match, use the index value as frame # for translation
6. If no match, get next candidate IPT entry from chain field
7. If NULL chain entry -> page fault

#### Properties

* IPT grows with size of RAM, NOT virtual address space
* Frame table is needed anyway (for page replacement,
more later)
* Need a separate data structure for non-resident pages
* Saves a vast amount of space (especially on 64-bit
systems)

### Hashed Page Table

* Like IPT but use hashes of the virtual page number to index into the page table 

#### Properties

* HPT sized based on physical memory size
* With sharing

    - Each frame can have more than one PTE
    - More sharing increases number of slots used, Increases collision likelihood

## The TLB

* Also known as the Memory Management Unit (MMU)
* When given a virtual address the processor will first examine the TLB (Translation Lookaside Buffer)
* If a matching page table entry is found a TLB hit occurs and the address is translated (to its physical address)
* Otherwise a TLB miss occurs and the page number is used to index itno the processes page table 

    - If the page table contains a valid entry, reload the TLB and restart
    - Otherwise a page fault occurs and the disk is checked for the page

        - If the page is present on the disk swap it in
        - Otherwise allocate a new page or raise an exception

![TLB Diagram](./images/TLBEntries.svg)

### TLB Properties

* The TLB holds a recently used subset of page table entries which are tagged with the page number the TLB entry transaltes
* Thus access is by associative lookup, that is the entry in the TLB (physical frame | V | W | ect) is looked up using the page number

* TLB may be hardware or software loaded 
* TLB typically holds 64-128 entries
* Can have multiple TLBs with diffrent purposes (instruction fetch, data access)

### TLB Flushing

* TLB shared piece of hardware while page tables are per-process
* This means that entries in the TLB are process specific
* To handle this the TLB must be flushed, all entries invalidated, on a context switch
* OR tag TLB entries with an address-space ID (ASID)

    - Known as a tagged TLB
    - Primay approach used on all modern OS'

### TLB Performance Benifits

* **without TLB** 

    - Average number of physical memory references per virtual refrence is **2**

* **with TLB** (assuming 99% TLB hit ratio)

    - Average number of physical memory refrences per virtual reference is
    - `= 0.99 * 1 + 0.01 * 2`
    - `= 1.01`


## TLB Refill

* Typically handled by software
* Responsible for updating the TLB with frame numbers found in page table entries


## Locality and Working Sets

### The Principle of Locality

> Programs Spend 90% of their time in 10% of their code 

* Programs tend to reuse data amd instructions they have used recently
* We can exploit this locality of refrences since we can use it to reasonably predict what instructions and data a program will use in the near future based on its accesses in the recent past

### Temporal Locality

* states that recently accessed items are likely to be accessed in the near future

### Spatial locality

* says that items whose addresses are near one another tend to be referenced close together in time

### Working Set

* The pages/segments required by an application in a time window (&) is called its memory working set.
* Working set is an approximation of a programs’ locality
* The system should aim to keep resident at least a processes working set
* Note, the working set tends to change gradually

#### Working Set Considerations

If the pages/segments required by an application in a time window:

* are too small will not encompass entire locality
* are too large will encompass several localities
* approach infinity will encompass entire program

Thus & size is an application specific tradeoff.


## Thrashing

* Thrashing is the starvation of processes as memory avalibility becomes scarce due to the number of processes executing concurrently in a system.

* This often occurs when we try to maximise CPU utilisation by increasing the degree of multiprogramming which also leads to there being less memory avaliable per process

* When thrashing occurs CPU utilisation decreases and the system becomes I/O bound/limited

### Recovery From Thrashing

* Suspend a few processes to reduce degree of
multiprogramming
* Resident pages of suspended processes will migrate
to backing store
* More physical memory becomes available = Less faults, faster progress for runnable processe
* Resume suspended processes later when memory
pressure eases

## Page Size

* **Increasing Page Size**

    - Increased internal fragmentation
    - Decreasing number of pages = reduced size of page tables
    - Increased tlb coverage = reduced TLB misses
    - Increases page fault latency = need more disk reads before process restart
    - Increased swapping I/O throughput = small I/O are dominated by seek/rotation delays

* Most OS’ only support one page size, this is because dealing with varying page sizes is hard

* Increasing the page size generally increases the working set size of an application
* This is because the larger granularity of inclusion results in more virtual memory being included in the working set when only part of the page is actually accessed.

## Page Replacment Algorithms

* To have an efficient virtual management system we need a way to choose pages to stash to disk that will have the least impact on performance
* Generally this is the page least likely to be referenced in the near future
* Typically this metric is determined by analysing past behaviour and using it to predict future behaviour

### Optimal Replacement

* A theoretical upper bound algorithm where the page that **won't** be used for the longest time is stored to disk
* Impossible to implement in practice

### FIFO Replacement

 * First-in, first-out: Toss the oldest page
 * Easy to implement
 * Semi flawed metric in the sense that the age of the page isn't necessarily related to usage


### Least Recently Used

* Toss the least recently used page
* Assumes that page that has not been referenced for a long time is unlikely to be referenced in the near future
* Works if locality holds 
* Implementation requires a time stamp to be kept for each page, updated on every reference
* Impossible to implement efficiently, most implementations are approximations

### Clock Page Replacement

* Makes use of a reference bit in the frame table 
* Reference bit set to one when page is used
* When looking for a victim set each entries refrence bit to 0 one the way past
* Toss the first page with a zero reference bit

* We can use the valid bit in the page table entry to determine if the page is referenced
* When a page is mapped (valid bit set), set the reference bit
* When resetting the reference bit, invalidate the PTE entry
* On a page fault turn on the valid bit and reference bit in the PTE

## Cleaning Policy

* Clean pages are cheaper to replace than dirty ones


#### Demand Cleaning

* A page is written out only when it has been selected for replacement
* High latency between the decision to replace and availability of free frame

#### Precleaning

* Pages are written out in batches (in the background, the pagedaemon)
* Increases likelihood of replacing clean frames
* Overlap I/O with current activity