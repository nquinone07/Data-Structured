#include <Math.h>

/*******************************************************
 *
 *  Transcendental Functions
 *  E.g. sin, cos, log, exp
 *
 *  These functions are comprised of 3 steps:
 *      1. Reduction -- Map and reduce the given value 
 *                      to a suitably confined, finite range
 *                      such that the problem is transposed 
 *                      applying the function to the transformed
 *                      value with finite, confined range.
 *      2. Approximation -- Calculated of the transformed value
 *                          typically performed by computing an
 *                          approximating polynomial.
 *      3. Reconstruction -- Composition of the final result 
 *                           based on the approximation step 
 *                           before and arithmetic operations 
 *                           of related, chosen constants from the 
 *                           transformation in reduction step.
 * 
 * DESCRIPTION: 
 * Taylor Series = f(a) + f'(a)/1!*(x-a) + f''(a)/2!*(x-a)^2 + ...
 *               = summation n = 0 -> inf [ f(n)(a)/(n!)*(x-a)^n ]
 * where f(n)(a) denotes the nth derivative of f evaluated at point a,
 * when a=0 this is called the Maclaurin Series
 * Example
 *
 * f(x) = ln(x)
 *
 * Approximating Taylor Series:
 *
 * ln(a) + 1/a * (x-a) - 1/a^2 * (x-a)^2
 *
 * Novel Reduction:
 * We use the property f(uv) = g(f(u)),f(v)) e.g. ln(uv) = ln(u) + ln(v), where g is the summation operator
 * We can achieve argument reduction by using :
 * IA64 frcpa instruction which approximates the floating point division of 1/a using the upper 8-bits
 * as lookup for the normalized input a hence approximating to about 8 significant bits off accuracy.
 * So we have :
 *  f(x) = f(xfrcpa(x)/frcpa(x))
 *       = g(f(xfrcpa(x),f(1/frcpa(x)))
 * So,
 *  f(1/frcpa(x)) can be looked up using precomputed tables with the corollary index being the upper 
 *  8 bits of x
 *
 * The functions considered here have a natural expansion around 1. The function:
 *  f(xfrcpa(x))
 * is most naturally approximated by a polynomial evaluated at:
 *  r = xfrcpa(x) - 1
 *******************************************************/

/* 
 * Natural Logarithm
 *
 * For ln(x) = ln( 2**ex * m) = ex*ln(2) + ln(m), where x = 2**ex + m
 *
 * Reduction:
 * Reducing to interval [1.0, 2.0]
 * => ln(x) = ln(2**ex * y)   , where ex is some exponent
 *          = ex*ln(2) + ln(y)
 * we compute ex by finding the highest power of 2 which is less than x (e.g. find the most significant 
 * bit of x)
 *
 * Approximation:
 * Compute a minimax polynomial using the Remez algorithm:
 *
 * Reconstruction:
 * Use a table to lookup all potential ex*ln(2), adding its result to the approximating minimax polynomial
 * evaluated at y
 *
 */
static float Math::elog(size_t x)
{
    /* Constants & Variables */
    // The natural log of 2, precomputed
    const float LN_2 = 0.69314718056;
    // The highest power of 2
    ssize_t high_pow2;
    // Divisor and the variable mapping the function to a reduced range
    float divisor, reduced_var, result;
    /* Reduction */
    // The reduced variable is computable from the expression:
    // reduced_var = x/(2**ex) , where 2**ex is the highest power of 2 which is still smaller than x
    high_pow2   = Math::msb(x);
    divisor     = static_cast<float>(1 << high_pow2); // 2**ex (left shift 1 msb times)
    reduced_var = x / divisor;
    /* Approximating polynomial */
    // TODO: Implement the remez algorithm. Replacing the below..
    /* polynomial_t ln_minimax = Math::remez_algorithm() */
    // Referencing: https://stackoverflow.com/questions/9799041/efficient-implementation-of-natural-logarithm-ln-and-exponentiation
    result = -1.7417939 + (2.812026 + (-1.4699568 + (0.44717955 - 0.056570851 * reduced_var) * reduced_var) * reduced_var) * reduced_var;
    /* Reconstruction */
    // ex*ln(2) + ln(y), where ln(y) is computed above
    result += LN_2 * high_pow2;
    /* Return */
    return result;
}

/* MSB
 * 
 * Using the GCC builtin __builtin_clz, find the most significant bit _position_ in the given word
 *
 * GIVENS:
 * = the word given is a size_t 
 * = the system defines a byte as 8 bits
 *
 * ASSUMPTIONS:
 * = word is non-zero, the builtin __builtinz_clz has undefined behaviour given 0
 *
 * RETURNS:
 * = the bit index of the most signficant bit in the word
 */
static size_t Math::msb(size_t word)
{
    return (sizeof(word) * BITS_PER_BYTE) - __builtin_clz(word) - 1;
}

static float Math::pow(ssize_t val, ssize_t power)
{
    // UNSAFE
    float result;
    return result;
}

/********************************* TODO **********************************/ 

static ssize_t Math::ceil(float val)
{
    return static_cast<ssize_t>(val) + 1;
}

static ssize_t Math::floor(ssize_t val)
{
    // STUBBED
    return 0;
}
