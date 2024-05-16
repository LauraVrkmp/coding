#include <stdio.h>

int main(void)
{
    char str[] = "Some text #123,456 this shouldn't be printed";
    char sales_rank[20];

    if (sscanf(str, "%*[^#]#%19[^ ]", sales_rank) == 1) {
        printf("Sales rank: %s\n", sales_rank);
    } else {
        printf("No sales rank found.\n");
    }

    return 0;
}