#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool test_extension(const char *file_name, const char *extension);

int main(void)
{
    char *file_name = "memo.txt";
    char *extension = "TXT";

    printf("%d\n", test_extension(file_name, extension));
}

bool test_extension(const char *file_name, const char *extension)
{
    while (*file_name++ != '.');
    while (*file_name && *extension)
        if (toupper(*file_name++) != toupper(*extension++))
            return false;
    return true;
}