#include <stdio.h>
#include <string.h>

void get_extension(const char *file_name, char *extension);

int main(void)
{
    char file_name[] = "memo.txt";
    char extension[5];

    get_extension(file_name, extension);

    printf("%s\n", extension);

    return 0;
}

void get_extension(const char *file_name, char *extension)
{
    while (*file_name) {
        if (*file_name++ == '.') {
            strcpy(extension, file_name);
            return;
        }
    }

    strcpy(extension, "");
}