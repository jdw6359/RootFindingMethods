#-----------------------------------------------------------------------
# Makefile for GNU/Linux system (tested on Ubuntu 12.04)
# Compiles and tests rootfinding module
# Revised, J.C. Cockburn 3/7/2014
# ----------------------------------------------------------------------

## for GCC
CC = gcc
CFLAGS = -Wall -ansi
LFLAGS = -lm

##Optimization levels
## -O1, -O2, -O3, or Nothing
OptLevel=


#Timers module
TIMER=

## Testing Parameters, modify as needed
TOL=.000000000001
#Bisection
A=-2.5
B=2.5
#Newton
X01=-1.5
X02=1.5
#Secant
X11=2.07
X12=2.5
#VERB=1 (print partial results)
VERB=1

## Main "body" of makefile

hw4: rootfinding.o hw4.o
	$(CC) $(OptLevel) $(CFLAGS) -o  hw4 rootfinding.o hw4.o $(LFLAGS) 

rootfinding.o: rootfinding.c rootfinding.h FORCE
	$(CC) $(OptLevel) -c $(OptLevel) rootfinding.c 

hw4.o: hw4.c FORCE
	$(CC) $(OptLevel) -c $(OptLevel)  hw4.c $(TIMER)

FORCE: 


##Testing block, redirect output to a file?

test: hw4
	./hw4 bisection $(TOL) $(A) $(B) $(VERB)
	./hw4 secant $(TOL) $(X01) $(X11) $(VERB)
	./hw4 secant $(TOL) $(X02) $(X12) $(VERB)
	./hw4 newton $(TOL) $(X02) $(VERB)
	./hw4 newton $(TOL) $(X01) $(VERB)


bisection: hw4
	./hw4 bisection $(TOL) $(A) $(B) $(VERB)

secant: hw4
	./hw4 secant $(TOL) $(X02) $(X12) $(VERB)
	./hw4 secant $(TOL) $(X01) $(X11) $(VERB)

newton: hw4
	./hw4 newton $(TOL) $(X01) $(VERB)
	./hw4 newton $(TOL) $(X02) $(VERB)



##Cleaning auxiliary files
clean:
	rm -f *.o

