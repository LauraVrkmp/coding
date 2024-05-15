#include <stdio.h>

#define M(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))

int main(void)
{
    unsigned short x, y;
    x = 0x0100;
    y = 0x1101;
    printf("%x\n%x\n\n", x, y);

    M(x, y);

    printf("%x\n%x\n", x, y);

    return 0;
}