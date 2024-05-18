// wrong output :/ should be 0, -1, -1, -1

#include <stdio.h>
#include <stdlib.h>

int mbcheck(const char *s);

int main(void)
{
    int n;
    const char *s;
    char a[] = "\x05\x87\x80\x36\xed\xaa";
	char b[] = "\x20\xe4\x50\x88\x3f";
	char c[] = "\xde\xad\xbe\xef";
	char d[] = "\x8a\x60\x92\x74\x41";

    s = a;
    n = mbcheck(s);
    printf("%d\n", n);

    s = b;
    n = mbcheck(s);
    printf("%d\n", n);

    s = c;
    n = mbcheck(s);
    printf("%d\n", n);

    s = d;
    n = mbcheck(s);
    printf("%d\n", n);

    return 0;
}

int mbcheck(const char *s)
{
    int n;

    for (mblen(NULL, 0); ; s += n)
        if ((n = mblen(s, MB_CUR_MAX)) <= 0)
            return n;
}