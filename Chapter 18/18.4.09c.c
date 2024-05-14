// float *(*x(void))(int);

typedef float *fx_t(int);
typedef fx_t *inner_fx_t(void);
inner_fx_t x;