#include <stdio.h>

unsigned short swap_bytes(unsigned short i);
unsigned short swap_bytes_condensed(unsigned short i);

int main(void)
{
    unsigned short hex_numbers;

    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%hx", &hex_numbers);

    printf("Number with bytes swapped: %hx\n", swap_bytes(hex_numbers));

    return 0;
}

unsigned short swap_bytes(unsigned short i)
{
    unsigned short high_byte = i << 8;
    unsigned short low_byte = i >> 8;

    return high_byte | low_byte;
}

unsigned short swap_bytes_condensed(unsigned short i)
{
    return i << 8 | i >> 8;
}