#include <stdio.h>
#include <stdarg.h>

int max_int(int n, ...);

int main(void)
{
    int largest = max_int(5, 12, 15, 0);
    printf("%d", largest);
    return 0;
}

int max_int(int n, ...)
{
    va_list ap;
    int current, largest;

    va_start(ap, n);
    largest = n;

    while ((current = va_arg(ap, int)) != 0) {
        if (current > largest)
            largest = current;
    }

    va_end(ap);
    return largest;
}
