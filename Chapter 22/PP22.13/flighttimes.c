#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define MAX_TIMES 100
#define MAX_LENGTH 255

int compare(const void *a, const void *b);

int main(int argc, char *argv[])
{
    FILE *input;

    char line[MAX_LENGTH];
    int i, hours, minutes, flights, minutes_since_midnight, 
            dep_hour, dep_min, arr_hour, arr_min,
            departures[MAX_TIMES], arrivals[MAX_TIMES];

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

    i = 0;

    while ((read_line(line, MAX_LENGTH, input)) != 0) {
        sscanf(line, "%d:%d %d:%d", &dep_hour, &dep_min, &arr_hour, &arr_min);
        departures[i] = dep_hour * 60 + dep_min;
        arrivals[i] = arr_hour * 60 + arr_min;
        i++;
        if (i == MAX_TIMES) {
            fprintf(stderr, "Error: flight.dat too long, using first %d"
                    " listings\n", i);
            break;
        }
    }
    flights = i;

    qsort(departures, flights, sizeof(int), compare);
    qsort(arrivals, flights, sizeof(int), compare);

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    minutes_since_midnight = hours * 60 + minutes;

    for (i = 0; i < flights; i++) {
        if ((abs(minutes_since_midnight - departures[i])) <=
            (abs(minutes_since_midnight - departures[i + 1])))
                break;
    }

    printf("Closest departure time is: %.2d:%.2d, arriving at %.2d:%.2d\n",
            departures[i] / 60, departures[i] % 60,
            arrivals[i] / 60, arrivals[i] % 60);

    fclose(input);
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}