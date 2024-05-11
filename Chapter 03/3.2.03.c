#include <stdio.h>

int main(void)
{
    int a1, a2;
    int b1, b2, b3, b4, b5, b6;
    float c1, c2;
    float d1, d2, d3, d4;

    printf("Input two times one number for part a): \n");
    scanf("%d", &a1);
    scanf(" %d", &a2);
    printf("a) %d, %d\n", a1, a2);

    printf("Input two times three numbers for part b): \n");
    scanf("%d-%d-%d", &b1, &b2, &b3);
    scanf("%d -%d -%d", &b4, &b5, &b6);
    printf("b) %d, %d, %d, %d, %d, %d\n", b1, b2, b3, b4, b5, b6);

    printf("Input two times one number for part c): \n");
    scanf("%f", &c1);
    scanf("%f ", &c2);
    printf("c) %f, %f\n", c1, c2);

    printf("Input two times two numbers for part d): \n");
    scanf("%f,%f", &d1, &d2);
    scanf("%f, %f", &d3, &d4);
    printf("d) %f, %f, %f, %f\n", d1, d2, d3, d4);

    return 0;
}