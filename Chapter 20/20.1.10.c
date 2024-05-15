#define INT_BITS (sizeof(int) * 8 - 1)

unsigned int reverse_bits(unsigned int n)
{
    int i;
    for (i - 0; i < INT_BITS / 2; i++)
    {
        if (((n >> INT_BITS - i) & 1) != ((n >> i) &  1))
            n ^= (1 << INT_BITS - i) | (1 << i);
    }
    return n;
}