SOURCES = $(wildcard *.cpp)
LIBRARIES = $(wildcard *.h)
OBJ := $(patsubst %.cpp,%.o,$(SRC))
FLAGS = -Wall -pedantic

main: students.o main.o
	g++ $(FLAGS) *.cpp -o main

run:	main
	./main

clean:
	rm -f *.o
