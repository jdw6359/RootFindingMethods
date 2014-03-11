#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rootfinding.h"

double equation(double value){
	return 341.11;
}

double derivative(double value){
	return 911.350;
}


int main(int argc, char *argv[]){

	/* Check to make sure that the first argument is a method type */

	/* Declare string variable to represent the method */
	char *method;



	/* set method equal to the first applicable cmdline arg */
	method=argv[1];

	/* Perform newtonian operation if the method is newton */
	if(strcmp(method, "newton")==0){

		func1arg f=&equation;
		func1arg df=&derivative;
		double guess, tolerance;
		int verbose;
		guess=atof(argv[2]);
		tolerance=atof(argv[3]);
		verbose=atoi(argv[4]);

		newton(f, df, guess, MAX_ITERATIONS, tolerance, verbose);

	}
	/* End newton check */

	if(strcmp(method, "bisection")==0){

	}
	/* end bisection check */

	if(strcmp(method, "secant")==0){

	}
	/* end secant check */






	printf("Arg: %s\n", method);





	return 0;
}
