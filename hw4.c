#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "rootfinding.h"
#include "Timers.h"

/* Function that represents the equation whose roots we are solving. Function
   evaluates and returns result at the given x value */
double equation(double value){
	return .76 * value * sin(30 * value / 52) * tan(10 * value / 47) \
	+ 2.9 * cos(value + 2.5) * sin(.39 * (1.5 + value));

}

/* Function that represents the derivative of the equation expressed above.
   Function evaluates and returns result at given x value */
double derivative(double value){

	return -2.9 * sin(.39 * (value + 1.5)) * sin(value + 2.5) \
	+ 1.131 * cos(.39 * (value + 1.5)) * cos(value + 2.5) \
	+ .76 * sin(15 * value /26) * tan(10 * value/47) \
	+ .438462 * value * cos(15 * value/26) * tan(10 * value/47) \
	+ .161702 * value * sin(15 * value/26) * (1 + tan(10 * value/47) * tan(10 * value/47));

}


int main(int argc, char *argv[]){

	/* Declare string variable to represent the method */
	char *method;

	/* Declare double values for cmdline args */
	double a, b, x0, x1, tolerance;

	/* Declare int value for cmdline args */
	int verbose;

	/* Declare counter variable to compare to MAX_ITERATIONS during timing */
	int iterations;

	/* Assign function addresses to variables */
	func1arg f=&equation;
	func1arg df=&derivative;

	/* Handle case where method is not provided */
	if(argc>1){
		method=argv[1];
	}else{
		method="notamethod";
	}

	/* Perform newtonian operation if the method is newton */
	if(strcmp(method, "newton")==0){

		/* Check for proper amount of cmd line args */
		if(argc!=5){

			/* Print usage */
			fprintf(stdout,"\nUsage: ./hw4 newton $TOL(double) $X(double) $VERB(0/1)\n");

			/* Return out of main method */
			return 0;

		}else{

			printf("Performing Newton Method!...\n");

			/* Assign newton parameters to cmdline args */
			tolerance=atof(argv[2]);
			x0=atof(argv[3]);
			verbose=atoi(argv[4]);

			DECLARE_TIMER(NewtonTimer);

			START_TIMER(NewtonTimer);

			/* Loop for NUM__ITERATIONS times through newton method */
			for(iterations=0;iterations < NUM_ITERATIONS;iterations++){

				/* Make function call to newton method */
				newton(f, df, x0, MAX_METHOD_ITERATIONS, tolerance, verbose);
			}

			STOP_TIMER(NewtonTimer);

			PRINT_TIMER(NewtonTimer);

			RESET_TIMER(NewtonTimer);
		}

	}else if(strcmp(method, "bisection")==0){

		/* Check for proper amount of cmd line args */
		if(argc!=6){

			/* print usage */
			fprintf(stdout,"\nUsage: ./hw4 bisection $TOL(double) $X0(double) $X1(double) $VERB(0/1)\n");

			/* Return out of main method */
			return 0;

		}else{

			printf("Performing Bisection Method!...\n");

			/* Assign bisection parameters to cmdline args */
			tolerance=atof(argv[2]);
			a=atof(argv[3]);
			b=atof(argv[4]);
			verbose=atoi(argv[5]);

			DECLARE_TIMER(BisectionTimer);

			START_TIMER(BisectionTimer);

			for(iterations=0;iterations<NUM_ITERATIONS;iterations++){

				/* Make function call to newton method */
				bisection(f,a,b, MAX_METHOD_ITERATIONS, tolerance,verbose);
			}

			STOP_TIMER(BisectionTimer);

			PRINT_TIMER(BisectionTimer);

			RESET_TIMER(BisectionTimer);

		}

	}else if(strcmp(method, "secant")==0){

		/* Check for proper number of cmd line args */
		if(argc!=6){

			/* Print proper usage */
			fprintf(stdout,"\nUsage: ./hw4 secant $TOL(double) $A(double) $B(double) $VERB(0/1)\n");

			/* Return out of main method */
			return 0;
		}else{

			printf("Performing Secant Method!...\n");

			/* Assign secant parameters to cmdline args */
			tolerance=atof(argv[2]);
			x0=atof(argv[3]);
			x1=atof(argv[4]);
			verbose=atoi(argv[5]);

			DECLARE_TIMER(SecantTimer);

			START_TIMER(SecantTimer);

			for(iterations=0;iterations<NUM_ITERATIONS;iterations++){

				/* Make function call here */
				secant(f,x0,x1,tolerance,MAX_METHOD_ITERATIONS,verbose);
			}

			STOP_TIMER(SecantTimer);

			PRINT_TIMER(SecantTimer);

			RESET_TIMER(SecantTimer);


		}
	}else{

		/* print proper usage */
		fprintf(stdout,"\nUsage: \n");
		fprintf(stdout,"./hw4 newton $TOL(double) $X(double) $VERB(0/1)\n");
		fprintf(stdout,"./hw4 bisection $TOL(double) $X0(double) $X1(double) $VERB(0/1)\n");
		fprintf(stdout,"./hw4 secant $TOL(double) $A(double) $B(double) $VERB(0/1)\n");

	}

	return 0;
}
/* end main method */
