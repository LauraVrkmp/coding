#include <stdio.h>

int main(void) 
{
        int total = 2;

        printf("%d\n", 9 -((total - 1) % 10));
        printf("%d\n", (10 - (total % 10)) % 10);

        return 0;
}