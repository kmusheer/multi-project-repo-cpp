# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Executable name
TARGET = studentDB

# Object files
OBJS = main.o lib.o studentLib.o

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp lib.h
	$(CXX) $(CXXFLAGS) -c main.cpp

lib.o: lib.cpp lib.h
	$(CXX) $(CXXFLAGS) -c lib.cpp

studentLib.o: studentLib.cpp lib.h
	$(CXX) $(CXXFLAGS) -c studentLib.cpp

clean:
	rm -f *.o $(TARGET)
