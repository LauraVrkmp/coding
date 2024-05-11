#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hours, minutes, minutes_since_midnight, d1, d2, d3, d4, d5, d6, d7, d8;
    char c;

    d1 = 8 * 60;
    d2 = 9 * 60 + 43;
    d3 = 11 * 60 + 19;
    d4 = 12 * 60 + 47;
    d5 = (12 + 2) * 60;
    d6 = (12 + 3) * 60 + 45;
    d7 = (12 + 7) * 60;
    d8 = (12 + 9) * 60 + 45;

    printf("Enter a 12-hour time with AM/PM: ");
    scanf("%d:%d %c", &hours, &minutes, &c);

    minutes_since_midnight = ((toupper(c) == 'P' ? 12 : 0) + hours) * 60 + minutes;

    printf("Closest departure time is ");

    if (minutes_since_midnight <= d1 + (d2 - d1) / 2)
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    else if (minutes_since_midnight < d2 + (d3 - d2) / 2)
        printf("9:43 a.m., arriving at 11:52 a.m.\n");
    else if (minutes_since_midnight < d3 + (d4 - d3) / 2)
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
    else if (minutes_since_midnight < d4 + (d5 - d4) / 2)
        printf("12:47 p.m., arriving at 3:00 p.m.\n");
    else if (minutes_since_midnight < d5 + (d6 - d5) / 2)
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
    else if (minutes_since_midnight < d6 + (d7 - d6) / 2)
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
    else if (minutes_since_midnight < d7 + (d8 - d7) / 2)
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("9:45 p.m., arriving at 11:58 p.m.\n");

    return 0;
}