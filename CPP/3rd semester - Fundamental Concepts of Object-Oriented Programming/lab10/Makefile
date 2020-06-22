GXX = g++
FLAGS = -Wall -g -pedantic

main: main.o point.o linkedList.o
	$(GXX) *.o -o main 

main.o: main.cpp
	$(GXX) -c $(FLAGS) main.cpp

point.o: point.cpp point.h
	$(GXX) -c $(FLAGS) point.cpp

linkedList.o: linkedList.cpp linkedList.h
	$(GXX) -c $(FLAGS) linkedList.cpp



clean:
	rm -rf *.o main

run: main
	./main

check: main
	valgrind ./main

all: main run

.PHONY: all run clean check
