/*
<cmath> (math.h)

C numerics library

Header <cmath> declares a set of functions to compute common mathematical operations and transformations:
*/

#include <stdio.h>
#include <math.h>
#include <iostream>

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

    /*
    Power functions:
    pow         Raise to power:     double pow (double base, double exponent);    float pow (float base, float exponent);
                                    long double pow (long double base, long double exponent);     double pow (Type1 base, Type2 exponent);

    sqrt        Compute square root:    double sqrt (double x);    float sqrt (float x);    long double sqrt (long double x);     double sqrt (T x);

    cbrt        Compute cubic root

    hypot       Compute hypotenuse:     double hypot (double x, double y);     float hypot (float x, float y);
                                        long double hypot (long double x, long double y);     double hypot (Type1 x, Type2 y);
    */
    double leg_x, leg_y, result;
    leg_x = 3;
    leg_y = 4;
    result = hypot(leg_x, leg_y);
    printf("%f, %f and %f form a right-angled triangle.\n", leg_x, leg_y, result);
    // 3.000000, 4.000000 and 5.000000 form a right-angled triangle.

    /*
    Rounding functions:
    ceil       Round up value:      double ceil (double x);    float ceil (float x)    ;long double ceil (long double x);     double ceil (T x);

    floor      Round down value

    trunc      Truncate value

    round      Round to nearest
    */
    const char *format = "%.1f \t%.1f \t%.1f \t%.1f \t%.1f\n";
    printf("value\tround\tfloor\tceil\ttrunc\n");
    printf("-----\t-----\t-----\t----\t-----\n");
    printf(format, 2.3, round(2.3), floor(2.3), ceil(2.3), trunc(2.3));
    printf(format, 3.8, round(3.8), floor(3.8), ceil(3.8), trunc(3.8));
    printf(format, 5.5, round(5.5), floor(5.5), ceil(5.5), trunc(5.5));
    printf(format, -2.3, round(-2.3), floor(-2.3), ceil(-2.3), trunc(-2.3));
    printf(format, -3.8, round(-3.8), floor(-3.8), ceil(-3.8), trunc(-3.8));
    printf(format, -5.5, round(-5.5), floor(-5.5), ceil(-5.5), trunc(-5.5));
    // value   round   floor   ceil    trunc
    // -----   -----   -----   ----    -----
    // 2.3     2.0     2.0     3.0     2.0
    // 3.8     4.0     3.0     4.0     3.0
    // 5.5     6.0     5.0     6.0     5.0
    // -2.3    -2.0    -3.0    -2.0    -2.0
    // -3.8    -4.0    -4.0    -3.0    -3.0
    // -5.5    -6.0    -6.0    -5.0    -5.0

    /*
    Other function:
    abs     Compute absolute value:      double abs (double x);    float abs (float x);     long double abs (long double x);     double abs (T x);
    */
    std::cout << "abs (3.1416) = " << std::abs(3.1416) << '\n';
    std::cout << "abs (-10.6)  = " << std::abs(-10.6) << '\n';
    // abs (3.1416) = 3.1416
    // abs (-10.6) = 10.6
    return 0;
}