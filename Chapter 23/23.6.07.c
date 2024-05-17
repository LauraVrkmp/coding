// not possible

#include <stdio.h>
#include <string.h>

void capitalize_all_gs(char *s);

int main(void)
{
    char str[] = "We had a great day together.";
    capitalize_all_gs(str);
    printf("%s\n", str);
    return 0;
}

void capitalize_all_gs(char *s)
{
    s = strrchr(s, 'g');
    while (s != NULL) {
        *s = 'G';
        s = strrchr(s++, 'g');
    }
}