HEADERS = ../atof.h

default: myatof

myatof.o: myatof.c $(HEADERS)
	gcc -c myatof.c -o myatof.o

atof.o: ../atof.c
	gcc -c ../atof.c -o atof.o

myatof: myatof.o atof.o
	gcc myatof.o atof.o -o myatof

clean:
	rm -f myatof.o
	rm -f atof.o
	rm -f myatof
