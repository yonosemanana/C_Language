default: calculator

calculator: calculator.o stack.o getop.o
	gcc calculator.o stack.o getop.o getch.o -o calculator

calculator.o: calculator.c
	gcc -c calculator.c -o calculator.o

stack.o: stack.c
	gcc -c stack.c -o stack.o

getop.o: getop.c getch.o
	gcc -c getop.c -o getop.o

getch.o: getch.c
	gcc -c getch.c -o getch.o

clean:
	rm calculator
	rm calculator.o
	rm stack.o
	rm getop.o
	rm getch.o
