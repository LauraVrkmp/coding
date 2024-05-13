#include <stdio.h>

struct date {
    int month, day, year;
};

int compare_dates(struct date d1, struct date d2);

int main(void)
{
    struct date date1, date2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &date1.month, &date1.day, &date1.year);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &date2.month, &date2.day, &date2.year);

    int compared = compare_dates(date1, date2);

    if (compared > 0)
        printf("%d/%d/%d comes before %d/%d/%d\n",
               date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);
    else if (compared < 0)
        printf("%d/%d/%d comes before %d/%d/%d\n",
               date2.month, date2.day, date2.year, date1.month, date1.day, date1.year);
    else
        printf("%d/%d/%d and %d/%d/%d are equal\n", 
               date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);
    
    return 0;
}

int compare_dates(struct date d1, struct date d2) {
    if (d1.year < d2.year)
        return -1;
    else if (d1.year > d2.year)
        return 1;
    else {
        if (d1.month < d2.month)
            return -1;
        else if (d1.month > d2.month)
            return 1;
        else {
            if (d1.day < d2.day)
                return -1;
            else if (d1.day > d2.day)
                return 1;
            else
                return 0;
        }
    }
}