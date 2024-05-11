int find_largest(int a[], int n)
{
    int *p = a;
    int max = *p++;

    while (p++ < a + n) {
        if (*p > max)
            max = *p;
    }

    return max;
}