default: calculator2

calculator2: calculator2.o stack.o getop.o
	gcc calculator2.o stack.o getop.o getch.o -o calculator2 -lm

calculator2.o: calculator2.c
	gcc -c calculator2.c -o calculator2.o 

stack.o: stack.c
	gcc -c stack.c -o stack.o

getop.o: getop.c getch.o
	gcc -c getop.c -o getop.o

getch.o: getch.c
	gcc -c getch.c -o getch.o

clean:
	rm calculator2
	rm calculator2.o
	rm stack.o
	rm getop.o
	rm getch.o
