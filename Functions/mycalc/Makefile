
default: calc

calc.o: calc.c
	gcc -c calc.c -o calc.o

calc: calc.o
	gcc -g calc.o -o calc

clean:
	rm calc
	rm calc.o
