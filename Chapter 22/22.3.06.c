#include <stdio.h>

int main(void)
{
    int i = 2;

    printf(i == 1 ? "%d widget" : "%d widgets", i);

    return 0;
}