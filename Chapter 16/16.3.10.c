#include <stdbool.h>

struct point {int x, y;};
struct rectangle {struct point upper_left, lower_right;};

int area(struct rectangle r)
{
    return (r.lower_right.x - r.upper_left.x) * 
           (r.upper_left.y - r.lower_right.y);
}

struct point center(struct rectangle r)
{
    int x = (int) ((r.lower_right.x - r.upper_left.x) / 2);
    int y = (int) ((r.upper_left.y - r.lower_right.y) / 2);

    return (struct point) {x, y};
}

struct rectangle move(struct rectangle r, int x, int y)
{
    r.lower_right.x += x;
    r.upper_left.x += x;
    r.lower_right.y += y;
    r.upper_left.y += y;

    return r;
}

bool in_r(struct rectangle r, struct point p)
{
    if (r.upper_left.x < p.x && r.lower_right.x > p.x) {
        if (r.lower_right.y < p.y && r.upper_left.y > p.y)
            return true;
    }

    return false;
}