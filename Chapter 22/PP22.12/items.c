#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

int main(int argc, char *argv[])
{
    FILE *input;
    char line[255];
    int item, year, month, day;
    float price;

    if (argc != 2)
    {
        char *file_name = strrchr(argv[0], '\\');
        file_name++;
        fprintf(stderr, "Usage: %s filename\n", file_name);
        exit(EXIT_FAILURE);
    }

    if ((input = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");

    while (read_line(line, 255, input) != 0) {
        sscanf(line, "%d,%f,%d/%d/%d", &item, &price, &month, &day, &year);
        printf("%d\t\t$%8.2f\t%.2d/%.2d/%.4d\n", item, price, month, day, year);
    }

    return 0;
}