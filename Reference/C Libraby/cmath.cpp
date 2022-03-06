/*
<cmath> (math.h)

C numerics library

Header <cmath> declares a set of functions to compute common mathematical operations and transformations:
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    Trigonometric functions:
    cos         Compute cosine:      double cos (double x);   float cos (float x);   long double cos (long double x);   double cos (T x);

    sin         Compute sine

    tan         Compute tangent

    acos        Compute arc cosine

    asin        Compute arc sine

    atan        Compute arc tangent

    atan2       ompute arc tangent with two parameters
    */
    double param, result;
    param = 60.0;
    result = cos(param * 3.14159265 / 180.0);
    printf("The cosine of %f degrees is %f.\n", param, result);
    // The cosine of 60.000000 degrees is 0.500000.

    /*
    Hyperbolic functions:
    cosh        Compute hyperbolic cosine:      double cosh (double x);    float cosh (float x);    long double cosh (long double x);    double cosh (T x);

    sinh        Compute hyperbolic sine

    tanh        Compute hyperbolic tangent

    acosh       Compute area hyperbolic cosine

    asinh       Compute area hyperbolic sine

    atanh       Compute area hyperbolic tangent
    */
    double param, result;
    param = log(2.0);
    result = cosh(param);
    printf("The hyperbolic cosine of %f is %f.\n", param, result);
    // The hyperbolic cosine of 0.693147 is 1.250000.

    /*
    Exponential and logarithmic functions:
    exp         Compute exponential function:   double exp (double x);   float exp (float x);   long double exp (long double x);    double exp (T x);

    frexp       Get significand and exponent:   double frexp (double x, int* exp);   float frexp (float x, int* exp);   long double frexp (long double x, int* exp);    double frexp (T x, int* exp);

    ldexp       Generate value from significand and exponent:   double ldexp (double x, int exp);   float ldexp (float x, int exp);    long double ldexp (long double x, int exp);   double ldexp (T x, int exp);

    log         Compute natural logarithm:   double log (double x);   float log (float x);    long double log (long double x);    double log (T x);

    log10       Compute common logarithm

    modf        Break into fractional and integral parts:   double modf (double x, double* intpart);   float modf (float x, float* intpart);    long double modf (long double x, long double* intpart);   double modf (T x, double* intpart);

    exp2        Compute binary exponential function

    expm1       Compute exponential minus one

    ilogb       Integer binary logarithm

    log1p       Compute logarithm plus one

    log2        Compute binary logarithm

    logb        Compute floating-point base logarithm

    scalbn      Scale significand using floating-point base exponent:   double scalbn (double x, int n);   float scalbn (float x, int n);    long double scalbn (long double x, int n);    double scalbn (T x, int n);

    scalbln     Scale significand using floating-point base exponent (long)
    */
    double param, fractpart, intpart;

    param = 3.14159265;
    fractpart = modf(param, &intpart);
    printf("%f = %f + %f \n", param, intpart, fractpart);
    // 3.141593 = 3.000000 + 0.141593
    return 0;
}