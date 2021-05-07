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
    - 4 Kbyte page size

* `2^32 / 2^12 = 2^20` entires
* This is a huge address space for processes which are normally much smaler than this
* Enter multi-level page tables


### Multi-Level Page Tables

* Split the total bit range for the page table into two or more smaller bit ranges
* That is split the segment of the virtual address for the page table into more subdivisions
* Save space for sparsely populated process virtual address space (very common) by only allocating entries in the root page table that are mapped
* That is additional leaf page tables are only required when there exists a mapping in the base (root) page table
* Hence the overall size will be far smaller than the `2^20` entries calculated above (in the same conditions with a typical process)

### Two-Level Page Table

![Two Level Page Table Diagram](./images/TwoLevelPT.svg)

### Inverted Page Table

### Hashed Page Table

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