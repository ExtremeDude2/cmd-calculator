/************************************************************/
/*                                                          */
/* Created by Ryan Collins 2012-2015, use at your own risk. */
/*                                                          */
/************************************************************/

#include <float.h>
#include <math.h>
#include "calculator.h"

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
double root(double radicand, double index)
{
    double scientific; /* index * 10^x, until it becomes an integer */
    integer i; /* e.g. 8 ^ (5/3) = cuberoot(8 ^ 5), so i = 3 */

    if (radicand == 0)
        return 0; /* divide(0, 0) is too abstract and could be anything. */
    if (index == 0)
        return divide(radicand, 0);

    scientific = index;
    while (scientific != (double)((integer)scientific))
        scientific *= 10;
    i = (integer)scientific;

    if (radicand < 0 && i % 2 != 0) /* odd-roots of negative numbers */
        return -power(-radicand, 1 / index);
    return power(radicand, 1 / index);
}

whole factorial(whole n)
{
    whole answer, old_answer;
    whole i;

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
