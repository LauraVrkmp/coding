int strcmp(char *s, char *t)
{
    while (*s == *t) {
        if (*t == '\0') {
            return 0;
        }
        s++;
        t++;
    }

    return *s - *t;
}