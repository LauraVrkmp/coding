#include <stdio.h>

int fseek(FILE *stream, long int offset, int whence);

// fseek(fp, 64L * n, SEEK_SET);
// fseek(fp, -64L, SEEK_END);
// fseek(fp, 64L, SEEK_CUR);
// fseek(fp, 64L * -2, SEEK_CUR);
