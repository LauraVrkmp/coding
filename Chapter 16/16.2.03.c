struct complex make_complex(double real, double imaginary);

struct complex {
    double real, imaginary;
};

int main(void)
{
    struct complex c1, c2, c3;
}

struct complex make_complex(double x, double y)
{
    struct complex structure;
    structure.real = x;
    structure.imaginary = y;
    return structure;
}

struct complex add_complex(struct complex x, struct complex y)
{
    struct complex structure;
    structure.real = x.real + y.real;
    structure.imaginary = x.imaginary + y.imaginary;
    return structure;
}