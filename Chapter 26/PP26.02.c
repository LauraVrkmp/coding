#include <stdio.h>
#include <stdlib.h>

void first(void);
void second(void);

int main(void)
{
    int count = 1000;
    atexit(second);

    while (count-- > 0)
        printf("%d", rand() & 1);
    printf("\n");
    atexit(first);
    return 0;
}

void first(void)
{
    printf("That's all, ");
}

void second(void)
{
    printf("folks!\n");
}