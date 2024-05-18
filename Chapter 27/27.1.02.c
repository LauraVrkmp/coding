#include <stdio.h>

#define INT32_C(n)  n ## L
#define UINT32_C(n) n ## UL
#define INT64_C(n)  n ## LL
#define UINT64_C(n) n ## ULL

int main(void) {
    long int a = INT32_C(12345);         // Equivalent to 12345L
    unsigned long int b = UINT32_C(12345); // Equivalent to 12345UL
    long long int c = INT64_C(123456789012345);   // Equivalent to 123456789012345LL
    unsigned long long int d = UINT64_C(123456789012345); // Equivalent to 123456789012345ULL

    printf("a: %ld\n", a);
    printf("b: %lu\n", b);
    printf("c: %lld\n", c);
    printf("d: %llu\n", d);

    return 0;
}
