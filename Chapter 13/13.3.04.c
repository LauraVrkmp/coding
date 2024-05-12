int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()));

    while (i < n && (ch = getchar()) != '\n' && !isspace(ch))
        str[i++] = ch;

    if (ch = '\n' && i < n - 1)
        str[i++] = '\n';
    
    str[i] = '\0';
    return i;
}