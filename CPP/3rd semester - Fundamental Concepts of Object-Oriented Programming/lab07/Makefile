FLAG = -Wall -g -pedantic

main: intLinkedList.o main.o
	g++ $(FLAG) *.cpp -o main

run:
	./main

check:
	valgrind ./main

clean:
	rm -f *.o

all: main run
