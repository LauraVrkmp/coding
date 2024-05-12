#include <stdio.h>

int main(void)
{
    int tenth, oneth;

    const char *except[] = {"ten", "eleven", "twelve", "thirteen",
                            "fourteen", "fifteen", "sixteen", "seventeen",
                            "eighteen", "nineteen"};

    const char *times_ten[] = {"", "", "twenty", "thirty", "forty",
                               "fifty", "sixty", "seventy", "eighty", "ninety"};

    const char *times_one[] = {"", "-one", "-two", "-three", "-four",
                               "five", "six", "seven", "eight", "nine"};

    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &tenth, &oneth);

    printf("You entered the number ");

    if (tenth == 1)
        printf("%s", except[oneth]);
    else {
        printf("%s", times_ten[tenth]);

        if (oneth != 0)
            printf("%s", times_one[oneth]);
    }
    
    printf(".\n");

    return 0;
}