int count_ones_with_loop(unsigned char ch)
{
    int count = 0;
    while (ch) {
        if (ch & 0x01 == 1)
            count++;
        ch >>= 1;
    }
    return count;
}

int count_ones_without_loop(unsigned char ch)
{
    if (ch == 0)
        return 0;
    return count_ones(ch & ch - 1) + 1;
}