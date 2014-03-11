#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#include "rootfinding.h"

/* Function that represents the equation whose roots we are solving. Function
   evaluates and returns result at the given x value */
double equation(double value){
	return .76 * value * sin(30/52 * value) * tan(10/47 * value) + \
	2.9 * cos(value + 2.5) * sin(.39 * (1.5 + value));
}

/* Function that represents the derivative of the equation expressed above.
   Function evaluates and returns result at given x value */
double derivative(double value){
	return 911.350;
}


int main(int argc, char *argv[]){
/*
	printf("Result at %f is %f\n", 2.212389, equation(2.212389));
	double start=-2.5;
	double end=2.5;
	while(start<end){

		printf("value at %f is %f\n", start, equation(start));
		start+=.01;
	}

*/



	/* Check to make sure that the first argument is a method type */

	/* Declare string variable to represent the method */
	char *method;

	/* Declare double values for cmdline args */
	double a, b, x0, x1, tolerance;

	/* Declare int value for cmdline args */
	int verbose;

	/* Assign function addresses to variables */
	func1arg f=&equation;
	func1arg df=&derivative;

	/* set method equal to the first applicable cmdline arg */
	method=argv[1];

	/* Perform newtonian operation if the method is newton */
	if(strcmp(method, "newton")==0){

		/* Assign newton parameters to cmdline args */
		tolerance=atof(argv[2]);
		x0=atof(argv[3]);
		verbose=atoi(argv[4]);

		/* Make function call to newton method */
		newton(f, df, x0, MAX_ITERATIONS, tolerance, verbose);

	}
	/* End newton check */

	if(strcmp(method, "bisection")==0){

		/* Assign bisection parameters to cmdline args */
		tolerance=atof(argv[2]);
		a=atof(argv[3]);
		b=atof(argv[4]);
		verbose=atoi(argv[5]);

		/* Make function call to newton method */

		bisection(f,a,b, MAX_ITERATIONS, tolerance,verbose);
	}
	/* end bisection check */

	if(strcmp(method, "secant")==0){

		/* Assign secant parameters to cmdline args */
		tolerance=atof(argv[2]);
		x0=atof(argv[3]);
		x1=atof(argv[4]);
		verbose=atoi(argv[5]);

		secant(f,x0,x1,tolerance,MAX_ITERATIONS,verbose);

	}
	/* end secant check */

	return 0;
}
/* end main method */
