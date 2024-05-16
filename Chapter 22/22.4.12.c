#include <stdio.h>

int count_periods(const char *filename)
{
    FILE *fp;
    int n = 0;
    char c;

    if ((fp = fopen(filename, "r")) != NULL) {
        while ((c = fgetc(fp)) != EOF)
            if (c == '.')
                n++;
        fclose(fp);
    }

    return n;
}