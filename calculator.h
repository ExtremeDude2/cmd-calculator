#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#if 0
typedef long double             real;
#else
typedef double                  real;
#endif
typedef real (*op_ptr)(real m, real n);

/*
 * Try to take advantage of the C implementation to provide the best
 * (highest-precision) integer types--preferably in a C89-compliant way.
 *
 * A `whole' number is a non-negative integer.  This is an important type to
 * have for operations like !x (factorial), which cannot return for (x < 0).
 */
#include <limits.h>
#include <stddef.h>

/*
 * Set up exception-handling in C in case the user requests funny things.
 * Division by 0, even-roots of negative numbers, 0 to the power of 0, etc.
 */
#include <setjmp.h>
extern jmp_buf CPU_state;
extern void FPU_exception(int exception_ID);

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

extern const op_ptr functions[];

real add(real m, real n);
real subtract(real m, real n);
real multiply(real m, real n);
real divide(real m, real n);

real power(real m, real n);
real root(real radicand, real index); /* basically power(m, 1/n) */

real greatest_common_divisor(real m, real n);
real least_common_multiple(real m, real n);

extern whole factorial(whole n);

/*
 * string-to-number input conversion replacement for C++ cout and cin
 */
extern double carry_in(void);

#endif
