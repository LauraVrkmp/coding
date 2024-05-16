#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INTEGERS 10000

int compare(const void *a, const void *b);

int main(int argc, char *argv[])
{
    FILE *input;
    long int array[MAX_INTEGERS], num, median;
    int count = 0;

    if (argc != 2) {
        char *file_name = strrchr(argv[0], '\\');
        file_name++;
        fprintf(stderr, "Usage: %s file_in\n", file_name);
        exit(EXIT_FAILURE);
    }

    if ((input = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fscanf(input, "%d", &num) == 1 && count < MAX_INTEGERS) {
        array[count++] = num;
    }

    fclose(input);

    qsort(array, count, sizeof(long int), compare);

    printf("Largest number: %d\n", array[count - 1]);
    printf("Smallest number: %d\n", array[0]);

    if (count % 2)
        median = (array[count / 2] + array[count / 2 - 1]) / 2;
    else median = array[count / 2];

    printf("Median: %d\n", median);
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}