#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

/*
 * Try to take advantage of the C implementation to provide the best
 * (highest-precision) integer types--preferably in a C89-compliant way.
 *
 * A `whole' number is a non-negative integer.  This is an important type to
 * have for operations like !x (factorial), which cannot return for (x < 0).
 */
#include <limits.h>
#include <stddef.h>

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
typedef long long               integer;
typedef unsigned long long      whole;
#elif (ULONG_MAX > 0x00000000FFFFFFFFul)
typedef signed long             integer;
typedef unsigned long           whole;
#elif defined(INT64_MIN) && defined(INT64_MAX) && defined(UINT64_MAX)
typedef int64_t                 integer;
typedef uint64_t                whole;
#else
typedef long int                integer;
typedef size_t                  whole;
#endif

typedef double(*op_ptr)(double m, double n);
extern const op_ptr functions[];

double add(double m, double n);
double subtract(double m, double n);
double multiply(double m, double n);
double divide(double m, double n);

double power(double m, double n);
double root(double radicand, double index); /* basically power(m, 1/n) */

extern whole factorial(whole n);

/*
 * string-to-number input conversion replacement for C++ cout and cin
 */
static double carry_in(void);

#endif
