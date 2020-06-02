#include <stdio.h>

struct fraction {
    int numerator, denominator;
    };

int GCD(int a, int b) {
	if(b) while((a %= b) && (b %= a));
	return a + b;
}

struct fraction reduce(struct fraction f)
{
    int gcd = GCD(f.numerator, f.denominator);
    f.numerator /= gcd;
    f.denominator /= gcd;
    return f;
}

#define FracFun(tag, a, b) \
struct fraction tag(struct fraction f1, struct fraction f2)\
{\
    struct fraction ans = {\
        a, b\
    };\
    return reduce(ans);\
}

FracFun(add, f1.numerator * f2.denominator + f2.numerator * f1.denominator,
             f1.denominator * f2.denominator)

FracFun(subtract, f1.numerator * f2.denominator - f2.numerator * f1.denominator,
                  f1.denominator * f2.denominator)

FracFun(multpy, f1.numerator * f2.numerator,
                f1.denominator * f2.denominator)

FracFun(divide, f1.numerator * f2.denominator,
                f1.denominator * f2.numerator)
int main()
{
    struct fraction f = {9, 12}, f2 = {1, 4};;
    printf("%d %d\n", divide(f, f2).numerator, divide(f, f2).denominator);
    return 0;
}
