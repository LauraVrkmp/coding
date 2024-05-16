#include <stdio.h>
#include <stdlib.h>

int line_length(const char *filename, int n);

int main(void)
{
    printf("%d\n", line_length("test.txt", 3));

    return 0;
}

int line_length(const char *filename, int n)
{
    int current_line = 1;
    int length = 0;
    int c; 

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("%s can't be opened\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(file)) != EOF) {
        if (current_line == n) {
            while (c != '\n' && c != EOF) {
                length++;
                c = fgetc(file);
            }
            break;
        } else if (c == '\n') {
            current_line++;
        }
    }
    
    fclose(file);
    return (current_line == n) ? length : 0;

}