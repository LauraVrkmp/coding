#include <stdbool.h>

bool search(const int a[], int n, int key);

int main(void)
{
    int temperatures[7][24];

    bool has32 = search(temperatures, 7 * 24, 32);

    return 0;
}

bool search(const int a[], int n, int key)
{
    const int *p;

    for (p = a; p < a + n; p++) {
        if (*p == key)
            return true;
    }

    return false;
}