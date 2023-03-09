# Homework 2 : Paging and Replacement Algorithms

## Part 1 : Virtual Memory 
The goal of this portion of the programming assignment is to convert a virtual address to the corresponding physical address.  You will accompilish this with five helper methods, all within the file translation.cpp

### 1.a) Finding VPN and Offset : method ```split_virtual_address(...)```
This method is passed the following parameters : 
- ```int virtual_address``` : the virtual address of the instruction 
- ```int page_size``` : the number of bytes per page
- ```int* VPN``` : pointer to which method should return VPN
- ```int* offset``` : pointer to which method should return offset

Given the virtual address and page size, you should return the VPN and offset of the virtual address.  Assume the virtual address contains sizeof(int)\*BITS_PER_BYTE bits, where BITS_PER_BYTE is defined for you in the file.

### 1.b) Finding TLB tag and index : method ```split_VPN(...)```
This method is passed the following parameters :
- ```int VPN``` : the virtual page number
- ```int k``` : the number of sets in the TLB (k-way associative)
- ```int* index``` : pointer to which method should return TLB index
- ```int* tag``` : pointer to which method should return TLB tag

Given the VPN and value of k, you should return the TLB index and tag.

### 1.c) Checking TLB for PTE : method ```TLB_lookup(...)```
This method is passed the following arguments : 
- ```TLB* tlb``` : a pointer to a k-way associative TLB cache object
- ```int VPN``` : the virtual page number

#### 1.c.1 : Search the TLB for the given VPN  
- The value ```tlb.k``` holds the dimension of the k-way associative set.
- The ```tlb->lookup(int index, int tag, TLB\_entry* entry)``` returns a boolean indicating whether the index and tag are currently in the TLB.  If the entry is found, it is returned in the pointer ```TLB\_entry* entry```.  Otherwise, the pointer returns as NULL.
#### 1.c.2 : If the VPN is not in the TLB, throw a TLB miss exception.
- The method ```tlb_miss()``` will throw a TLB miss exception
#### 1.c.3 : If the table entry exists in the TLB and it cannot be accessed, throw a protection fault.
- The method ```entry->can_access()``` returns true if and only if the entry can be accessed (e.g. is not protected).
- The method ```protection_fault()``` throws a protection fault exception.
#### 1.c.4 : If the VPN is in the TLB and can be accessed, return the associated physical frame number
- The variable ```entry->PFN``` holds the physical frame number of a variable TLB_entry* entry.

### 1.d) Search the Page Table for the given VPN : method ```table_lookup(...)```
This method is passed the following arguments : 
- ```PageTable* table``` : a pointer to the page table
- ```TLB* tlb``` : a pointer to a k-way associative TLB cache object
- ```int VPN``` : the virtual page number

#### 1.d.1 : Search the Page Table for the given VPN
- The function ```table->lookup(int VPN)``` will return the page table entry ```PTE* entry``` associated with the given VPN
#### 1.d.2 : If the PTE is not valid, throw a segmentation fault
- The variable ```entry->valid_bit``` holds 1 if the entry is valid, and 0 otherwise.
- The method ```segmentation_fault()``` throws a segmentation fault exception.
#### 1.d.3 : Otherwise, if you cannot access the entry, you will throw a protection fault
- The method ```entry->can_access()``` will return true if and only if the entry can be accessed (e.g. is not protected)
- The method ```protection_fault()``` throws a protection_fault exception.
#### 1.d.4 : Otherwise, if the entry is not present in the page table, throw a page fault
- The variable ```entry->present_bit``` will hold 1 if the page is present in main memory, and 0 otherwise.
- The method ```page_fault()``` throws a page fault exception.
#### 1.d.5 : Finally, add the entry to the TLB and return the associated physical frame number
- The method ```tlb->add_entry(int index, int tag, int PFN, entry->protect_bit)``` will add the variable ```PTE* entry``` to the TLB at the specified index and tag, with the protection settings given by the protect bit.
- The variable ```entry->PFN``` holds the physical frame associated with the variable ```PTE* entry```
- Return the PFN

### 1.e) Form physical address : method ```get_physical_address(...)```
This method is passed the following arguments : 
- ```int PFN``` : physical frame number
- ```int offset``` : offset of address location within page/frame
- ```int page_size``` : the number of bytes per page

Return the physical address, which can be found by combining the PFN and offset.  Assume the physical address contains sizeof(int)\*BITS_PER_BYTE bits, where BITS_PER_BYTE is defined for you in the file.

### 1.f) Translate the virtual to physical address
This method is passed the following arguments :
- ```int virtual_address``` : the virtual address of the instruction 
- ```int page_size``` : the number of bytes per page
- ```TLB* tlb``` : a pointer to a k-way associative TLB cache object
- ```PageTable* table``` : a pointer to the page table

Using all of the methods that you have completed above, convert a given virtual address to
the associated physical address. First, look for the VPN in the TLB, catching any fault that
occurs. If a TLB miss exception is thrown (e.g. you catch the string ""TLB Miss!"), find the PFN in the Page Table instead. 
**You will need to use a try-catch statement to catch TLB miss exceptions (and continue to throw any other fault with ’throw’).  This is a C++ method, but doesn't require knowledge of C++.  Information on try/catch/throw is available at [Try-catch-throw-statement webpage](https://learn.microsoft.com/en-us/cpp/cpp/try-throw-and-catch-statements-cpp?view=msvc-170)**


## Part 2 : Replacement Algorithms
For this part of the programming assignment, you will write three different frame replacement algorithms. To do this, you will edit the file replacement.cpp.  Each method is passed a FrameList\* object along with a pointer to a FrameList\*. The FrameList\* object has the following methods:
- ```FrameList* next``` : the next frame in the linked list
- ```int idx``` : the index indicating when the associated page was last accessed. The higher the
index, the more recently accessed.
- ```int clock bit``` : the bit used for the clock algorithm (either 0 or 1).

Complete the following methods, each returning a pointer to the FrameList* object selected for removal. The methods each return an integer of the number of FrameList* objects accessed throughout
the method.

### 2.a) FIFO Replacement : method ```fifo(...)```
Implement the first in, first out frame replacement algorithm. The FrameList\*
linked list object is ordered by which arrived first, with the head of the list arriving least
recently, and the tail arriving most recently. Return the number of FrameList\* objects
accessed during this algorithm, along with the FrameList\* to be removed.

### 2.b) Least Recently Used Replacement : method ```lru(...)```
Implement the least recently used frame replacement algorithm.  Each FrameList* object holds an index for when it was last accessed. The higher the index, the more recently accessed. Assume this index is unique. Return the number of FrameList\* objects accessed during this algorithm, along with the FrameList\* to be removed.

### 2.c) Approximate Least Recently Used : method ```clock_lru(...)```
Implement the clock algorithm for approximating LRU. Start with the head of the linked list, and step through
checking if FrameList\* object should be removed, or if the clock bit should be reset.
Return the number of FrameList\* objects accessed during this algorithm, along with the
FrameList\* to be removed.
