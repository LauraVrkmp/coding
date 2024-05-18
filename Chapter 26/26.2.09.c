#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rand_double(void);

int main(void)
{
    srand(time(NULL));
    printf("%f\n", rand_double());

    return 0;
}

double rand_double(void)
{
    return (double) rand() / (RAND_MAX + 1);
}