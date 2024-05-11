#define LEN 8

int sum_two_dimensional_array(const int a[][LEN], int n)
{
    const int *p = *a;
    int sum = 0;

    while (p < *a + n * LEN)
        sum += *p++;
    
    return sum;
}