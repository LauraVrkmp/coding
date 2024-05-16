#include <stdio.h>

int main(void)
{
    float f = 83.7361, g = 29748.6607, h = 1054932234.0, i = 0.0000235218;

    printf("Double f: %#012.5g\n", f);
    printf("Double g: %#012.5g\n", g);
    printf("Double h: %#012.5g\n", h);
    printf("Double i: %#012.5g\n", i);

    return 0;
}