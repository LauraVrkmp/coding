#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);