FLAG = -Wall -pedantic

main: print.o suma.o maksimum.o srednia.o arytmetyczny.o mediana.o main.o
	g++ $(FLAG) *.cpp -o main

test:
	./main

clean:
	rm -f *.o

all: main test
