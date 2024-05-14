#define RECTANGLE 0
#define CIRCLE 1
#define PI 3.121593

struct point {int x, y;};

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

int area(struct shape s)
{
    if (s.shape_kind == RECTANGLE) {
        return s.u.rectangle.height * s.u.rectangle.width;
    } else {
        return s.u.circle.radius * s.u.circle.radius * PI;
    }
}

struct shape move(struct shape s, int x, int y)
{
    s.center.x += x;
    s.center.y += y;

    return s;
}

struct shape scale(struct shape s, double c)
{
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
    }
    else {
        s.u.circle.radius *= c;
    }

    return s;
}