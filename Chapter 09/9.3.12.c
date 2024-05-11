double inner_product(double a[], double b[], int n)
{
    int i;
    double result = 0;

    for (i = 0; i < n; i++) {
        result += a[i] * b[i];
    }

    return result;
}