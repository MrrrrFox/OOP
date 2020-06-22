FLAG = -Wall -g -pedantic

main: numbers.o complexNumber.o main.o
	g++ $(FLAG) *.cpp -o main -lm

run:
	./main

check:
	valgrind ./main

clean:
	rm -f *.o

all: main run
