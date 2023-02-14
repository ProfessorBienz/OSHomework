# Homework 2 : Paging and Replacement Algorithms

## Part 1 : Virtual Memory 
The goal of this portion of the programming assignment is to convert a virtual address to the corresponding physical address.  You will accompilish this with five helper methods, all within the file translation.cpp

### 1.a) Finding VPN and Offset : method split\_virtual\_address(...)
This method is passed the following parameters : 
- int virtual\_address : the virtual address of the instruction 
- int page\_size : the number of bytes per page
- int* VPN : pointer to which method should return VPN
- int* offset : pointer to which method should return offset

Given the virtual address and page size, you should return the VPN and offset of the virtual address.  Assume the virtual address contains sizeof(int)*BITS_PER_BYTE bits, where BITS_PER_BYTE is defined for you in the file.

### 1.b) Finding TLB tag and offset : method split\_VPN
This method is passed the following parameters :
- int VPN : the virtual page number
- int k : the number of sets in the TLB (k-way associative)
- int* index : pointer to which method should return TLB index
- int* tag : pointer to which method should return TLB tag

Given the VPN and value of k, you should return the TLB index and tag.

### 1.c) Checking TLB for PTE : method TLB\_lookup
This method is passed the following arguments : 
- TLB* tlb : a pointer to a k-way associative TLB cache object
- int VPN : the virtual page number

Search the TLB for the given VPN.  This can be done with the method ```tlb->lookup(int index, int tag, TLB\_entry* entry)
