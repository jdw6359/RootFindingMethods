/*****************************************************************************
 * Application Code for root-finding module
 * Course: Applied Programming
 * Author: Josh Woodward
 * Edit Dates: 3/10/2014
 * Module provides, bisection, newton, and secant rootfinding methods
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "rootfinding.h"

/* Bisection method implementation */
extern double bisection ( func1arg f, double a, double b, int Nmax, double tol, int verb){

	/* double value to represent the midpoint we are evaluating */
	double c;

	/* Declare looping variable */
	int count=1;

	while(count < Nmax){
		/* Set c equal to the new midpoint between values a and b */
		c=(a+b)/2;

		if(verb==1){

			/* If the verbose flag is set, then we will display the
			partial results of the alrogith here */
			fprintf(stdout, "\nThis is iteration #%d through the bisection algorithm...\n", count);
			fprintf(stdout, "The left endpoint is %f\n", a);
			fprintf(stdout, "The right endpoint is %f\n", b);
			fprintf(stdout, "The midpoint between the two points is %f\n", c);

			/* Going to display results as to which bisection to
			investigate, for programming convenience, the same logic that
			is used lower in this algorithm is going to be repeated without
			concern for performance due to the fact that we explicitly would
			like to see the partial results */
			if((f(a) * f(c))>0){
				fprintf(stdout, "There is a sign change between %f and %f, we will further investigate this bisection\n", c, b);
			}else{
				fprintf(stdout, "There is a sign change between %f and %f, we will further investigate this bisection\n", a, c);
			}

		}
		/* End if verb output */

		/* If f(c) is zero or the distance between b and a is less than the
		desired tolerance, we have found our solution */
		if((f(c)==0)||(fabs((b-a)/2)<tol)){

			/* Only display the results if verb is set to one */
			if(verb==1){
				printf("\nRoot found %f\n\n", c);
			}

			return c;
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

	/* Declare x,y,and yprime variables */
	double y, yprime, x1;

	/* Declare and initialize counter */
	int count=1;

	/* only loop max NMax number of times */
	while(count<Nmax){

		/* assign the function and derivative values at this x value */
		y=f(x0);
		yprime=df(x0);

		/* Do newton's computation */
		x1=x0-y/yprime;

		/* only print verbose output if verb flag is set */
		if(verb==1){

			/* Print the verbose output if the verb flag is set */
			fprintf(stdout, "\nThis is iteration #%d through the newton algorithm\n", count);
			fprintf(stdout, "Current X Value:%f\n", x0);
			fprintf(stdout, "Y Value at %f: %f\n", x0, y);
			fprintf(stdout, "Y Prime at %f: %f\n", x0, yprime);
			fprintf(stdout, "New X Value Given Tangent Line: %f\n", x1);

		}
		/* End verb output check */

		/* if the result is within tolerance, we have found the solution */
		if(fabs(x1-x0)/fabs(x1) < tol){

			/* only display output of verb is set to one */
			if(verb==1){
				fprintf(stdout, "\nsolution found: %f\n\n", x0);
			}

			return x0;
		}

		x0=x1;

		/* Increment count */
		count++;
	}
	return 0.0;
}
/* end newtonian method */


extern double secant (func1arg f, double x0, double x1, double tol, int Nmax, int verb){

	/* Declare values for temp x and f as well as function values for x0 and x1 */
	double f0,f1;
	double tempx, tempf;

	/* Declare and initialize counter variable */
	int count=1;

	/* Get values for function at x values of x0 and x1 */
	f0=f(x0);
	f1=f(x1);

	/* Make sure that we only perform a maxumum of Nmax iterations */
	while(count<Nmax){

		/* Print verbose output only if the flag is set */
		if(verb==1){

			/* Only display verbose output if flag is set */
			fprintf(stdout, "\nThis is iteration #%d through the secant algorithm\n", count);
			fprintf(stdout, "Value of x0 is: %f\n", x0);
			fprintf(stdout, "Value of x1 is: %f\n", x1);
			fprintf(stdout, "Value of f(%f) is: %f\n", x0,f(x0));
			fprintf(stdout, "Value of f(%f) is: %f\n", x1, f(x1));

		}

		/* If function value at x0 is closer to x axis than function value
		at x1, then switch the value( and function value) of x0 and x1 */
		if(fabs(f0) < fabs(f1)){

			/* Switch value of x0 and x1 */
			tempx=x0;
			x0=x1;
			x1=tempx;

			/* Switch value of f0 and f1 */
			tempf=f0;
			f0=f1;
			f1=tempf;
		}

		/* calulate new x value that will take the place of new x1 */
		tempx=x1-(f1/(f1-f0))*(x1-x0);

		/* "move" x values over, that is x0=x1 and x1= new value */
		x0=x1;
		x1=tempx;

		/* do the same for new function values */
		f0=f1;
		f1=f(tempx);

		/* If difference between values is within tolerance
		result has been found */
		if(fabs(x1-x0)<tol){

			/* Only display results if verb flag is set */
			if(verb==1){

				fprintf(stdout, "\nResult is x = %f\n\n", x1);
			}

			return x1;
		}

		/* Increment count */
		count++;
	}

	return 0.0;

}
/* end secant method */
