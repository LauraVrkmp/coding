#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    FILE *input, *output;
    
    char file_name[100], new_file_name[100];
    int shift, c;

    printf("Enter name of file to be encrypted: ");
    scanf("%s", file_name);
    printf("Enter shift amount (1-26): ");
    scanf("%d", &shift);

    if ((input = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    
    snprintf(new_file_name, sizeof(new_file_name), "%s.enc", file_name);

    if ((output = fopen(new_file_name, "w")) == NULL) {
        fprintf(stderr, "Can't open %s\n", new_file_name);
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(input)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A') + shift) % 26 + 'A';
            fputc(c, output);
        } else if (c >= 'a' && c <= 'z') {
            c = ((c - 'a') + shift) % 26 + 'a';
            fputc(c, output);
        } else {
            fputc(c, output);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}