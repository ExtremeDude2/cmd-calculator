/************************************************************/
/*                                                          */
/* Created by Ryan Collins 2012-2015, use at your own risk. */
/*                                                          */
/************************************************************/

#include <float.h>
#include <math.h>

double add(double m, double n)
{
    return (m + n);
}
double subtract(double m, double n)
{
    return (m - n);
}
double multiply(double m, double n)
{
    return (m * n);
}
double divide(double m, double n)
{
#ifndef PREFER_NATIVE_HARDWARE_DIVISION_BY_ZERO
    if (n == 0) /* Undefined, but we must return (something). */
    {
        n = DBL_MIN; /* smallest positive real number */
        m = (m < 0) ? -DBL_MAX : +DBL_MAX;
    } /* Geometric graphs of x/0 look prettiest this way. */
#endif
    return (m / n);
}
double power(double m, double n)
{
    return pow(m, n);
}

unsigned long factorial(unsigned long n)
{
    unsigned long answer, old_answer;
    unsigned long i;

    answer = 1;
    for (i = 1; i < n + 1; i++)
    {
        old_answer = answer;
        answer *= i;
        if (answer < old_answer) /* unsigned overflow */
            return 0; /* `n' is too large to store the correct factorial for. */
    }
    return (answer);
}
