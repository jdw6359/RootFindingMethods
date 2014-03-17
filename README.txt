In order to run the programs as described in analysis.txt, 
please use the command: 
	make test

To run the methods individually, please use any of the following commands:
	make bisection
	make secant
	make newton
**Keep in mind that for newton and secant, the program will be run for each 
**of the two pairs of inputs


In addition, the makefile is structured so that values used during compilation
as well as execution can be modified and easily applied.

To allow/deny verbose output, open the makefile and set
	VERB=0 or
	VERB=1
**Keep in mind that displaying the result of the algorithms is dependant on
**VERB being set to 1

To include the timing options in the program execution, open the makefile and 
set TIMER=-DEN_TIME
**Otherwise, leave empty

The compiler optimization levels can be changed with the option OptLevel
-O1, -O2, -O3

 
