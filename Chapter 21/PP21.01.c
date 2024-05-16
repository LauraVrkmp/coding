#include <stdio.h>
#include <stddef.h>

struct s {
    char a;
    int b[2];
    float c;
} s1;

int main(void)
{
    printf("Size of a: %d, offset: %d\n", sizeof(s1.a), offsetof(struct s, a));
    printf("Size of b: %d, offset: %d\n", sizeof(s1.b), offsetof(struct s, b));
    printf("Size of c: %d, offset: %d\n", sizeof(s1.c), offsetof(struct s, c));
    printf("Size of s: %d\n", sizeof(struct s));
}