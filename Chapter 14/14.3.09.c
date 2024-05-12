#define CHECK(x, y, n) ((0 < (x) && 0 <= (y) && \
                        (x) <= (n) - 1 && (y) <= (n) - 1) \
                         ? 1 : 0)

#define MEDIAN(x, y, z) (((x) < (y) && (x) > (z) ? (x)) : \
                         ((z) < (y) && (z) > (x)) ? (z) : (y))

#define POLYNOMIAL(x) (((((3 * (x) + 2) * (x) - 5) * (x) - 1) * \
                        (x) + 7) * (x) - 6)