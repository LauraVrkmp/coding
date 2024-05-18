#include <stdio.h>
#include <stdarg.h>

char *max_pair(int num_pairs, ...);

int main(void)
{
    char *max = max_pair(5, 180, "Seinfeld", 180, "I Love Lucy", 
                            39, "The Honeymooners", 210, "All in the Family",
                            86, "The Sopranos");
    printf("%s\n", max);
    return 0;
}

char *max_pair(int num_pairs, ...)
{
    va_list ap;
    int i, current_number, largest_number;
    char *current_show, *largest_show;

    va_start(ap, num_pairs);
    largest_number = va_arg(ap, int);
    largest_show = va_arg(ap, char *);

    for (i = 1; i < num_pairs; i++) {
        current_number = va_arg(ap, int);
        current_show = va_arg(ap, char *);
        if (current_number > largest_number)
            largest_show = current_show;
    }

    va_end(ap);
    return largest_show;
}