#ifndef LINE_H
#define LINE_H

#include <stdio.h>

void clear_line(void);

void add_word(const char *word);

int space_remaining(void);

void write_line(FILE *);

void flush_line(FILE *);

#endif