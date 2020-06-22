CXX = g++
EXEC = main
CXXFLAGS = -Wall -pedantic -std=c++14

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

$(EXEC): $(OBJS) 
	$(CXX) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o
	rm -f *.txt
	rm -f *.d
	rm -f $(EXEC)

-include $(DEPS)
