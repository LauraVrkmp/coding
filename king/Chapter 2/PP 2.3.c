#include <stdio.h>
#define M_PI 3.14159265358979323846

int main(void)
{
    float rad;

    printf("Enter the radius of a sphere: ");
    scanf("%f", &rad);

    float v = 4.0f / 3.0f * M_PI * rad * rad * rad;

    printf("The volume is %.3f.\n", v);
    
    return 0;
}
