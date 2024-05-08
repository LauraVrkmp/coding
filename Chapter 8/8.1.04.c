#include <stdio.h>
#include <stdbool.h>

#define length ((int) (sizeof(weekend) / sizeof(weekend[0])))

int main(void)
{
    bool weekend[7] = {[0] = true, [6] = true};

    printf("This is your array:\n");
    for (int i = 0; i < length; i++)
        printf("%d", weekend[i]);

    return 0;
}