#include <string.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
    FILE *input, *output;
    char word[MAX_WORD_LEN+2];
    int word_len;

    if ((input = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((output = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    clear_line();
    for (;;) {
        read_word(input, word, MAX_WORD_LEN + 1);
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line(output);
            break;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) {
            write_line(output);
            clear_line();
        }
        add_word(word);
    }

    fclose(input);
    fclose(output);

    return 0;
}