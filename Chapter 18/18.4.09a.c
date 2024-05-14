// char (*x[10])(int);

typedef char fx_t(int);
typedef fx_t *fx_prt_t;
typedef fx_prt_t fx_prt_t_array_t[10];
fx_prt_t_array_t x;