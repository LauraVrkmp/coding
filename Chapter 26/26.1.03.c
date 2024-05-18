#include <stdio.h>
#include <stdarg.h>

void my_printf(const char *s, ...);

int main(void)
{
    my_printf("Hello %d %s hello %d %%", -43, "try", 132);
    return 0;
}

void my_printf(const char *s, ...)
{
    va_list ap;
    int digit, i, power, temp;
    char *ch;

    va_start(ap, s);

    while (*s != '\0') {
        if (*s != '%') {
            putchar(*s);
            s++;
        } else if (*s == '%' && *(s + 1) != 'd' && *(s + 1) != 's')
            s += 2;
        else if (*(s + 1) == 'd') {
            i = va_arg(ap, int);
            if (i < 0) {
                i = -i;
                putchar('-');
            }

            temp = i;
            power = 1;
            while (temp > 9) {
                temp /= 10;
                power *= 10;
            }

            do {
                digit = i / power;
                putchar(digit + '0');
                i -= digit * power;
                power /= 10;
            } while (i > 0);

            s += 2;
        }
        else {
            ch = va_arg(ap, char *);
            while (*ch) {
                putchar(*ch);
                ch++;
            }
            s += 2;
        }
    }

    va_end(ap);
}