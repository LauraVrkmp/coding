// void (*x(int, void (*y)(int)))(int);

typedef void outer_fx_t(int);
typedef void *arg_fx_t(int);
typedef outer_fx_t *inner_fx_t(int, arg_fx_t);
outer_fx_t x;
