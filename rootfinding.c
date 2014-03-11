/*****************************************************************************
 * Application Code for root-finding module
 * Course: Applied Programming
 * Author: Josh Woodward
 * Edit Dates: 3/10/2014
 * Module provides, bisection, newton, and secant rootfinding methods
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "rootfinding.h"


/* Bisection method implementation */
extern double bisection ( func1arg f, double a, double b, double tol, int verb){


	return 0.0;
}
/* end bisection method */


extern double newton(func1arg f, func1arg df, double x0, int Nmax, double tol, int verb){
	printf("Normal function call: %f\n", f(0.0));
	printf("Derivative function call: %f\n", df(0.0));

	return 0.0;
}
/* end newtonian method */


extern double secant (func1arg f, double x0, double x1, double tol, int Nmax, int verb){


	return 0.0;
}
/* end secant method */
