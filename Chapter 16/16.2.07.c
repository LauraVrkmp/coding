struct fraction {
    int numerator;
    int denominator;
};

struct fraction reduce(struct fraction f)
{
    int m = f.numerator;
    int n = f.denominator;
    int remainder;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    f.numerator = f.numerator / m;
    f.denominator = f.denominator / m;

    return f;
}

struct fraction add(struct fraction f1, struct fraction f2)
{
    struct fraction f3 = {f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                          f1.denominator * f2.denominator};
    
    f3 = reduce(f3);

    return f3;
}

struct fraction substract(struct fraction f1, struct fraction f2)
{
    struct fraction f3 = {f1.numerator * f2.denominator - f2.numerator * f1.denominator,
                          f1.denominator * f2.denominator};
    
    f3 = reduce(f3);

    return f3;
}

struct fraction multiply(struct fraction f1, struct fraction f2)
{
    struct fraction f3 = {f1.numerator * f2.numerator,
                          f1.denominator * f2.denominator};
    
    f3 = reduce(f3);

    return f3;
}

struct fraction divide(struct fraction f1, struct fraction f2)
{
    struct fraction f3 = {f1.numerator * f2.denominator,
                          f1.denominator * f2.numerator};
    
    f3 = reduce(f3);

    return f3;
}