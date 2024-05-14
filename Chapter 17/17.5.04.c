#include <stdlib.h>

struct point {int x, y;};
struct rectangle {struct point upper_left, lower_right;};
struct rectangle *p;

int main(void)
{
    p = (struct rectangle *) malloc(sizeof(struct rectangle));
    if (p == NULL) {
        printf("Error: retured a null pointer.");
        exit(EXIT_FAILURE);
    }
    p->upper_left.x = 10;
    p->upper_left.y = 25;
    p->lower_right.x = 20;
    p->lower_right.y = 15;
}