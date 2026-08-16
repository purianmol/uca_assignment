#include <stdio.h>
#include <stdint.h>

void address_translation(uint32_t virtual_address) {
    uint32_t page_number = 0;
    uint32_t offset = 0;

    // TODO: Calculate page_number using a right-shift operation (>>)
    // page_number = ...

    page_number = virtual_address >> 12;

    // TODO: Calculate offset using a bitwise AND operation (&) with mask 0xFFF
    // offset = ...
    offset = virtual_address & 0xFFF;

    printf("[1A] Addr: 0x%08X -> Page: %u (0x%X), Offset: %u (0x%X)\n",
           virtual_address, page_number, page_number, offset, offset);
}
int main(){
    int testcase1 = 0x00000000;
    int testcase2 = 0x00000FFF;
    int testcase3 = 0x00001000;
    int testcase4 = 0x00003A2C;

    address_translation(testcase1);
    address_translation(testcase2);
    address_translation(testcase3);
    address_translation(testcase4);
}
