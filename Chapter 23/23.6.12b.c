#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int stricmp(const char *s1, const char *s2);

int main(void)
{
    char s1[] = "Wereld", s2[] = "Wereld";
    printf("%d\n", stricmp(s1, s2));
    return 0;
}

int stricmp(const char *s1, const char *s2)
{
    int i, len_s1 = strlen(s1) + 1, len_s2 = strlen(s2) + 1;
    char difference;

    double min = fmin(len_s1, len_s2);
    for (i = 0; i < min; i++) {
        difference = toupper(s1[i]) - toupper(s2[i]);
        if (difference > 0)
            return 1;
        else if (difference < 0)
            return -1;
    }

    return 0;
}