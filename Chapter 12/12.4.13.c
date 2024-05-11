#include <stdio.h>

#define N 10

int main(void)
{
    double ident[N][N], *p;
    int count = N;

    for (p = &ident[0][01]; p <= &ident[N - 1][N - 1]; p++) {
        if (count == N) {
            *p = 1.0;
            count = 0;
        } else {
            *p = 0.0;
            count++;
        }
    }

    return 0;
}