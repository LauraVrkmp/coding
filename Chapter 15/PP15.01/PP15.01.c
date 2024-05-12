#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;
bool space_additional = false;

void write_line(void)
{
    int extra_spaces, spaces_to_insert, i, j;
    space_additional = !space_additional;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (i = 0; i < line_len; i++) {
        if (line[i] != ' ')
            putchar(line[i]);
        else {
            spaces_to_insert = extra_spaces / (num_words - 1);
            if (space_additional && extra_spaces > 0) {
                spaces_to_insert++;
                space_additional = !space_additional;
            }
            for (j = 1; j <= spaces_to_insert + 1; j++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n');
}