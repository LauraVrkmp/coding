Complex make_complex(double real, double imaginary);

typedef struct {
    double real, imaginary;
} Complex;

int main(void)
{
    Complex c1, c2, c3;
}

Complex make_complex(double x, double y)
{
    return (Complex) {x, y};
}

Complex add_complex(Complex x, Complex y)
{
    return (Complex) {x.real + y.real, x.imaginary + y.imaginary};
}