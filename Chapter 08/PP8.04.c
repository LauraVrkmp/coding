#include <stdio.h>
#define MAX (int) (sizeof(a) / sizeof(a[0]))

int main(void)
{
    int a[10], i;
    
    printf("Enter %d numbers: ", MAX);
    for (i = 0; i < MAX; i++)
        scanf("%d", &a[i]);
    
    printf("In reverse order:");
    for (i = MAX - 1; i >= 0; i--)
        printf(" %d", a[i]);
    
    printf("\n");

    return 0;
}