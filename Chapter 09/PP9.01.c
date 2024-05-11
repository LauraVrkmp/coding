#include <stdio.h>

#define N 100

void selection_sort(int a[], int n);

int main(void)
{
    int a[N] = {0};
    int i, n, c;

    printf("Enter a series of integers: ");

    for (i = 0, n = 0; i < N; i++) {
        scanf("%d", &a[i]);
        n++;
        if ((c = getchar()) == '\n')
            break;
    }

    selection_sort(a, n);

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int a[], int n)
{
    if (n == 0) return;
    
    int i, temp, max = 0;
    
    for (i = 0; i < n; i++) {
        if (a[i] > a[max]) {
            max = i;
        }
    }

    temp = a[n - 1];
    a[n - 1] = a[max];
    a[max] = temp;

    selection_sort(a, n - 1);
}