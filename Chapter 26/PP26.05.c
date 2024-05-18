#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm first, second;
    time_t first_conv, second_conv;
    int n, difference;

    first.tm_sec = first.tm_min = first.tm_hour = 0;
    second.tm_sec = second.tm_min = second.tm_hour = 0;
    first.tm_isdst = second.tm_isdst = -1;

    printf("Enter first month (1-12): ");
    scanf("%d", &first.tm_mon);
    first.tm_mon--;

    printf("Enter first day (1-31): ");
    scanf("%d", &first.tm_mday);

    printf("Enter first year: ");
    scanf("%d", &first.tm_year);
    first.tm_year -= 1900;

    printf("Enter second month (1-12): ");
    scanf("%d", &second.tm_mon);
    second.tm_mon--;

    printf("Enter second day (1-31): ");
    scanf("%d", &second.tm_mday);

    printf("Enter second year: ");
    scanf("%d", &second.tm_year);
    second.tm_year -= 1900;

    first_conv = mktime(&first);
    second_conv = mktime(&second);

    difference = difftime(second_conv, first_conv);
    difference /= (60 * 60 * 24);

    printf("The difference is %d days\n", difference);

    return 0;
}