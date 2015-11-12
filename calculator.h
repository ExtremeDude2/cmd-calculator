#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

typedef double(*op_ptr)(double m, double n);
extern const op_ptr functions[];

double add(double m, double n);
double subtract(double m, double n);
double multiply(double m, double n);
double divide(double m, double n);

double power(double m, double n);
double root(double radicand, double index); /* basically power(m, 1/n) */

extern unsigned long factorial(unsigned long n);

/*
 * string-to-number input conversion replacement for C++ cout and cin
 */
static double carry_in(void);

#endif
