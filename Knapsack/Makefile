EXECUTABLE = knapsack

CXX = g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -Ofast

SOURCES = $(wildcard *.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $^ -o $@


.PHONY: clean distclean

clean:
	rm *.o

distclean: clean
	rm $(EXECUTABLE)
