#include <stdio.h>

struct date {
    int month, day, year;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void)
{
    struct date d = {3, 29, 1994};
    struct date e = {3, 25, 1996};

    printf("%d\n", day_of_year(d));
    printf("%d\n", compare_dates(d, e));

    return 0;
}

int day_of_year(struct date d)
{
    int i, days = 0;
    
    for (i = 1; i < d.month; i++) {
        switch (d.month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                days += 31;
                break;
            case 4: case 6: case 9: case 11:
                days += 30;
                break;
            case 2:
                if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
                    days += 29;
                else
                    days += 28;
                break;
        }
    }

    days += d.day;
    return days;   
}

int compare_dates(struct date d1, struct date d2)
{
    int d1_days = day_of_year(d1);
    int d2_days = day_of_year(d2);

    if (d1.year < d2.year)
        return -1;
    else if (d1.year == d2.year) {
        if (d1_days < d2_days)
            return -1;
        else if (d1_days == d2_days)
            return 0;
    } else
        return 1;
}