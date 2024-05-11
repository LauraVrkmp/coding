#include <stdio.h>

int main(void)
{
    int i = 10;
    while (i >= i) {
        printf("%d\n", i++);
        i /= 2;
    }

    return 0;
}