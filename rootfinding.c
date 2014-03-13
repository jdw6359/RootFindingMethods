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

	printf("\nPerforming bisection method...\n");

	/* double value to represent the midpoint we are evaluating */
	double c;

	/* Declare looping variable */
	int count=1;

	while(count < Nmax){
		/* Set c equal to the new midpoint between values a and b */
		c=(a+b)/2;

		/* If the verbose flag is set, then we will display the
		partial results of the alrogith here */
		printf("\nThis is iteration #%d through the bisection algorithm...\n", count);
		printf("The left endpoint is %f\n", a);
		printf("The right endpoint is %f\n", b);
		printf("The midpoint between the two points is %f\n", c);

		/* Going to display results as to which bisection to
		investigate, for programming convenience, the same logic that
		is used lower in this algorithm is going to be repeated without
		concern for performance due to the fact that we explicitly would
		like to see the partial results */
		if((f(a) * f(c))>0){
			printf("There is a sign change between %f and %f, we will further investigate this bisection\n", c, b);
		}else{
			printf("There is a sign change between %f and %f, we will further investigate this bisection\n", a, c);
		}





		/* If f(c) is zero or the distance between b and a is less than the
		desired tolerance, we have found our solution */
		if((f(c)==0)||(fabs((b-a)/2)<tol)){
			printf("\nRoot found %f\n\n", c);
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

	printf("\nPerforming newton method...\n");

	double y, yprime, x1;

	int count=1;


	while(count<Nmax){

		/* assign the function and derivative values at this x value */
		y=f(x0);
		yprime=df(x0);

		/* Do newton's computation */
		x1=x0-y/yprime;

		/* if the result is within tolerance, we have found the solution */
		if(fabs(x1-x0)/fabs(x1) < tol){
			printf("\nsolution found: %f\n\n", x0);
			break;
		}
		x0=x1;
		count++;
	}



	return 0.0;
}
/* end newtonian method */


extern double secant (func1arg f, double x0, double x1, double tol, int Nmax, int verb){

	printf("Performing secant method...");

	double f0,f1;
	double tempx, tempf;
	int count=0;

	f0=f(x0);
	f1=f(x1);
	while(count<Nmax){

		if(fabs(f0) < fabs(f1)){
			tempx=x0;
			x0=x1;
			x1=tempx;

			tempf=f0;
			f0=f1;
			f1=tempf;
		}

		tempx=x1-(f1/(f1-f0))*(x1-x0);
		x0=x1;
		f0=f1;
		x1=tempx;
		f1=f(tempx);

		if(fabs(x1-x0)<tol){
			printf("\nResult is x = %f\n\n", x1);
			break;
		}


		count++;
	}



	return 0.0;
}
/* end secant method */
