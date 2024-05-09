int largest(int a[], int n)
{
    int large = 0, i;

    for (i = 0; i < n; i++) {
        if (a[i] > large)
            large = a[i];
    }

    return large;
}

float average(int a[], int n)
{
    int sum = 0, i;

    for (i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum / n;
}

int positive(int a[], int n)
{
    int count = 0, i;

    for (i = 0; i < n; i++) {
        if (a[i] > 0)
            count++;
    }

    return count;
}