#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int i = 5;
    unsigned int j = 10;

    printf("%" PRId8 "\n", i);
    printf("%12.4" PRId32 "\n", i);
    printf("%-6" PRIo16 "\n", j);
    printf("%#" PRIx64 "\n", j);

    return 0;
}