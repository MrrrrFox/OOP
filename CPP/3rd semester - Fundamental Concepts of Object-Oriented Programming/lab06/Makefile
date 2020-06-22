FLAG = -Wall -g -pedantic

main: intArrayList.o main.o
	g++ $(FLAG) *.cpp -o main

run:
	./main

clean:
	rm -f *.o

all: main run
