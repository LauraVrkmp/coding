#include <stdio.h>
#define DAYS 30
#define HOURS 24

int main(void)
{
    float average;
    float temperature_reading[DAYS][HOURS];

    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < HOURS; j++) {
            average += temperature_reading[i][j];
        }
    }

    average /= DAYS * HOURS;

    return 0;
}