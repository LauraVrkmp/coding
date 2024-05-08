#include <stdio.h>
#include <stdbool.h>

#define length ((int) (sizeof(fibonacci) / sizeof(fibonacci[0])))
#define N 40

int main(void)
{
    int fibonacci[40] = {[0] = 0, [1] = 1};

    for (int i = 2; i < N; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

    printf("This is your array:\n");
    for (int i = 0; i < N; i++)
        printf("%d\n", fibonacci[i]);

    return 0;
}