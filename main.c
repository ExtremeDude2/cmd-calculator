/************************************************************/
/*                                                          */
/* Created by Ryan Collins 2012-2015, use at your own risk. */
/*                                                          */
/************************************************************/

#include <stdio.h>
#include <signal.h>
#include "calculator.h"

#include <stdlib.h>
#include <time.h>

static const char* operators[] = {
    "add", "sub", "mul", "div",
    "exp", "root",
    "gcd", "lcm",
};

const op_ptr functions[] = {
    add,
    subtract,
    multiply,
    divide,

    power,
    root,

    greatest_common_divisor,
    least_common_multiple,
};

int main(void)
{
    size_t i;
    real num1, num2;
    int recovered_from_exception;

    srand(time(NULL));
    for (;;)
    {
        fputs("Please enter a number:  ", stdout);
        num1 = carry_in();

        fputs("Please enter another number:  ", stdout);
        num2 = carry_in();

        for (i = 0; i < sizeof(functions) / sizeof(op_ptr); i++)
            printf(
                "%s(%g, %g) = %g\n",
                operators[i], num1, num2,
                functions[i](num1, num2)
            );

        signal(SIGFPE, FPU_exception);
        recovered_from_exception = setjmp(CPU_state);
        if (recovered_from_exception)
            printf("The square root of %g is %g*i.\n", num1, root(-num1, 2));
        else
            printf("The square root of %g is %g.\n", num1, root(num1, 2));

        signal(SIGFPE, FPU_exception);
        recovered_from_exception = setjmp(CPU_state);
        if (recovered_from_exception)
            printf("The square root of %g is %g*i.\n", num2, root(-num2, 2));
        else
            printf("The square root of %g is %g.\n", num2, root(num2, 2));

/*
 * integer-precision factorials
 */
        if (num1 >= 0)
            printf(
                "The factorial of %lu is %lu.\n",
                (unsigned long)num1,
                (unsigned long)factorial((whole)num1)
            );
        if (num2 >= 0)
            printf(
                "The factorial of %lu is %lu.\n",
                (unsigned long)num2,
                (unsigned long)factorial((whole)num2)
            );

        printf("%g to the power of %g is %g.\n", num2, num1, power(num2, num1));

        if (num1 == num2)
            puts("The two numbers are equal");
        if (num1 > num2)
            printf("%g is larger than %g.\n", num1, num2);
        if (num1 < num2)
            printf("%g is larger than %g.\n", num2, num1);

        printf("Random number of the day is:  %i\n", rand());
        puts("----------------------------------");
    }
    return 0;
}

static double carry_in(void)
{
    static char temp_buffer[64];
    register size_t i;

    for (i = 0; i < sizeof(temp_buffer); i++)
    {
        int character;

        temp_buffer[i] = '\0';
        character = getchar();
        if (character == '\n')
            return strtod(&temp_buffer[0], NULL);
        if (character < 0 || character > +127)
            return 0;
        temp_buffer[i] = (char)character;
    }
    return 0; /* standard library:  No valid conversion can be done. */
}

jmp_buf CPU_state; /* as of before attempting the offending command */
void FPU_exception(int exception_ID)
{
    signal(SIGFPE, FPU_exception);
    fprintf(
        stderr,
        "Hardware-native division by zero not available (signal %i).\n"\
        "Forcing in software...\n",
        exception_ID
    );
    longjmp(CPU_state, exception_ID);
    fprintf(stderr, "Unable to recover from exception:  no recovery point\n");
    return;
}
