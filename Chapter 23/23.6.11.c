#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "Testing this function";
    int n = 5;
    int len = strlen(s);

    char *start = (len > n) ? s + len - n : s;
    memset(start, '!', n);

    printf("%s\n", s);

    return 0;
}