/************************************************************/
/*                                                          */
/* Created by Ryan Collins 2012-2015, use at your own risk. */
/*                                                          */
/************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned long factorial(unsigned long n)
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

static double carry_in(void)
{
    static char temp_buffer[32];
    size_t i;

    for (i = 0; i < sizeof(temp_buffer); i++)
    {
        int character;

        character = getchar();
        if (character == '\n')
            break;
        if (character == EOF)
        {
            fputs("scan_long:  unexpected EOF\n", stderr);
            break;
        }
        temp_buffer[i] = (char)character;
    }

    if (i >= sizeof(temp_buffer))
    {
        fputs("scan_long:  evaded buffer overrun\n", stderr);
        i = sizeof(temp_buffer) - 1;
    }
    temp_buffer[i] = '\0';
    return strtod(temp_buffer, NULL);
}

int main(void)
{
    double num1, num2;
    
    while (1)
    {
        fputs("Please enter a number: ", stdout);
        num1 = carry_in();

        fputs("Please enter another number: ", stdout);
        num2 = carry_in();

        printf("%g + %g = %g\n", num1, num2, num1 + num2);
        printf("%g - %g = %g\n", num1, num2, num1 - num2);
        printf("%g * %g = %g\n", num1, num2, num1 * num2);
        if (num2 == 0)
            fputs("Cannot divide by 0.\n", stderr);
        else
            printf("%g / %g = %g\n", num1, num2, num1 / num2);

        if (num1 < 0)
            puts("Error: cannot find the square root of a number less than 0");
        else
            printf("The square root of %g is %g.\n", num1, sqrt(num1));

        if (num2 < 0)
            puts("Error: cannot find the square root of a number less than 0");
        else
            printf("The square root of %g is %g.\n", num2, sqrt(num2));

/*
 * integer-precision factorials
 */
        if (num1 >= 0)
            printf(
                "The factorial of %lu is %lu.\n",
                (unsigned long)num1,
                factorial((unsigned long)num1)
            );
        if (num2 >= 0)
            printf(
                "The factorial of %lu is %lu.\n",
                (unsigned long)num2,
                factorial((unsigned long)num2)
            );

        printf("%g to the power of %g is %g.\n", num1, num2, pow(num1, num2));
        printf("%g to the power of %g is %g.\n", num2, num1, pow(num2, num1));

        if (num1 == num2)
            puts("The two numbers are equal");
        if (num1 > num2)
            printf("%g is larger than %g.\n", num1, num2);
        if (num1 < num2)
             printf("%g is larger than %g.\n", num2, num1);

        srand(time(NULL));
        printf("Random number of the day is:  %g\n", rand());
        puts("----------------------------------");
    }
    return 0;
}
