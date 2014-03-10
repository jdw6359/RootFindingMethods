/*****************************************************************************
 Header file for root-finding C-module
 Course: Applied Programming
 Adapted to ANSI C by Juan C. Cockburn
 Revised: October 11/10/2013

 Module provides: bisection, newton and secant methods
 *****************************************************************************/
#ifndef _ROOTFINDING_H_
#define _ROOTFINDING_H_

/* Typemark for a scalar function of one variable */
typedef double (*func1arg) (double);

/* Function prototypes */
extern double bisection ( func1arg f, double a, double b, double tol , int verb);
/* 
PURPOSE:   find the root of a scalar nonlinear function using the
           bisection method

CALLING SEQUENCE:
           root = bisection ( f, a, b, tol, verb );
INPUTS:
           f        function whose root is to be determined
                    must take a single argument of type double and return
                    single value of type double
           a        left endpoint of interval known to contain root
                    type:  double
           b        right endpoint of interval known to contain root
                    type:  double
           tol      absolute error convergence tolerance
                    type:  double
           verb     flag indicating whether to print intermediate
                    results ( 1 = TRUE, 0 = FALSE )
                    type:  int
OUTPUT:
           root     approximate location of root
                    type:  double
*/

extern double newton ( func1arg f, func1arg df, double x0, int Nmax, double tol, int verb);
/*
PURPOSE:   find the root of a scalar smooth nonlinear function using
           Newton's method

CALLING SEQUENCE:
           root = newton ( f, df, x0, Nmax, tol, verb );
INPUTS:
           f        function whose root is to be determined
                    must take single argument of type double and return
                    single value of type double
           df       derivative of function whose root is to be determined
                    must take single argument of type double and return
                    single value of type double
           x0       initial guess for location of root
                    type:  double
           tol      absolute error convergence tolerance
                    type:  double
           Nmax     maximum number of iterations to achieve convergence
                    type:  int
           verb     flag indicating whether to print intermediate
                    results ( 1 = TRUE, 0 = FALSE )
                    type:  int
OUTPUT:
           root     approximate location of root
                    type:  double
*/

extern double secant ( func1arg f, double x0, double x1, double tol, int Nmax, int verb);
/*
PURPOSE:   find the root of a scalar nonlinear function using
           the secant method

CALLING SEQUENCE:
           root = secant ( f, x0, x1, Nmax, tol, verb );
INPUTS:
           f        function whose root is to be determined
                    must take single argument of type double and return
                    single value of type double
           x0       one initial guess for location of root
                    type:  double
           x1       another initial guess for location of root
                    type:  double
           Nmax     maximum number of iterations to achieve convergence
                    type:  int
           tol      absolute error convergence tolerance
                    type:  double
           verb     flag indicating whether to print intermediate
                    results ( 1 = TRUE, 0 = FALSE )
                    type:  int
OUTPUT:
           root     approximate location of root
                    type:  double
*/

#endif /* _ROOTFINDING_H_ */