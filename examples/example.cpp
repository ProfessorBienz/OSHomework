#include "cs_481_hw_src/src.hpp"
#include <string>
#include <algorithm>

void print_binary(int n)
{
    std::string binary_n;
    while (n) {
        if (n & 1)
            binary_n.append("1");
        else
            binary_n.append("0");
        n >>= 1;
    }
    std::reverse(binary_n.begin(), binary_n.end());
    printf("%s\n", binary_n.c_str());
}


int main(int argc, char* argv[])
{
    int virtual_address = 262735;
    int page_size = 4096;

    int vpn, offset;
    split_virtual_address(virtual_address, page_size, &vpn, &offset);

    printf("Virtual Address: ");
    print_binary(virtual_address);
    printf("Page Size: ");
    print_binary(page_size);
    printf("VPN: ");
    print_binary(vpn);
    printf("Offset: ");
    print_binary(offset);
}
