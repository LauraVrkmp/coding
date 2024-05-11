double inner_product(const double *a, const double *b, int n)
{
    double sum = 0;
    int i = 0;

    while (i++ < n) {
        sum += *a++ * *b++;
    }

    return sum;
}