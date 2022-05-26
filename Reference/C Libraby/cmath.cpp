/*
<cmath>(math.h)

C numerics library

Header <cmath> declares a set of functions to compute common mathematical operations and transformations:
*/

#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

#define PI 3.14159265

int main()
{

    //----------------------------------------Trigonometric functions----------------------------------------//
    // cos         Compute cosine:      double cos(double x);   float cos(float x);   long double cos(long double x);   double cos(T x);
    double param, result;
    param = 60.0;
    result = cos(param * PI / 180.0);
    printf("The cosine of %f degrees is %f.\n", param, result);
    // The cosine of 60.000000 degrees is 0.500000.

    // sin         Compute sine:    double sin(double x);
    double param, result;
    param = 30.0;
    result = sin(param * PI / 180);
    printf("The sine of %f degrees is %f.\n", param, result);
    // The sine of 30.000000 degrees is 0.500000.

    // tan         Compute tangent:     double tan(double x);
    double param, result;
    param = 45.0;
    result = tan(param * PI / 180.0);
    printf("The tangent of %f degrees is %f.\n", param, result);
    // The tangent of 45.000000 degrees is 1.000000.

    // acos        Compute arc cosine:  double acos(double x);
    double param, result;
    param = 0.5;
    result = acos(param) * 180.0 / PI;
    printf("The arc cosine of %f is %f degrees.\n", param, result);
    // The arc cosine of 0.500000 is 60.000000 degrees

    // asin        Compute arc sine:    double asin(double x);
    double param, result;
    param = 0.5;
    result = asin(param) * 180.0 / PI;
    printf("The arc sine of %f is %f degrees\n", param, result);
    // The arc sine of 0.500000 is 30.000000 degrees.

    // atan        Compute arc tangent:     double atan(double x);
    double param, result;
    param = 1.0;
    result = atan(param) * 180 / PI;
    printf("The arc tangent of %f is %f degrees\n", param, result);
    // The arc tangent of 1.000000 is 45.000000 degrees.

    // atan2       ompute arc tangent with two parameters:     double atan2(double y, double x);
    double x, y, result;
    x = -10.0;
    y = 10.0;
    result = atan2(y, x) * 180 / PI;
    printf("The arc tangent for(x=%f, y=%f)is %f degrees\n", x, y, result);
    // The arc tangent for(x=-10.000000, y=10.000000)is 135.000000 degrees.

    //----------------------------------------Hyperbolic functions----------------------------------------//
    // cosh        Compute hyperbolic cosine:      double cosh(double x);    float cosh(float x);    long double cosh(long double x);    double cosh(T x);
    double param, result;
    param = log(2.0);
    result = cosh(param);
    printf("The hyperbolic cosine of %f is %f.\n", param, result);
    // The hyperbolic cosine of 0.693147 is 1.250000.

    // sinh        Compute hyperbolic sine:     double sinh(double x);
    double param, result;
    param = log(2.0);
    result = sinh(param);
    printf("The hyperbolic sine of %f is %f.\n", param, result);
    // The hyperbolic sine of 0.693147 is 0.750000.

    // tanh        Compute hyperbolic tangent:  double tanh(double x);
    double param, result;
    param = log(2.0);
    result = tanh(param);
    printf("The hyperbolic tangent of %f is %f.\n", param, result);
    // The hyperbolic tangent of 0.693147 is 0.600000.

    // acosh       Compute area hyperbolic cosine:   double acosh(double x);  float acoshf(float x);  long double acoshl(long double x);
    double param, result;
    param = exp(2) - sinh(2);
    result = acosh(param);
    printf("The area hyperbolic cosine of %f is %f radians.\n", param, result);
    // The area hyperbolic cosine of 3.762196 is 2.000000 radians.

    // asinh       Compute area hyperbolic sine:    double asinh(double x);   float asinhf(float x);     long double asinhl(long double x);
    double param, result;
    param = exp(2) - cosh(2);
    result = asinh(param);
    printf("The area hyperbolic sine of %f is %f.\n", param, result);
    // The area hyperbolic sine of 3.626860 is 2.000000

    // atanh       Compute area hyperbolic tangent:     double atanh(double x);   float atanhf(float x);     long double atanhl(long double x);
    double param, result;
    param = tanh(1);
    result = atanh(param);
    printf("The area hyperbolic tangent of %f is %f.\n", param, result);
    // The area hyperbolic tangent of 0.761594 is 1.000000

    //----------------------------------------Exponential and logarithmic functions----------------------------------------//
    // exp         Compute exponential function:   double exp(double x);   float exp(float x);   long double exp(long double x);    double exp(T x);
    double param, result;
    param = 5.0;
    result = exp(param);
    printf("The exponential value of %f is %f.\n", param, result);
    // The exponential value of 5.000000 is 148.413159.

    // frexp       Get significand and exponent:   double frexp(double x, int* exp);   float frexp(float x, int* exp);   long double frexp(long double x, int* exp);    double frexp(T x, int* exp);
    double param, result;
    int n;
    param = 8.0;
    result = frexp(param, &n);
    printf("%f = %f * 2^%d\n", param, result, n);
    // 8.000000 = 0.500000 * 2^4

    // ldexp       Generate value from significand and exponent:   double ldexp(double x, int exp);   float ldexp(float x, int exp);    long double ldexp(long double x, int exp);   double ldexp(T x, int exp);
    double param, result;
    int n;
    param = 0.95;
    n = 4;
    result = ldexp(param, n);
    printf("%f * 2^%d = %f\n", param, n, result);
    // 0.950000 * 2^4 = 15.200000

    // log         Compute natural logarithm:   double log(double x);   float log(float x);    long double log(long double x);    double log(T x);
    double param, result;
    param = 5.5;
    result = log(param);
    printf("log(%f)= %f\n", param, result);
    // log(5.500000)= 1.704748

    // log10       Compute common logarithm:    double log10(double x);
    double param, result;
    param = 1000.0;
    result = log10(param);
    printf("log10(%f)= %f\n", param, result);
    // log10(1000.000000)= 3.000000

    // modf        Break into fractional and integral parts:   double modf(double x, double* intpart);   float modf(float x, float* intpart);    long double modf(long double x, long double* intpart);   double modf(T x, double* intpart);
    double param, fractpart, intpart;
    param = 3.14159265;
    fractpart = modf(param, &intpart);
    printf("%f = %f + %f \n", param, intpart, fractpart);
    // 3.141593 = 3.000000 + 0.141593

    // exp2        Compute binary exponential function:     double exp2(double x);    float exp2f(float x);    long double exp2l(long double x);
    double param, result;
    param = 8.0;
    result = exp2(param);
    printf("2 ^ %f = %f.\n", param, result);
    // 2 ^ 8.000000 is 256.000000.

    // expm1       Compute exponential minus one:   double expm1(double x);   float expm1f(float x);     long double expm1l(long double x);
    double param, result;
    param = 1.0;
    result = expm1(param);
    printf("expm1(%f)= %f.\n", param, result);
    // expm1(1.000000)= 1.718282.

    // ilogb       Integer binary logarithm:    int ilogb(double x);  int ilogbf(float x);   int ilogbl(long double x);
    double param;
    int result;
    param = 10.0;
    result = ilogb(param);
    printf("ilogb(%f)= %d\n", param, result);
    // ilogb(10.000000)= 3

    // log1p       Compute logarithm plus one:  double log1p(double x);   float log1pf(float x);     long double log1pl(long double x);
    double param, result;
    param = 1.0;
    result = log1p(param);
    printf("log1p(%f)= %f.\n", param, result);
    // log1p(1.000000)= 0.693147

    // log2        Compute binary logarithm:    double log2(double x);    float log2f(float x);  long double log2l(long double x);
    double param, result;
    param = 1024.0;
    result = log2(param);
    printf("log2(%f)= %f.\n", param, result);
    // log2(1024.000000)= 10.000000

    // logb        Compute floating-point base logarithm:    double logb(double x);   float logbf(float x);  long double logbl(long double x);
    double param, result;
    param = 1024.0;
    result = logb(param);
    printf("logb(%f)= %f.\n", param, result);
    // logb(1024.000000)= 10.000000

    // scalbn      Scale significand using floating-point base exponent:   double scalbn(double x, int n);   float scalbn(float x, int n);    long double scalbn(long double x, int n);    double scalbn(T x, int n);
    double param, result;
    int n;
    param = 1.50;
    n = 4;
    result = scalbn(param, n);
    printf("%f * %d^%d = %f\n", param, FLT_RADIX, n, result);
    // 1.500000 * 2^4 = 24.000000

    // scalbln     Scale significand using floating-point base exponent(long):     double scalbln(double x, long int n);   float scalblnf(float x, long int n);   long double scalblnl(long double x, long int n);
    double param, result;
    long n;
    param = 1.50;
    n = 4L;
    result = scalbln(param, n);
    printf("%f * %d^%d = %f\n", param, FLT_RADIX, n, result);
    // 1.500000 * 2^4 = 24.000000

    //----------------------------------------Power functions----------------------------------------//
    // pow         Raise to power:     double pow(double base, double exponent);    float pow(float base, float exponent);  long double pow(long double base, long double exponent);    double pow(Type1 base, Type2 exponent);
    printf("7 ^ 3 = %f\n", pow(7.0, 3.0));
    printf("4.73 ^ 12 = %f\n", pow(4.73, 12.0));
    printf("32.01 ^ 1.54 = %f\n", pow(32.01, 1.54));
    // 7 ^ 3 = 343.000000
    // 4.73 ^ 12 = 125410439.217423
    // 32.01 ^ 1.54 = 208.036691

    // sqrt        Compute square root:    double sqrt(double x);    float sqrt(float x);    long double sqrt(long double x);     double sqrt(T x);
    double param, result;
    param = 1024.0;
    result = sqrt(param);
    printf("sqrt(%f)= %f\n", param, result);
    // sqrt(1024.000000)= 32.000000

    // cbrt        Compute cubic root:  double cbrt(double x);   float cbrtf(float x);   long double cbrtl(long double x);
    double param, result;
    param = 27.0;
    result = cbrt(param);
    printf("cbrt(%f)= %f\n", param, result);
    // cbrt(27.000000)= 3.000000

    // hypot       Compute hypotenuse:     double hypot(double x, double y);     float hypot(float x, float y);     long double hypot(long double x, long double y);     double hypot(Type1 x, Type2 y);
    double leg_x, leg_y, result;
    leg_x = 3;
    leg_y = 4;
    result = hypot(leg_x, leg_y);
    printf("%f, %f and %f form a right-angled triangle.\n", leg_x, leg_y, result);
    // 3.000000, 4.000000 and 5.000000 form a right-angled triangle.

    //----------------------------------------Error and gamma functions----------------------------------------//
    // erf	        Compute error function:     double erf(double x);   float erff(float x);     long double erfl(long double x);
    double param, result;
    param = 1.0;
    result = erf(param);
    printf("erf(%f)= %f\n", param, result);
    // erf(1.000000)= 0.842701

    // erfc	        Compute complementary error function:   double erfc(double x);    float erfcf(float x);  long double erfcl(long double x);
    double param, result;
    param = 1.0;
    result = erfc(param);
    printf("erfc(%f)= %f\n", param, result);
    // erfc(1.000000)= 0.157299

    // tgamma	    Compute gamma function:     double tgamma(double x);     float tgammaf(float x);  long double tgammal(long double x);
    double param, result;
    param = 0.5;
    result = tgamma(param);
    printf("tgamma(%f)= %f\n", param, result);
    // tgamma(0.500000)= 1.772454

    // lgamma	    Compute log-gamma function:      double lgamma(double x);   float lgammaf(float x);  long double lgammal(long double x);
    double param, result;
    param = 0.5;
    result = lgamma(param);
    printf("lgamma(%f)= %f\n", param, result);
    // lgamma(0.500000)= 0.572365

    //----------------------------------------Rounding functions----------------------------------------//
    // ceil       Round up value:      double ceil(double x);    float ceil(float x);long double ceil(long double x);     double ceil(T x);

    // floor      Round down value:     double ceil(double x);    float ceil(float x);long double ceil(long double x);     double ceil(T x);

    // trunc      Truncate value:   double ceil(double x);    float ceil(float x);long double ceil(long double x);     double ceil(T x);

    // round      Round to nearest:     double ceil(double x);    float ceil(float x);long double ceil(long double x);     double ceil(T x);
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

    // fmod     Compute remainder of division:   double fmod(double numer, double denom);     float fmod(float numer, float denom);    long double fmod(long double numer, long double denom);    double fmod(Type1 numer, Type2 denom);
    printf("fmod of 5.3 / 2 is %f\n", fmod(5.3, 2));
    printf("fmod of 18.5 / 4.2 is %f\n", fmod(18.5, 4.2));
    // fmod of 5.3 / 2 is 1.300000
    // fmod of 18.5 / 4.2 is 1.700000

    // remainder	Compute remainder(IEC 60559):       double remainder(double numer, double denom);    float remainder(float numer, float denom);   long double remainder(long double numer, long double denom);   double remainder(Type1 numer, Type2 denom);
    printf("remainder of 5.3 / 2 is %f\n", remainder(5.3, 2));
    printf("remainder of 18.5 / 4.2 is %f\n", remainder(18.5, 4.2));
    // remainder of 5.3 / 2 is -0.700000
    // remainder of 18.5 / 4.2 is 1.700000

    // remquo	    Compute remainder and quotient:     double remquo(double numer, double denom, int* quot);    float remquo(float numer, float denom, int* quot);     long double remquo(long double numer, long double denom, int* quot);   double remquo(Type1 numer, Type2 denom, int* quot);
    double numer = 10.3;
    double denom = 4.5;
    int quot;
    double result = remquo(numer, denom, &quot);
    printf("numerator: %f\n", numer);
    printf("denominator: %f\n", denom);
    printf("remainder: %f\n", result);
    printf("quotient: %d\n", quot);
    // numerator: 10.300000
    // denominator: 4.500000
    // remainder: 1.300000
    // quotient: 2

    //----------------------------------------Minimum, maximum, difference functions----------------------------------------//
    // fdim	    Positive difference:    double fdim(double x, double y);  float fdim(float x, float y);  long double fdim(long double x, long double y);  double fdim(Type1 x, Type2 y);
    printf("fdim(2.0, 1.0)= %f\n", fdim(2.0, 1.0));
    printf("fdim(1.0, 2.0)= %f\n", fdim(1.0, 2.0));
    printf("fdim(-2.0, -1.0)= %f\n", fdim(-2.0, -1.0));
    printf("fdim(-1.0, -2.0)= %f\n", fdim(-1.0, -2.0));
    // fdim(2.0, 1.0)= 1.000000
    // fdim(1.0, 2.0)= 0.000000
    // fdim(-2.0,-1.0)= 0.000000
    // fdim(-1.0,-2.0)= 1.000000

    // fmax	    Maximum value:  double fmax(double x, double y);  float fmax(float x, float y);    long double fmax(long double x, long double y);    double fmax(Type1 x, Type2 y);
    printf("fmax(100.0, 1.0)= %f\n", fmax(100.0, 1.0));
    printf("fmax(-100.0, 1.0)= %f\n", fmax(-100.0, 1.0));
    printf("fmax(-100.0, -1.0)= %f\n", fmax(-100.0, -1.0));
    // fmax(100.0, 1.0)= 100.000000
    // fmax(-100.0, 1.0)= 1.000000
    // fmax(-100.0,-1.0)= -1.000000

    // fmin	    Minimum value:  double fmin(double x, double y);   float fmin(float x, float y);   long double fmin(long double x, long double y);    double fmin(Type1 x, Type2 y);
    printf("fmin(100.0, 1.0)= %f\n", fmin(100.0, 1.0));
    printf("fmin(-100.0, 1.0)= %f\n", fmin(-100.0, 1.0));
    printf("fmin(-100.0, -1.0)= %f\n", fmin(-100.0, -1.0));
    // fmin(100.0, 1.0)= 1.000000
    // fmin(-100.0, 1.0)= -100.000000
    // fmin(-100.0,-1.0)= -100.000000

    //----------------------------------------Other function----------------------------------------//
    // abs      Compute absolute value:      double abs(double x);    float abs(float x);     long double abs(long double x);     double abs(T x);
    cout << "abs(3.1416)= " << std::abs(3.1416) << '\n';
    cout << "abs(-10.6)= " << std::abs(-10.6) << '\n';
    // abs(3.1416)= 3.1416
    // abs(-10.6)= 10.6

    // fma	    Multiply-add:   double fma(double x, double y, double z);    float fma(float x, float y, float z);  long double fma(long double x, long double y, long double z);  double fma(Type1 x, Type2 y, Type3 z);
    double x, y, z, result;
    x = 10.0, y = 20.0, z = 30.0;
#ifdef FP_FAST_FMA
    result = fma(x, y, z);
#else
    result = x * y + z;
#endif
    printf("10.0 * 20.0 + 30.0 = %f\n", result);
    //  10.0 * 20.0 + 30.0 = 230.000000

    return 0;
}