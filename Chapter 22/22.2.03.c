#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;

    if (fp = fopen("example.dat", "r")) {
        // read characters until end-of-file
    } else {
        fprintf(stderr, "Error, cannot open file: %s\n", "example.dat");
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    return 0;
}