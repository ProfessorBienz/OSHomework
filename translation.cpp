#include "cs_481_hw2_src/src.hpp"

#define BITS_PER_BYTE 8

// Return the virtual page number associated with the given virtual address
//      - page_size : size of pages
//      - addr_bits : number of bits in virtual address
void split_virtual_address(int virtual_address, int page_size, int* VPN, int* offset)
{

}



// Split VPN into index and tag
// Assuming k-way associative TLB
void split_VPN(int VPN, int k, int* index, int* tag)
{

}





// TLB is k-way associative
//     - Find TLB entry, if it exists (return true)
//     - Otherwise, return false
int TLB_lookup(TLB* tlb, int VPN)
{

}





// Lookup VNP in Page Table
int table_lookup(PageTable* table, TLB* tlb, int VPN)
{

}





// Convert PFN and Offset to Physical Address
int get_physical_address(int PFN, int offset, int page_size)
{

}





// Put everything together to get physical address from virtual
int virtual_to_physical(int virtual_address, int page_size, TLB* tlb, PageTable* table)
{

}

