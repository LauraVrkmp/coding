#include <stdio.h>

int main(void)
{
    unsigned short i;
    i = 0x0000;
    printf("%x\n", i);

    i ^= 0x0010;

    printf("%d\n", i);

    return 0;
}