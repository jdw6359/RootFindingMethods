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
extern double bisection ( func1arg f, double a, double b, int Nmax, double tol, int verb){

	/* double value to represent the midpoint we are evaluating */
	double c;

	/* Declare looping variable */
	int count=1;

	while(count < Nmax){
		printf("A and B values: %f, %f\n", a,b);
		/* Set c equal to the new midpoint between values a and b */
		c=(a+b)/2;

		/* If f(c) is zero or the distance between b and a is less than the
		desired tolerance, we have found our solution */
		if((f(c)==0)||((b-a)/2<tol)){
			printf("Root found %f\n", c);
			break;
		}
		/* end if check to find root */

		/* increment counter */
		count++;

		/* check to see what half we are going to further investigate */
		if((f(a) * f(c))>0){

			/* a and c are the same sign, a is set to c's value */
			a=c;
		}else{

			/* c and c are the same sign, b is set to c's value */
			b=c;
		}
		/* end sign check */

	}
	/* end while loop */

	return 0.0;
}
/* end bisection method */


extern double newton(func1arg f, func1arg df, double x0, int Nmax, double tol, int verb){

	return 0.0;
}
/* end newtonian method */


extern double secant (func1arg f, double x0, double x1, double tol, int Nmax, int verb){


	return 0.0;
}
/* end secant method */
